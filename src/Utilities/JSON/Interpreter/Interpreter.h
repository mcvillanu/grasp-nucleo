#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <ArduinoJson.h>
#include <Utilities/Constants.h>
#include <Utilities/JSON/Object/Object.h>
#include <Utilities/JSON/Array/Array.h>



class Interpreter {
    private:
        template<class T> class Serializer {
            public:
                Serializer();
                Serializer(Serializer const & other);
                ~Serializer();

                void       operator=  (Serializer const & other);
                bool const operator== (Serializer const & other) const;
                bool const operator!= (Serializer const & other) const;

                String const * const serialize(T const * const & json);
        };
        template<class T> class Deserializer {
            private:
                int size;
                DeserializationError error;
                int const fix_error();

            public:
                Deserializer  ();
                Deserializer  (Deserializer const & other);
                ~Deserializer ();

                void       operator=  (Deserializer const & other);
                bool const operator== (Deserializer const & other) const;
                bool const operator!= (Deserializer const & other) const;

                T * const deserialize(String const * const & str);

                int const getSize() const;
                DeserializationError const getError() const;
        };

    public:
        Interpreter();
        Interpreter(Interpreter const & other);
        ~Interpreter();

        void operator=(Interpreter const & other);
        bool const operator==(Interpreter const & other) const;
        bool const operator!=(Interpreter const & other) const;

        template<class T> static T * const deserialize(String const * const & str);
        template<class T> static String const * const serialize(T const * const & json);
};





template<class T> Interpreter::Serializer<T>::Serializer() { return; }
template<class T> Interpreter::Serializer<T>::Serializer(Serializer<T> const & other) { return; }
template<class T> Interpreter::Serializer<T>::~Serializer() { return; }
template<class T> void Interpreter::Serializer<T>::operator=(Serializer const & other) { return; }
template<class T> bool const Interpreter::Serializer<T>::operator==(Serializer const & other) const { return true; }
template<class T> bool const Interpreter::Serializer<T>::operator!=(Serializer const & other) const { return !this->operator==(other); }
template<class T> String const * const Interpreter::Serializer<T>::serialize(T const * const & json) { return nullptr; }





template<class T> Interpreter::Deserializer<T>::Deserializer() : size(UTILITIES::JSON::META::SIZE), error(DeserializationError::Ok) { return; }
template<class T> Interpreter::Deserializer<T>::Deserializer(Deserializer<T> const & other) : size(other.getSize()), error(other.getError()) { return; }
template<class T> Interpreter::Deserializer<T>::~Deserializer() { return; }
template<class T> int const Interpreter::Deserializer<T>::fix_error() {
    // while (this->error) {
    //     switch (this->error) {
    //         case DeserializationError::Ok              : return UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::RESOLVED;
    //         case DeserializationError::IncompleteInput : return UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::UNRESOLVABLE;
    //         case DeserializationError::InvalidInput    : return UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::UNRESOLVABLE;
    //         case DeserializationError::NoMemory        : this->size *= 2; return UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::RESOLVABLE;
    //         case DeserializationError::NotSupported    : return UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::UNRESOLVABLE;
    //         case DeserializationError::TooDeep         : return UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::UNRESOLVABLE;
    //     }
    // }

    // this->error = DeserializationError::Ok;
    // return true;

    // switch (this->error) {
    //     case DeserializationError::Ok              : return UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::RESOLVED;
    //     case DeserializationError::IncompleteInput : return UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::UNRESOLVABLE;
    //     case DeserializationError::InvalidInput    : return UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::UNRESOLVABLE;
    //     case DeserializationError::NoMemory        : this->size *= 2; return UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::RESOLVABLE;
    //     case DeserializationError::NotSupported    : return UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::UNRESOLVABLE;
    //     case DeserializationError::TooDeep         : return UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::UNRESOLVABLE;
    //     default                                    : return UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::UNRESOLVABLE;
    // }

    if      (this->error == DeserializationError::Ok)                return UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::RESOLVED;
    else if (this->error == DeserializationError::IncompleteInput)   return UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::UNRESOLVABLE;
    else if (this->error == DeserializationError::InvalidInput)      return UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::UNRESOLVABLE;
    else if (this->error == DeserializationError::NoMemory) {
        this->size *= 2;
        return UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::RESOLVABLE;
    } else if (this->error == DeserializationError::NotSupported)    return UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::UNRESOLVABLE;
    else if (this->error == DeserializationError::TooDeep)           return UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::UNRESOLVABLE;
    else                                                             return UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::UNRESOLVABLE;
}
template<class T> void Interpreter::Deserializer<T>::operator=(Deserializer const & other) {
    this->size = other.getSize();
    return;
}
template<class T> bool const Interpreter::Deserializer<T>::operator==(Deserializer const & other) const { return (this->size == other.getSize()); }
template<class T> bool const Interpreter::Deserializer<T>::operator!=(Deserializer const & other) const { return !this->operator==(other); }
template<class T> T * const Interpreter::Deserializer<T>::deserialize(String const * const & str) { return nullptr; }
template<> Object * const Interpreter::Deserializer<Object>::deserialize(String const * const & str) {
    DynamicJsonDocument * document = new DynamicJsonDocument(this->size);
    this->error = deserializeJson(*document,*str);
    return new Object(document, new JsonObject(document->as<JsonObject>()));
}
template<> Array * const Interpreter::Deserializer<Array>::deserialize(String const * const & str) {
    // DynamicJsonDocument * document = nullptr;
    // do {
    //     document = new DynamicJsonDocument(this->size);
    //     this->error = deserializeJson(*document,*str);
    // } while (this->fix_error() == UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::RESOLVABLE);
    // return (document) ? (new Array(document, new JsonArray(document->as<JsonArray>()))) : nullptr;

    while (true) {
        DynamicJsonDocument * document = new DynamicJsonDocument(this->size);
        this->error = deserializeJson(*document, *str);

        int err = this->fix_error();
        
        if (err == UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::RESOLVED) return new Array(document, new JsonArray(document->as<JsonArray>()));
        else if (err == UTILITIES::JSON::INTERPRETER::DESERIALIZER::RESOLVE_TYPES::RESOLVABLE) delete document;
        else return nullptr;
    }
}
template<class T> int const Interpreter::Deserializer<T>::getSize() const { return this->size; }
template<class T> DeserializationError const Interpreter::Deserializer<T>::getError() const { return this->error; }





Interpreter::Interpreter() { return; }
Interpreter::Interpreter(Interpreter const & other) { return; }
Interpreter::~Interpreter() { return; }
void Interpreter::operator=(Interpreter const & other) { return; }
bool const Interpreter::operator==(Interpreter const & other) const { return true; }
bool const Interpreter::operator!=(Interpreter const & other) const { return !this->operator==(other); }
template<class T> T * const Interpreter::deserialize(String const * const & str) {
    Deserializer<T> * const d = new Deserializer<T>();
    T * const ret = d->deserialize(str);
    delete d;
    return ret;
}
template<class T> String const * const Interpreter::serialize(T const * const & json) {
    Serializer<T> s;
    return s.serialize(json);
}

#endif