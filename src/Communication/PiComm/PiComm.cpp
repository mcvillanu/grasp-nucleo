#include <Communication/PiComm/PiComm.h>


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
bool Communication::serialActive = false;
Communication::Communication() {}
bool const Communication::isSerialActive() {
	return Communication::serialActive;
}
void Communication::setup() {
	if (Communication::serialActive) return;
	Communication::serialActive = true;
	Serial.begin(COMMUNICATION::PICOMM::META::BAUDRATE);
    Serial.flush();
}
rapidjson::Document * const Communication::createNewJSON() {
	rapidjson::Document * const json = new rapidjson::Document();
	json->SetObject();
	return json;
}
void Communication::addString(rapidjson::Document * const & json, std::string const & stdstr_key, std::string const & stdstr_val) {
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
void Communication::addBool(rapidjson::Document * const & json, std::string const & stdstr_key, bool const & bool_val) {
	char * const char_key = Utils::stdStrToChar(stdstr_key);

	if ((!json) || (json->HasMember(char_key))) return;

	rapidjson::Document::AllocatorType & allocator = json->GetAllocator();

	rapidjson::Value rval_key;
	rapidjson::Value rval_val;
	rval_key.SetString(char_key,allocator);
	rval_val.SetBool(bool_val);

	json->AddMember(rval_key,rval_val,allocator);  
}
void Communication::addInt(rapidjson::Document * const & json, std::string const & stdstr_key, int const & int_val) {
	char * const char_key = Utils::stdStrToChar(stdstr_key);

	if ((!json) || (json->HasMember(char_key))) return;

	rapidjson::Document::AllocatorType & allocator = json->GetAllocator();

	rapidjson::Value rval_key;
	rapidjson::Value rval_val;
	rval_key.SetString(char_key,allocator);
	rval_val.SetInt(int_val);

	json->AddMember(rval_key,rval_val,allocator);  
}
void Communication::addDouble(rapidjson::Document * const & json, std::string const & stdstr_key, double const & double_val) {
	char * const char_key = Utils::stdStrToChar(stdstr_key);

	if ((!json) || (json->HasMember(char_key))) return;

	rapidjson::Document::AllocatorType & allocator = json->GetAllocator();

	rapidjson::Value rval_key;
	rapidjson::Value rval_val;
	rval_key.SetString(char_key,allocator);
	rval_val.SetDouble(double_val);

	json->AddMember(rval_key,rval_val,allocator);  
}
void Communication::removeKeyPair(rapidjson::Document * const & json, std::string const & stdstr_key) {
	char * const char_key = Utils::stdStrToChar(stdstr_key);

	if (!(json && json->HasMember(char_key))) return;

	json->RemoveMember(char_key);
}
void Communication::replaceWithString(rapidjson::Document * const & json, std::string const & stdstr_key, std::string const & stdstr_val) {
	char const * const char_key = Utils::stdStrToChar(stdstr_key);
	if (!(json && json->HasMember(char_key))) return;

	Communication::removeKeyPair(json,stdstr_key);
	Communication::addString(json,stdstr_key,stdstr_val);
}
void Communication::replaceWithBool(rapidjson::Document * const & json, std::string const & stdstr_key, bool const & bool_val) {
	char const * const char_key = Utils::stdStrToChar(stdstr_key);
	if (!(json && json->HasMember(char_key))) return;

	Communication::removeKeyPair(json,stdstr_key);
	Communication::addBool(json,stdstr_key,bool_val);
}
void Communication::replaceWithInt(rapidjson::Document * const & json, std::string const & stdstr_key, int const & int_val) {
	char const * const char_key = Utils::stdStrToChar(stdstr_key);
	if (!(json && json->HasMember(char_key))) return;

	Communication::removeKeyPair(json,stdstr_key);
	Communication::addInt(json,stdstr_key,int_val);
}
void Communication::replaceWithDouble(rapidjson::Document * const & json, std::string const & stdstr_key, double const & double_val) {
	char const * const char_key = Utils::stdStrToChar(stdstr_key);
	if (!(json && json->HasMember(char_key))) return;

	Communication::removeKeyPair(json,stdstr_key);
	Communication::addDouble(json,stdstr_key,double_val);
}
std::string * const Communication::stringifyDocumentToJSON(rapidjson::Document * const & json) {
	rapidjson::StringBuffer s;
	rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(s);
	json->Accept(writer);
	return new std::string(s.GetString());
}
std::string const Communication::readRawMessage() {
    char const * const serialMsg = Serial.readStringUntil(*(COMMUNICATION::PICOMM::META::END_TAG)).c_str();
    return std::string(serialMsg);
}
rapidjson::Document * const Communication::parseMessageIntoDocument(std::string const & stdstr_msg) {
    char const * const char_msg = Utils::stdStrToChar(stdstr_msg);
    rapidjson::Document * doc = new rapidjson::Document();
    return &(doc->Parse(char_msg));
}
int const Communication::getType(rapidjson::Document const * const & json, std::string const & stdstr_key) {
	char const * const char_key = Utils::stdStrToChar(stdstr_key);
	if (json && json->HasMember(char_key)) {
		if      ((*json)[char_key].IsString()) return COMMUNICATION::PICOMM::JSON_TYPES::STR;
		else if ((*json)[char_key].IsBool()  ) return COMMUNICATION::PICOMM::JSON_TYPES::BLN;
		else if ((*json)[char_key].IsInt()   ) return COMMUNICATION::PICOMM::JSON_TYPES::INT;
		else if ((*json)[char_key].IsDouble()) return COMMUNICATION::PICOMM::JSON_TYPES::DBL;
		else if ((*json)[char_key].IsArray() ) return COMMUNICATION::PICOMM::JSON_TYPES::ARR;
		else return COMMUNICATION::PICOMM::JSON_TYPES::DNE;
	}
	return COMMUNICATION::PICOMM::JSON_TYPES::DNE;
}
void * const Communication::readValueFromMessage(rapidjson::Document const * const & json, std::string const & stdstr_key) {
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
std::string * const Communication::readStringFromMessage(rapidjson::Document const * const & json, std::string const & stdstr_key) {
	char const * const char_key = Utils::stdStrToChar(stdstr_key);
	if (!(json && json->HasMember(char_key) && (*json)[char_key].IsString())) return nullptr;
	return new std::string((*json)[char_key].GetString());
}
bool * const Communication::readBoolFromMessage(rapidjson::Document const * const & json, std::string const & stdstr_key) {
	char const * const char_key = Utils::stdStrToChar(stdstr_key);
	if (!(json && json->HasMember(char_key) && (*json)[char_key].IsBool())) return nullptr;
	return new bool((*json)[char_key].GetBool());
}
int * const Communication::readIntFromMessage(rapidjson::Document const * const & json, std::string const & stdstr_key) {
	char const * const char_key = Utils::stdStrToChar(stdstr_key);
	if (!(json && json->HasMember(char_key) && (*json)[char_key].IsInt())) return nullptr;
	return new int((*json)[char_key].GetInt());
}
double * const Communication::readDoubleFromMessage(rapidjson::Document const * const & json, std::string const & stdstr_key) {
	char const * const char_key = Utils::stdStrToChar(stdstr_key);
	if (!(json && json->HasMember(char_key) && (*json)[char_key].IsDouble())) return nullptr;
	return new double((*json)[char_key].GetDouble());
}
void Communication::writeRawMessage(std::string const stdstr_msg) {
	char const * const char_msg = Utils::stdStrToChar(stdstr_msg);
	Serial.write(char_msg);
}