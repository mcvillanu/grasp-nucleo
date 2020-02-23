#include <Communication/PiComm/PiComm.h>

bool Pi::serialActive = false;
Pi::Pi() {}
void Pi::setup() {
	if (Pi::serialActive) return;
	Pi::serialActive = true;
	Serial.begin(COMMUNICATION::PICOMM::META::BAUDRATE);
    Serial.flush();
}
void Pi::destroy() {
	if (!Pi::serialActive) return;
	Pi::serialActive = false;
	Serial.flush();
	Serial.end();
}
String const Pi::read() {
	String newstring;
	// try {
		newstring = Serial.readStringUntil(*COMMUNICATION::PICOMM::META::ENDTAG);
	// }
	// catch (std::exception const& e) {
	// 	return "false";
	// }
	return newstring;
}
void Pi::write(String const & msg) {
	Serial.println(msg);
	Serial.flush();
}
void Pi::refresh() {
	Serial.flush();
}
void Pi::reset() {
	Pi::refresh();
	Pi::destroy();
	Pi::setup();
}
bool const Pi::isSerialActive() {
	return Pi::serialActive;
}