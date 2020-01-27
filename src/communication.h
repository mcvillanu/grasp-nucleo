#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <stdlib.h>
#include <document.h>
#include <Arduino.h>
#include <Utils.h>
#include <constants.h>

using namespace std;
using namespace rapidjson;
using namespace Utils;
using namespace COMMUNICATION;

enum MSG {
    SAFETY_OFF  = -1,
    HANDSHAKE   = 0,
    OK          = 1,
    STOP        = 2,
    GRIP_HAMMER = 3,
    GRIP_PINCH  = 4,
    GRIP_BALL   = 5,
    GRIP_C      = 6,
    GRIP_FLAT   = 7
};

class Communication {
    private:
        int order;
        int param;
        int param_index = 0;

    public:
        Communication();
        void setup();
        void read_message();
        void handshake();
        void send_confirmation();
        int get_order();
        int get_param();

        std::string const readRawMessage() const;
        Document * const readMessage() const;


        void * const getValueFromMessage(Document * const json, std::string stdstr_key) const;
};

#endif
