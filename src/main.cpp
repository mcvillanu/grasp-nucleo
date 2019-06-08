#include <Arduino.h>
// #include <Servo.h>
// #include <motor.h>
#include <communication.h>
#include <constants.h>

// Motor motor(PINS::THUMB_PWM);
Communication comms(9600);
// Servo servo;
void setup()
{
    // Serial.begin(9600);
    // motor.setup();
    comms.setup();
    // servo.attach(PINS::THUMB_PWM);
}

void loop()
{
    comms.handshake();
    comms.read_message();
    if (comms.get_order() == MSG::GRIP_HAMMER){
        comms.send_confirmation();
    }
    // motor.move_to(0);
    // servo.write(100);
    delay(3000);
    // motor.move_to(50);
    delay(3000);
    // servo.write(60);
    // motor.move_to(100);
    delay(5000);
}