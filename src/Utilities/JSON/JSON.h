#ifndef JSON_H
#define JSON_H

#include <ArduinoJson.h>
#include <Utilities/Constants.h>

class JSON {
    private:
        int size;
        DynamicJsonDocument * json;
        DeserializationError error;

        bool const fix_error();

    public:
        JSON();
        JSON(JSON const & other);
        ~JSON();

        void       operator =  (JSON const & other);
        bool const operator == (JSON const & other) const;
        bool const operator != (JSON const & other) const;

        bool           const start  (String const * const & str);
        String const * const finish ();

        bool const containsKey(String const & key) const;

        int                         const getValueType (String const & key)          const;
        template<class T> T const * const getValue     (String const & key)          const;
        template<class T> bool      const setValue     (String const & key, T const & val);
        template<class T> bool      const replaceValue (String const & key, T const & val);

        int                  const getSize  () const;
        DeserializationError const getError () const;
};

#endif