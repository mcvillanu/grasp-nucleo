#ifndef PICOMM_H
#define PICOMM_H

#include <stdlib.h>
#include <document.h>
#include <Arduino.h>
#include <Utilities/Accessories/Accessories.h>
#include <Utilities/Constants.h>
#include <stringbuffer.h>
#include <prettywriter.h>



class Communication {
    private:
        static bool serialActive;
    // int order;
    // int param;
    // int param_index = 0;
    // void read_message();
    // void handshake();
    // void send_confirmation();
    // int get_order();
    // int get_param();
    
    public:
        Communication();

        static bool const isSerialActive();

        static void setup();

        static rapidjson::Document * const createNewJSON();
        static std::string * const stringifyDocumentToJSON(rapidjson::Document * const & json);
        static void addString (rapidjson::Document * const & json, std::string const & stdstr_key, std::string const & stdstr_val );
        static void addBool   (rapidjson::Document * const & json, std::string const & stdstr_key, bool        const & bool_val   );
        static void addInt    (rapidjson::Document * const & json, std::string const & stdstr_key, int         const & int_val    );
        static void addDouble (rapidjson::Document * const & json, std::string const & stdstr_key, double      const & double_val );

        static void removeKeyPair (rapidjson::Document * const & json, std::string const & stdstr_key);

        static void replaceWithString (rapidjson::Document * const & json, std::string const & stdstr_key, std::string const & stdstr_val);
        static void replaceWithBool   (rapidjson::Document * const & json, std::string const & stdstr_key, bool const & bool_val);
        static void replaceWithInt    (rapidjson::Document * const & json, std::string const & stdstr_key, int const & int_val);
        static void replaceWithDouble (rapidjson::Document * const & json, std::string const & stdstr_key, double const & double_val);

        static int const getType(rapidjson::Document const * const & json, std::string const & stdstr_key);

        static std::string const readRawMessage();
        static rapidjson::Document * const parseMessageIntoDocument(std::string const & stdstr_msg);

        static void        * const readValueFromMessage  (rapidjson::Document const * const & json, std::string const & stdstr_key);
        static std::string * const readStringFromMessage (rapidjson::Document const * const & json, std::string const & stdstr_key);
        static bool        * const readBoolFromMessage   (rapidjson::Document const * const & json, std::string const & stdstr_key);
        static int         * const readIntFromMessage    (rapidjson::Document const * const & json, std::string const & stdstr_key);
        static double      * const readDoubleFromMessage (rapidjson::Document const * const & json, std::string const & stdstr_key);

        static void writeRawMessage(std::string const stdstr_msg);
};

#endif