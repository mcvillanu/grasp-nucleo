#include <Utilities/JSON/JSON.h>


JSON::JSON() : str(nullptr), bytes(0), json(nullptr) {}
JSON::JSON(char const * const str, int const & bytes) : str(str), bytes(bytes), json(new DynamicJsonDocument(bytes)) {}
bool const JSON::setup() const {
    return deserializeJson(*(this->json),this->str);
}