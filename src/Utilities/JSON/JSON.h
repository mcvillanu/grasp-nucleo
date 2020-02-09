#ifndef JSON_H
#define JSON_H

#include <ArduinoJson.h>

class JSON {
    private:
        char const * str;
        int bytes;
        DynamicJsonDocument * json;

    public:
        JSON();
        JSON(char const * const str, int const & bytes);

        bool const setup() const;
};

#endif