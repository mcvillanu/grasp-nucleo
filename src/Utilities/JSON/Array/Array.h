#ifndef ARRAY_H
#define ARRAY_H

#include <ArduinoJson.h>
#include <Utilities/JSON/Base/Base.h>

class Array : Base<Array,JsonArray> {
    public:
        Array();
        Array(DynamicJsonDocument * const & document, JsonArray * const & array);
        Array(Array const & other);
        ~Array();

        void operator=(Array const & other);
        bool const operator==(Array const & other) const;
        bool const operator!=(Array const & other) const;
};

Array::Array() : Base<Array,JsonArray>() { return; }
Array::Array(DynamicJsonDocument * const & document, JsonArray * const & jsonArray) : Base<Array,JsonArray>(document, jsonArray) { return; }
Array::Array(Array const & other) : Base<Array,JsonArray>(other.getDocument(), other.getSelf()) { return; }
Array::~Array() { return; }
void Array::operator=(Array const & other) { return; }
bool const Array::operator==(Array const & other) const { return true; }
bool const Array::operator!=(Array const & other) const { return this->operator==(other); }

#endif