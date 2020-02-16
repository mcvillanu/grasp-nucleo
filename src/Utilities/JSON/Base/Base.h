#ifndef BASE_H
#define BASE_H

#include <ArduinoJson.h>

// template<class T> class Base {
//     private:
//         T * self;

//     public:
//         Base();
//         Base(T const * const & self);
//         Base(Base const & other);
//         ~Base();

//         void operator=(Base<T> const & other);
//         bool const operator==(Base<T> const & other) const;
//         bool const operator!=(Base<T> const & other) const;

//         void operator=(T const & other);
//         virtual bool const operator==(T const & other) const = 0;
//         virtual bool const operator!=(T const & other) const = 0;

//         T * const getSelf() const;
//         bool const setSelf(T * const & self);
// };


// template<class X, class T> class Base;

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
    this->self = nullptr;
    return;
}
template<class X, class T> T * const Base<X,T>::getSelf() const { return this->self; }
template<class X, class T> void Base<X,T>::setSelf(T * const & self) {
    this->self = self;
    return;
}

#endif