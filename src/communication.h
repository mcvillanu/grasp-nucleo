#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <stdlib.h>
#include <document.h>

using namespace std;
using namespace rapidjson;

enum MSG {
    SAFETY_OFF = -1,
    HANDSHAKE = 0,
    OK = 1,
    STOP = 2,
    GRIP_HAMMER = 3,
    GRIP_PINCH = 4,
    GRIP_BALL = 5,
    GRIP_C = 6,
    GRIP_FLAT = 7
};

class Communication {
    private:
        int order;
        int param;
        int param_index = 0;
        int BAUDRATE;
        char const * const END_TAG = "\n";

    public:
        Communication(int BAUDRATE);
        void setup();
        void read_message();
        void handshake();
        void send_confirmation();
        int get_order();
        int get_param();

        String readRawMessage() const;
        Document * const readMessage() const;

        String * const getStringFromMessage (Document * const json, String key) const;
        bool   * const getBoolFromMessage   (Document * const json, String key) const;
        int    * const getIntFromMessage    (Document * const json, String key) const;
        double * const getDoubleFromMessage (Document * const json, String key) const;
        void   * const getArrayFromMessage  (Document * const json, String key) const;
};

#endif
