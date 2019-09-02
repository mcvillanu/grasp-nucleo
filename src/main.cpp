#include <Arduino.h>
// #include <Servo.h>
#include <motor.h>
#include <wrist.h>
#include <communication.h>
#include <constants.h>
#include <emg.h>


Motor motor(PINS::THUMB_PWM);
Motor motor2(PINS::INDEX_PWM);
Wrist wrist(32);
Communication comms(9600);
Emg_signal emg(PINS::EMG_SIG);
// Servo servo;

void setup()
{
    Serial.begin(9600);
    // motor.setup();
    wrist.setup();
    comms.setup();
    // servo.attach(PINS::THUMB_PWM);
    wrist.rotate_by(5*360);
}

void loop()
{
    delayMicroseconds(wrist.poll());
    // // if (comms.get_order() == MSG::GRIP_HAMMER){
    // //     comms.send_confirmation();
    // //     motor.move_to(0);
    // //     motor2.move_to(0);
    // //     // servo.write(100);
    // //     delay(3000);
    // //     motor.move_to(50);
    // //     motor2.move_to(50);
    // //     delay(3000);
    // //     // servo.write(60);
    // //     motor.move_to(100);
    // //     motor2.move_to(100);
    // //     delay(5000);
    // // }
    float voltage = emg.emg_voltage();
    Serial.println(voltage);
    //wrist.rotate_by(180);
    // wrist.rotate_by(-180);
    // delay(3000);

    if (emg.peak_detected(voltage)) {
        Serial.println("Flex that");
        motor.move_to(100);
        delay(2000);
        motor.move_to(0);
        wrist.rotate_by(100);

    }
   // delay(2000);
}