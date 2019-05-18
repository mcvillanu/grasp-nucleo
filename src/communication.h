#ifndef COMMUNICATION_H
#define COMMUNICATION_H

enum Order
{
    GRIP_HAMMER = 0,
    GRIP_PINCH = 1,
    GRIP_BALL = 2,
    GRIP_C = 3,
    GRIP_FLAT = 4,
    STOP = 5

};

class Communication
{
    public:
        Communication(int BAUDRATE);
        int message[];
        void read_message(int message[]);

    private:
        void wait_for_handshake();
        void send_confirmation();
};

#endif