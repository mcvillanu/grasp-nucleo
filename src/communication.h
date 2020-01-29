#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <stdlib.h>
#include <document.h>
#include <Arduino.h>
#include <Utils.h>
#include <constants.h>
#include <stringbuffer.h>
#include <prettywriter.h>

using namespace std;
using namespace rapidjson;
using namespace Utils;
using namespace COMMUNICATION;

class Communication {
    private:
        // int order;
        // int param;
        // int param_index = 0;

    public:
        Communication();
        void setup();
        // void read_message();
        // void handshake();
        // void send_confirmation();
        // int get_order();
        // int get_param();



        rapidjson::Document * const createNewJSON() const;
        std::string * const stringifyDocumentToJSON(rapidjson::Document * const & json) const;
        void addString (rapidjson::Document * const & json, std::string const & stdstr_key, std::string const & stdstr_val ) const;
        void addBool   (rapidjson::Document * const & json, std::string const & stdstr_key, bool        const & bool_val   ) const;
        void addInt    (rapidjson::Document * const & json, std::string const & stdstr_key, int         const & int_val    ) const;
        void addDouble (rapidjson::Document * const & json, std::string const & stdstr_key, double      const & double_val ) const;



        int const getType(Document const * const & json, std::string const & stdstr_key) const;



        std::string const readRawMessage() const;
        Document * const parseMessageIntoDocument(std::string const & stdstr_msg) const;



        void        * const readValueFromMessage  (Document const * const & json, std::string const & stdstr_key) const;
        std::string * const readStringFromMessage (Document const * const & json, std::string const & stdstr_key) const;
        bool        * const readBoolFromMessage   (Document const * const & json, std::string const & stdstr_key) const;
        int         * const readIntFromMessage    (Document const * const & json, std::string const & stdstr_key) const;
        double      * const readDoubleFromMessage (Document const * const & json, std::string const & stdstr_key) const;
};

#endif
