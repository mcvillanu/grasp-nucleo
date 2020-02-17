#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <ArduinoJson.h>
#include <Utilities/Constants.h>
#include <Utilities/JSON/Object/Object.h>
#include <Utilities/JSON/Array/Array.h>



// class Interpreter {
//     private:
//         template<class T> class Serializer {
//             public:
//                 Serializer();
//                 Serializer(Serializer const & other);
//                 ~Serializer();

//                 void       operator=  (Serializer const & other);
//                 bool const operator== (Serializer const & other) const;
//                 bool const operator!= (Serializer const & other) const;

//                 String const * const serialize(T const * const & json);
//         };
//         template<class T> class Deserializer {
//             private:
//                 int size;
//                 DeserializationError error;
//                 bool const fix_error();

//             public:
//                 Deserializer  ();
//                 Deserializer  (Deserializer const & other);
//                 ~Deserializer ();

//                 void       operator=  (Deserializer const & other);
//                 bool const operator== (Deserializer const & other) const;
//                 bool const operator!= (Deserializer const & other) const;

//                 T * const deserialize(String const * const & str);

//                 int const getSize() const;
//                 DeserializationError const getError() const;
//         };

//     public:
//         Interpreter();
//         Interpreter(Interpreter const & other);
//         ~Interpreter();

//         void operator=(Interpreter const & other);
//         bool const operator==(Interpreter const & other) const;
//         bool const operator!=(Interpreter const & other) const;

//         template<class T> static T * const deserialize(String const * const & str);
//         template<class T> static String const * const serialize(T const * const & json);
// };





// template<class T> Interpreter::Deserializer<T>::Deserializer() : size(UTILITIES::JSON::META::SIZE), error(DeserializationError::Ok) { return; }
// template<class T> Interpreter::Deserializer<T>::Deserializer(Deserializer<T> const & other) : size(other.getSize()), error(other.getError()) { return; }
// template<class T> Interpreter::Deserializer<T>::~Deserializer() { return; }
// template<class T> bool const Interpreter::Deserializer<T>::fix_error() {
//     this->error = DeserializationError::Ok;
//     return true;
// }
// template<class T> void Interpreter::Deserializer<T>::operator=(Deserializer const & other) {
//     this->size = other.getSize();
//     return;
// }
// template<class T> bool const Interpreter::Deserializer<T>::operator==(Deserializer const & other) const { return (this->size == other.getSize()); }
// template<class T> bool const Interpreter::Deserializer<T>::operator!=(Deserializer const & other) const { return !this->operator==(other); }
// template<class T> T * const Interpreter::Deserializer<T>::deserialize(String const * const & str) { return nullptr; }
// template<> Object * const Interpreter::Deserializer<Object>::deserialize(String const * const & str) {
//     DynamicJsonDocument document(this->size);
//     this->error = deserializeJson(document,*str);
//     if (this->fix_error()) return new Object(new JsonObject(document.as<JsonObject>()));
//     return nullptr;
// }
// template<> Array * const Interpreter::Deserializer<Array>::deserialize(String const * const & str) {
//     DynamicJsonDocument document(this->size);
//     this->error = deserializeJson(document,*str);
//     if (this->fix_error()) return new Array(new JsonArray(document.as<JsonArray>()));
//     return nullptr;
// }
// template<class T> int const Interpreter::Deserializer<T>::getSize() const { return this->size; }
// template<class T> DeserializationError const Interpreter::Deserializer<T>::getError() const { return this->error; }





// template<class T> Interpreter::Serializer<T>::Serializer() { return; }
// template<class T> Interpreter::Serializer<T>::Serializer(Serializer<T> const & other) { return; }
// template<class T> Interpreter::Serializer<T>::~Serializer() { return; }
// template<class T> void Interpreter::Serializer<T>::operator=(Serializer const & other) { return; }
// template<class T> bool const Interpreter::Serializer<T>::operator==(Serializer const & other) const { return true; }
// template<class T> bool const Interpreter::Serializer<T>::operator!=(Serializer const & other) const { return !this->operator==(other); }
// template<class T> String const * const Interpreter::Serializer<T>::serialize(T const * const & json) {
//     return nullptr;
// }





// Interpreter::Interpreter() { return; }
// Interpreter::Interpreter(Interpreter const & other) { return; }
// Interpreter::~Interpreter() { return; }
// void Interpreter::operator=(Interpreter const & other) { return; }
// bool const Interpreter::operator==(Interpreter const & other) const { return true; }
// bool const Interpreter::operator!=(Interpreter const & other) const { return !this->operator==(other); }
// template<class T> T * const Interpreter::deserialize(String const * const & str) {
//     Deserializer<T> d;
//     return d.deserialize(str);
// }
// template<class T> String const * const Interpreter::serialize(T const * const & json) {
//     Serializer<T> s;
//     return s.serialize(json);
// }

class Interpreter {
    private:
        template<class T> class Serializer {
            public:
                Serializer();
                String const * const serialize(T const * const & json);
        };
        template<class T> class Deserializer {
            private:
                int size;
                DeserializationError error;
                bool const fix_error();

            public:
                Deserializer  ();

                JsonObject * const deserialize(String const * const & str);

                int const getSize() const;
                DeserializationError const getError() const;
        };

    public:
        Interpreter();

        template<class T> static JsonObject * const deserialize(String const * const & str);
        template<class T> static String const * const serialize(T const * const & json);
};





template<class T> Interpreter::Deserializer<T>::Deserializer() : size(UTILITIES::JSON::META::SIZE), error(DeserializationError::Ok) { return; }
template<class T> bool const Interpreter::Deserializer<T>::fix_error() {
    this->error = DeserializationError::Ok;
    return true;
}
template<class T> JsonObject * const Interpreter::Deserializer<T>::deserialize(String const * const & str) { return nullptr; }
template<> JsonObject * const Interpreter::Deserializer<Object>::deserialize(String const * const & str) {
    Pi::write(String(this->size));
    DynamicJsonDocument * document = new DynamicJsonDocument(200);
    this->error = deserializeJson(*document,*str);
    // if (this->fix_error()) return new Object(new JsonObject(document.as<JsonObject>()));
    // return new JsonObject(document.as<JsonObject>());
    return new JsonObject(document->as<JsonObject>());
    // return nullptr;
}
template<> JsonObject * const Interpreter::Deserializer<Array>::deserialize(String const * const & str) {
    DynamicJsonDocument document(this->size);
    this->error = deserializeJson(document,*str);
    // if (this->fix_error()) return new Array(new JsonArray(document.as<JsonArray>()));
    return new JsonObject(document.as<JsonObject>());
    // return nullptr;
}
template<class T> int const Interpreter::Deserializer<T>::getSize() const { return this->size; }
template<class T> DeserializationError const Interpreter::Deserializer<T>::getError() const { return this->error; }





template<class T> Interpreter::Serializer<T>::Serializer() { return; }
template<class T> String const * const Interpreter::Serializer<T>::serialize(T const * const & json) { return nullptr; }





Interpreter::Interpreter() { return; }
template<class T> JsonObject * const Interpreter::deserialize(String const * const & str) {
    Deserializer<T> * const d = new Deserializer<T>();
    return d->deserialize(str);
}
template<class T> String const * const Interpreter::serialize(T const * const & json) {
    Serializer<T> s;
    return s.serialize(json);
}

#endif