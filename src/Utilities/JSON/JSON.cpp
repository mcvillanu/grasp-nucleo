#include <Utilities/JSON/JSON.h>


JSON::JSON() : size(UTILITIES::JSON::META::SIZE), json(new DynamicJsonDocument(size)), error(DeserializationError::Ok) { return; }
JSON::JSON(JSON const & other) : size(other.size), json(new DynamicJsonDocument(*(other.json))), error(other.error) { return; }
JSON::~JSON() {
    delete this->json;
    this->json = nullptr;
    return;
}




// JSON::JSON(String const * const & str) : str(str), bytes(UTILITIES::JSON::META::SIZE), json(new DynamicJsonDocument(bytes)), error(DeserializationError::Ok) {
//     DeserializationError error = deserializeJson(*(this->json),*(this->str));
//     this->error = error;
//     if (error) this->fix_error();
// }



bool const JSON::fix_error() {
    if (!this->error) return true;
    else if (this->error == DeserializationError::NoMemory) {

    }
    return false;
}

void JSON::operator=(JSON const & other) {
    this->size = other.size;
    delete this->json;
    this->json = new DynamicJsonDocument(*(other.json));
    this->error = other.error;
    return;
}
bool const JSON::operator==(JSON const & other) const {
    return ((this->size == other.size) && ((this->json == other.json) || (*(this->json) == *(other.json))) && (this->error == other.error));
}
bool const JSON::operator!=(JSON const & other) const {
    return !this->operator==(other);
}
bool const JSON::start(String const * const & str) {
    if (!str) return false;

    this->error = deserializeJson(*(this->json),*str);
    return this->fix_error();
}
String const * const JSON::finish() {
    if (!this->fix_error()) return nullptr;

    String * const msg = new String();
    serializeJson(*(this->json),*msg);
    return (String const * const) msg;
}
template<class T> T const * const JSON::getValue(String const & key) const {
    if (!(this->fix_error() && this->json && this->json->containsKey(key))) return nullptr;

    return (*(this->json))[key].as<T>();
}
int const JSON::getSize() const {
    return this->size;
}
DeserializationError const JSON::getError() const {
    return this->error;
}