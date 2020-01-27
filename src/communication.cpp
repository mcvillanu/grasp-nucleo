#include <communication.h>




Communication::Communication() {}

/*  Setup:
        Begins the serial communication channel and flushes the serial buffer before anything is sent/received.
*/
void Communication::setup() {
    // Serial.begin(this->BAUDRATE);
	Serial.begin(COMMUNICATION::BAUDRATE);
    Serial.flush();
}

void Communication::handshake() {
    while (Serial.available() < 2) {
        // Serial.write(4);
            /*do nothing*/
    }
    // Serial.write(4);
    this->read_message();
    // Check that the handshake has been successfully performed
    if ((this->order == 0x00) && (this->param == 0xFF)) Serial.write(HANDSHAKE);
}

// void Communication::read_message() {
//     // buffer has to be at least two bytes long
//     while (Serial.available() < 2) { /*do nothing*/ }

//     this->order = Serial.read();
//     this->param = Serial.read();
// }

int Communication::get_order() {
    return this->order;
}

int Communication::get_param() {
    return this->param;
}

void Communication::send_confirmation() {
    Serial.write(MSG::OK);
}





std::string const Communication::readRawMessage() const {
    char const * const serialMsg = Serial.readStringUntil(*(this->END_TAG)).c_str();
    return std::string(serialMsg);
}

Document * const Communication::readMessage() const {
    char const * const msg = Utils::stdStrToChar(this->readRawMessage());
    Document * doc = new Document();
    return &(doc->Parse(msg));
}


void * const Communication::getValueFromMessage(Document * const json, std::string stdstr_key) const {
	char const * const char_key = Utils::stdStrToChar(stdstr_key);
	if (!(json && json->HasMember(char_key))) return nullptr;
	else {
		if      ((*json)[char_key].IsString() ) return (void * const) new std::string((*json)[char_key].GetString());
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