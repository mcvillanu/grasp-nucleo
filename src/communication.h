#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <stdlib.h>
#include <document.h>
#include <Arduino.h>
#include <Utils.h>
#include <constants.h>
#include <stringbuffer.h>
#include <prettywriter.h>



/* -------------------- DOCUMENTATION -------------------- */
/* ***NOTE***:
 * There are a few different types of ways chars/strings can be represented in this situation:
 * 		1) A null-terminated array of chars
 * 		2) A std::string
 * 		3) The Arduino Framework's String
 * The RapidJSON library uses 1) and the Arduino Framework uses 3).
 * This can be kind of confusing, so there are "conversion" functions declared in the Utils.h class which will allow you to convert one type into any of the other two.
 * 
 * However, while interfacing with this class, one will notice that std::string is always preferred. This was chosen mainly because std::string is part of the Standard C++ Library.
 * Also, std::string probably contains less overhead than the Arduino Framework's String (emphasis on probably...), and I think it will be easier to use and adapt to.
 */
/* Communication:
 * Empty default constructor. This technically needs to exist...
 */
/* Setup:
 * Initializes the this->BAUDRATE to COMMUNICATION::META::BAUDRATE and then flushes the Serial buffer.
 * This may cause a bug if multiple calls to setup are called (if setup is called in the middle of execution of reading, the Serial buffer can be accidentally cleared before the finishing reading.)
 */
/* Create New JSON:
 * Creates a new JSON Document object.
 * Use this method in order to create an empty JSON that can be populated with key-value pairs.
 */
/* Stringify Document To JSON:
 * Takes a JSON Document and turns it into a (formatted) std::string which is returned to the caller.
 */
/* Add String:
 * Takes in a JSON Document, a key, and a value (the latter two of which are both of type std::string).
 * The passed in key-value pair will be added to the JSON Document if and ONLY IF the key does NOT already exist in it.
 * 
 * Note:
 * If the key already exists, the function will return WITHOUT DOING ANYTHING (NO CHANGES TO THE EXISTING JSON DOCUMENT WILL BE MADE). This is a specific design decision just so the previous key will not be overidden.
 * Key resetting can be done through another API which will be implemented soon.
 */
/* Add Bool:
 * Takes in a JSON Document, a key, and a value (where the key is a std::string and the value is a boolean).
 * The passed in key-value pair will be added to the JSON Document if and ONLY IF the key does NOT already exist in it.
 * 
 * Note:
 * If the key already exists, the function will return WITHOUT DOING ANYTHING (NO CHANGES TO THE EXISTING JSON DOCUMENT WILL BE MADE). This is a specific design decision just so the previous key will not be overidden.
 * Key resetting can be done through another API which will be implemented soon.
 */
/* Add Int:
 * Takes in a JSON Document, a key, and a value (where the key is a std::string and the value is an int).
 * The passed in key-value pair will be added to the JSON Document if and ONLY IF the key does NOT already exist in it.
 * 
 * Note:
 * If the key already exists, the function will return WITHOUT DOING ANYTHING (NO CHANGES TO THE EXISTING JSON DOCUMENT WILL BE MADE). This is a specific design decision just so the previous key will not be overidden.
 * Key resetting can be done through another API which will be implemented soon.
 */
/* Add Double:
 * Takes in a JSON Document, a key, and a value (where the key is a std::string and the value is a double).
 * The passed in key-value pair will be added to the JSON Document if and ONLY IF the key does NOT already exist in it.
 * 
 * Note:
 * If the key already exists, the function will return WITHOUT DOING ANYTHING (NO CHANGES TO THE EXISTING JSON DOCUMENT WILL BE MADE). This is a specific design decision just so the previous key will not be overidden.
 * Key resetting can be done through another API which will be implemented soon.
 */
/* Get Type:
 * Takes in a JSON Document and a std::string key to search the Document against.
 * Returns an enumeration based upon the type of the key's value. Look through the JSON_TYPES enum in <constants.h> for all the codes.
 */
/* Read Raw Message:
 * Reads the raw JSON string incoming from the Serial Bridge.
 * Breaks off when the COMMUNICATION::END_TAG ("\n") tag is encountered.
 * Returns a std::string.
 */
/* Parse Message into Document:
 * Reads the raw message from the Serial Bridge and converts that into an array of chars.
 * The array of chars is then passed into a new rapidjson::Document pointer, which then converts that into a JSON document.
 * The JSON document is returned as a pointer ().
 */
/* Read Value from Message:
 * Receives a JSON Document to search through and a std::string which is the key the JSON is searched against.
 * 
 * If the key is found, it is returned as a (void *)! Before using the return value, you will have to cast it to the proper type, which will require you to know/calculate the type beforehand.
 * If the key does not exist in the JSON, a nullptr is returned! Check for a nullptr before using!
 */
/* Read String from Message:
 * Receives a JSON Document to search through and a std::string which is the key the JSON is searched against.
 * 
 * If the key is found and if the value is a std::string, it is returned as a (std::string *)! No casting will have to be done in order to use the return value.
 * If the key does not exist in the JSON OR if the key does exist but its value is not a std::string, a nullptr is returned! Check for a nullptr before using!
 */
/* Read Bool from Message:
 * Receives a JSON Document to search through and a std::string which is the key the JSON is searched against.
 * 
 * If the key is found and if the value is a bool, it is returned as a (bool *)! No casting will have to be done in order to use the return value.
 * If the key does not exist in the JSON OR if the key does exist but its value is not a bool, a nullptr is returned! Check for a nullptr before using!
 */
/* Read Int from Message:
 * Receives a JSON Document to search through and a std::string which is the key the JSON is searched against.
 * 
 * If the key is found and if the value is an int, it is returned as a (int *)! No casting will have to be done in order to use the return value.
 * If the key does not exist in the JSON OR if the key does exist but its value is not an int, a nullptr is returned! Check for a nullptr before using!
 */
/* Read double from Message:
 * Receives a JSON Document to search through and a std::string which is the key the JSON is searched against.
 * 
 * If the key is found and if the value is a double, it is returned as a (double *)! No casting will have to be done in order to use the return value.
 * If the key does not exist in the JSON OR if the key does exist but its value is not a double, a nullptr is returned! Check for a nullptr before using!
 */
/* Write Raw Message:
 * Takes in a std::string and writes it to the Serial bridge.
 */


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

/* TODO:
 * 1)   Implement object functionality (i.e. adding objects to and reading objects from JSONs; as of right now, only std::strings, bools, ints, and doubles can be added to and read from JSONs).
 * 2)   Implement array functionality (i.e. adding arrays to and reading arrays from JSONs).
 * 3)   Implement functionality to override values for keys that already exist
 *          I.E., with the current implementation, if a key-value pair is added to a JSON, but the key already exists in the JSON, no updating will occur.
 *          This could pose a problem if a certain key was inputed, but then an event occurred and the value of that pre-existing key needed to be updated, but was unable to because of the lack of overriding.
 *          Either create new specific methods that update the state for existing keys, or change the implementation of addString, addBool, addInt, and addDouble.
 */

#endif