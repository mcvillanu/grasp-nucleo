#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <vector>
using namespace std;

enum MSG
{
    HANDSHAKE = 0,
    OK = 1,
    STOP = 2,
    GRIP_HAMMER = 3,
    GRIP_PINCH = 4,
    GRIP_BALL = 5,
    GRIP_C = 6,
    GRIP_FLAT = 7
};

class Communication
{
    public:
        vector<int> order();
        vector<int> param();
        int BAUDRATE;
        Communication(int BAUDRATE);
        void read_message();
        void handshake();
        void send_confirmation();
        vector<int> get_order();
        vector<int> get_param();
};

#endif