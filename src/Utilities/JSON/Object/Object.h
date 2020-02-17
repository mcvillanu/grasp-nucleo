#ifndef OBJECT_H
#define OBJECT_H

#include <ArduinoJson.h>
#include <Utilities/JSON/Base/Base.h>

class Object : Base<Object, JsonObject> {
    public:
        Object();
        Object(JsonObject * const & object);
        Object(Object const & other);
        ~Object();

        void operator=(Object const & other);
        bool const operator==(Object const & other) const;
        bool const operator!=(Object const & other) const;

        bool const hasKey(String const & key) const;

        template<class T> T * const getValue(String const & key) const;
        template<class T> bool const setValue(String const & key, T * const val);
        template<class T> bool const replaceValue(String const & key, T * const val);

        JsonObject * const getSelf() const;
};

Object::Object() : Base<Object,JsonObject>() { return; }
Object::Object(JsonObject * const & jsonObject) : Base<Object,JsonObject>(jsonObject) { return; }
Object::Object(Object const & other) : Base<Object,JsonObject>(other.getSelf()) { return; }
Object::~Object() { return; }
void Object::operator=(Object const & other) { return; }
bool const Object::operator==(Object const & other) const { return true; }
bool const Object::operator!=(Object const & other) const { return this->operator==(other); }
bool const Object::hasKey(String const & key) const {
    if (this->self) return this->self->containsKey("asd");
    return false;
}
template<class T> T * const Object::getValue(String const & key) const { return ((this->hasKey(key)) ? (new T(this->self->operator[](key.c_str()).as<T>())) : nullptr); }
template<class T> bool const Object::setValue(String const & key, T * const val) {
    if (this->hasKey(key)) return false;
    this->self->operator[](key.c_str()).as<T>() = val;
    return true;
}
template<class T> bool const Object::replaceValue(String const & key, T * const val) {
    if (!this->hasKey(key)) return false;
    this->self->operator[](key.c_str()).as<T>() = val;
    return true;
}
JsonObject * const Object::getSelf() const {
    return this->self;
}

#endif