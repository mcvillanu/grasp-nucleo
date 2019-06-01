#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <queue>
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
        queue<int> order;
        queue<int> param;
        int BAUDRATE;
        Communication(int BAUDRATE);
        void read_message();
        void handshake();
        void send_confirmation();
        queue<int> get_order();
        queue<int> get_param();
};

#endif
