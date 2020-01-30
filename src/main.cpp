#include <Arduino.h>
#include <Servo.h>
#include <motor.h>
#include <wrist.h>
#include <communication.h>
#include <constants.h>
#include <emg.h>
#include <TaskManager.h>
#include <document.h>
#include <allocators.h>

using namespace std;
using namespace rapidjson;


Motor motor(PINS::THUMB_PWM);
Motor motor2(PINS::INDEX_PWM);
Wrist wrist(32);
Communication comms;
Emg_signal emg(PINS::EMG::EMG_SGNL);
TaskManager manager;
bool safetyOff = false;
// Servo servo;

void setup() {
    /* Begin serial communication: */
    Serial.begin(9600);

    /* Set up the motors */
    motor.setup();
    // motor2.setup();
    wrist.setup();
    comms.setup();

    // servo.attach(PINS::THUMB_PWM);
    wrist.rotate_by(5*360);
    pinMode(3, INPUT);
    pinMode(PC12, OUTPUT);
    // Choose which emg pin to read.
    // start with close hand. if read to close hand then switch to
      //   read the other emg for the close signal
}

void loop() {
    if (!safetyOff) {
        if (comms.get_order() == STATE::SAFE_SHUTDOWN) {
            Serial.println("Safety is still turned off");
            safetyOff = true;
        }
    } else if (safetyOff) {
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

        int order = comms.get_order();
        manager.executeOrder(order);

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
}
