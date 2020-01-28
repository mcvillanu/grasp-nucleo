#include <communication.h>


// void Communication::handshake() {
//     while (Serial.available() < 2) {
//         // Serial.write(4);
//             /*do nothing*/
//     }
//     // Serial.write(4);
//     this->read_message();
//     // Check that the handshake has been successfully performed
//     if ((this->order == 0x00) && (this->param == 0xFF)) Serial.write(HANDSHAKE);
// }

// void Communication::read_message() {
//     // buffer has to be at least two bytes long
//     while (Serial.available() < 2) { /*do nothing*/ }

//     this->order = Serial.read();
//     this->param = Serial.read();
// }

// int Communication::get_order() {
//     return this->order;
// }

// int Communication::get_param() {
//     return this->param;
// }

// void Communication::send_confirmation() {
//     Serial.write(MSG::OK);
// }

/* Note:
 * There are a few different types of ways chars/strings can be represented in this situation:
 * 		1) A null-terminated array of chars
 * 		2) A std::string
 * 		3) The Arduino Framework's String
 * The RapidJSON library uses 1) and the Arduino Framework uses 3).
 * This can be kind of confusing, so there are "conversion" functions declared in the Utils.h class which will allow you to convert one type into any of the other two.
 * 
 * However, while interfacing with this class, one will notice that std::string is always preferred. This was chosen mainly because std::string is part of the Standard C++ Library.
 * Also, std::string probably contains less overhead than the Arduino Framework's String (emphasis on probably...), and I think it will be easier to use and adapt to.
 */




/* Constructor:
 * Instantiates the Communication class.
 */
Communication::Communication() {}
/* Setup:
 * Begins the Serial Bridge with baudrate as defined in the COMMUNICATION enum.
 * Flushes the Serial Buffer before beginning.
 */
void Communication::setup() {
	Serial.begin(COMMUNICATION::BAUDRATE);
    Serial.flush();
}


rapidjson::Document * const Communication::createNewJSON() const {
	rapidjson::Document * const json = new rapidjson::Document();
	rapidjson::Value & value = json->SetObject();
	return json;
}
void Communication::addString(rapidjson::Document * const & json, std::string const & stdstr_key, std::string const & stdstr_val) const {
	char * const char_key = Utils::stdStrToChar(stdstr_key);
	char * const char_val = Utils::stdStrToChar(stdstr_val);

	if ((!json) || (json->HasMember(char_key))) return;

	rapidjson::Document::AllocatorType & allocator = json->GetAllocator();

	rapidjson::Value rval_key;
	rapidjson::Value rval_val;
	rval_key.SetString(char_key,allocator);
	rval_val.SetString(char_val,allocator);

	json->AddMember(rval_key,rval_val,allocator);  
}
void Coomunication::addBool(rapidjson::Document * const & json, std::string const & stdstr_key, bool const & bool_val) const {
	char * const char_key = stdStrToChar(stdstr_key);

	if ((!json) || (json->HasMember(char_key))) return;

	rapidjson::Document::AllocatorType & allocator = json->GetAllocator();

	rapidjson::Value rval_key;
	rapidjson::Value rval_val;
	rval_key.SetString(char_key,allocator);
	rval_val.SetBool(bool_val);

	json->AddMember(rval_key,rval_val,allocator);  
}
void addInt(rapidjson::Document * const json, std::string const & stdstr_key, int const & int_val) {
	char * const char_key = Utils::stdStrToChar(stdstr_key);

	if ((!json) || (json->HasMember(char_key))) return;

	rapidjson::Document::AllocatorType & allocator = json->GetAllocator();

	rapidjson::Value rval_key;
	rapidjson::Value rval_val;
	rval_key.SetString(char_key,allocator);
	rval_val.SetInt(int_val);

	json->AddMember(rval_key,rval_val,allocator);  
}
void addDouble(rapidjson::Document * const json, std::string const & stdstr_key, double const & double_val) {
	char * const char_key = Utils::stdStringToChar(stdstr_key);

	if ((!json) || (json->HasMember(char_key))) return;

	rapidjson::Document::AllocatorType & allocator = json->GetAllocator();

	rapidjson::Value rval_key;
	rapidjson::Value rval_val;
	rval_key.SetString(char_key,allocator);
	rval_val.SetDouble(double_val);

	json->AddMember(rval_key,rval_val,allocator);  
}
std::string * const stringifyDocumentToJSON(rapidjson::Document * const json) {
	StringBuffer s;
	PrettyWriter<StringBuffer> writer(s);
	json->Accept(writer);
	return new std::string(s.GetString());
}



/* Read Raw Message:
 * Reads the raw JSON string incoming from the Serial Bridge.
 * Breaks off when the COMMUNICATION::END_TAG ("\n") tag is encountered.
 * Returns a std::string.
 */
std::string const Communication::readRawMessage() const {
    char const * const serialMsg = Serial.readStringUntil(*(COMMUNICATION::END_TAG)).c_str();
    return std::string(serialMsg);
}
/* Read Message:
 * Reads the raw message from the Serial Bridge and converts that into an array of chars.
 * The array of chars is then passed into a new Document pointer, which then converts that into a JSON Document.
 * The JSON Document is returned as a pointer ().
 */
Document * const Communication::parseMessageIntoDocument(std::string const & stdstr_msg) const {
    char const * const char_msg = Utils::stdStrToChar(stdstr_msg);
    Document * doc = new Document();
    return &(doc->Parse(char_msg));
}
/* Get Type:
 * Takes in a JSON Document and a std::string key to search the Document against.
 * Returns an enumeration based upon the type of the key's value. Look through the JSON_TYPES enum in <constants.h> for all the codes.
 */
int const Communication::getType(Document const * const & json, std::string const & stdstr_key) const {
	char const * const char_key = Utils::stdStrToChar(stdstr_key);
	if (json && json->HasMember(char_key)) {
		if      ((*json)[char_key].IsString()) return JSON_TYPES::STR;
		else if ((*json)[char_key].IsBool()  ) return JSON_TYPES::BLN;
		else if ((*json)[char_key].IsInt()   ) return JSON_TYPES::INT;
		else if ((*json)[char_key].IsDouble()) return JSON_TYPES::DBL;
		else if ((*json)[char_key].IsArray() ) return JSON_TYPES::ARR;
	} else return JSON_TYPES::DNE;
}
/* Read Value from Message:
 * Receives a JSON Document to search through and a std::string which is the key the JSON is searched against.
 * 
 * If the key is found, it is returned as a (void *)! Before using the return value, you will have to cast it to the proper type, which will require you to know/calculate the type beforehand.
 * If the key does not exist in the JSON, a nullptr is returned! Check for a nullptr before using!
 */
void * const Communication::readValueFromMessage(Document const * const & json, std::string const & stdstr_key) const {
	char const * const char_key = Utils::stdStrToChar(stdstr_key);
	if (!(json && json->HasMember(char_key))) return nullptr;
	else {
		if      ((*json)[char_key].IsString() ) return (std::string * const) new std::string((*json)[char_key].GetString());
		else if ((*json)[char_key].IsBool()   ) return (void * const) new        bool((*json)[char_key].GetBool()  );
		else if ((*json)[char_key].IsInt()    ) return (void * const) new         int((*json)[char_key].GetInt()   );
		else if ((*json)[char_key].IsDouble() ) return (void * const) new      double((*json)[char_key].GetDouble());
		// else if ((*json)[char_key].IsArray()  ) {
		// 	rapidjson::GenericArray<false,rapidjson::GenericValue<rapidjson::UTF8<char>,rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>>> * genDoc = &(*json)[char_key].GetArray();
		// 	int size = genDoc->Size();
		// 	void * * const arr = (void * * const) malloc(size * sizeof(void *));
		// 	for (int i=0; i<size; i++) {
		// 		genDoc[i];
		// 	}
		// 	return nullptr;
		// }
		else return nullptr;
	}
}
/* Read String from Message:
 * Receives a JSON Document to search through and a std::string which is the key the JSON is searched against.
 * 
 * If the key is found and if the value is a std::string, it is returned as a (std::string *)! No casting will have to be done in order to use the return value.
 * If the key does not exist in the JSON OR if the key does exist but its value is not a std::string, a nullptr is returned! Check for a nullptr before using!
 */
std::string * const Communication::readStringFromMessage(Document const * const & json, std::string const & stdstr_key) const {
	char const * const char_key = Utils::stdStrToChar(stdstr_key);
	if (!(json && json->HasMember(char_key) && (*json)[char_key].IsString())) return nullptr;
	return new std::string((*json)[char_key].GetString());
}
/* Read Bool from Message:
 * Receives a JSON Document to search through and a std::string which is the key the JSON is searched against.
 * 
 * If the key is found and if the value is a bool, it is returned as a (bool *)! No casting will have to be done in order to use the return value.
 * If the key does not exist in the JSON OR if the key does exist but its value is not a bool, a nullptr is returned! Check for a nullptr before using!
 */
bool * const Communication::readBoolFromMessage(Document const * const & json, std::string const & stdstr_key) const {
	char const * const char_key = Utils::stdStrToChar(stdstr_key);
	if (!(json && json->HasMember(char_key) && (*json)[char_key].IsBool())) return nullptr;
	return new bool((*json)[char_key].GetBool());
}
/* Read Int from Message:
 * Receives a JSON Document to search through and a std::string which is the key the JSON is searched against.
 * 
 * If the key is found and if the value is an int, it is returned as a (int *)! No casting will have to be done in order to use the return value.
 * If the key does not exist in the JSON OR if the key does exist but its value is not an int, a nullptr is returned! Check for a nullptr before using!
 */
int * const Communication::readIntFromMessage(Document const * const & json, std::string const & stdstr_key) const {
	char const * const char_key = Utils::stdStrToChar(stdstr_key);
	if (!(json && json->HasMember(char_key) && (*json)[char_key].IsInt())) return nullptr;
	return new int((*json)[char_key].GetInt());
}
/* Read double from Message:
 * Receives a JSON Document to search through and a std::string which is the key the JSON is searched against.
 * 
 * If the key is found and if the value is a double, it is returned as a (double *)! No casting will have to be done in order to use the return value.
 * If the key does not exist in the JSON OR if the key does exist but its value is not a double, a nullptr is returned! Check for a nullptr before using!
 */
double * const Communication::readDoubleFromMessage(Document const * const & json, std::string const & stdstr_key) const {
	char const * const char_key = Utils::stdStrToChar(stdstr_key);
	if (!(json && json->HasMember(char_key) && (*json)[char_key].IsDouble())) return nullptr;
	return new double((*json)[char_key].GetDouble());
}