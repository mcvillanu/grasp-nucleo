#ifndef BASE_H
#define BASE_H

#include <ArduinoJson.h>



template<class X, class T> class  Base {
    protected:
        DynamicJsonDocument * const document;
        T * self;

    public:
        Base();
        Base(DynamicJsonDocument * const & document, T * const & self);
        virtual ~Base();

        virtual void operator=(X const & other) = 0;
        virtual bool const operator==(X const & other) const = 0;
        virtual bool const operator!=(X const & other) const = 0;

        virtual T * const getSelf() const;
        virtual DynamicJsonDocument * const getDocument() const;

        virtual void setSelf(T * const & self);
};

template<class X, class T> Base<X,T>::Base() : document(new DynamicJsonDocument(UTILITIES::JSON::META::SIZE)), self(nullptr) { return; }
template<class X, class T> Base<X,T>::Base(DynamicJsonDocument * const & document, T * const & self) : document(document), self(self) { return; }
template<class X, class T> Base<X,T>::~Base() {
    delete this->self;
    delete this->document;
    return;
}
template<class X, class T> T * const Base<X,T>::getSelf() const { return this->self; }
template<class X, class T> DynamicJsonDocument * const Base<X,T>::getDocument() const { return this->document; }
template<class X, class T> void Base<X,T>::setSelf(T * const & self) {
    this->self = self;
    return;
}

#endif