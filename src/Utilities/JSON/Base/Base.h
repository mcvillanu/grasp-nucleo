#ifndef BASE_H
#define BASE_H

#include <ArduinoJson.h>



template<class X, class T> class Base {
    protected:
        T * self;

    public:
        Base();
        Base(T * const & self);
        ~Base();

        virtual void operator=(X const & other) = 0;
        virtual bool const operator==(X const & other) const = 0;
        virtual bool const operator!=(X const & other) const = 0;

        T * const getSelf() const;
        void setSelf(T * const & self);
};

template<class X, class T> Base<X,T>::Base() : self(nullptr) { return; }
template<class X, class T> Base<X,T>::Base(T * const & self) : self(self) { return; }
template<class X, class T> Base<X,T>::~Base() {
    this->self->~T();
    this->self = nullptr;
    return;
}
template<class X, class T> T * const Base<X,T>::getSelf() const { return this->self; }
template<class X, class T> void Base<X,T>::setSelf(T * const & self) {
    this->self = self;
    return;
}

#endif