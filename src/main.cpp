#include <Arduino.h>
// #include <Servo.h>
#include <hand.h>
#include <wrist.h>
#include <communication.h>
#include <constants.h>
#include <emg.h>


// Motor motor(PINS::THUMB_PWM);
// Motor motor2(PINS::INDEX_PWM);

// Different grip positions for the hand (values in arrays correspond to actuator movement to orient fingers)
//array value in order {thumb, index, middle, ring, pinky}
// int hammer[] = {100, 100, 100, 100, 100}; // Need to move this into hand.cpp
// int pinch[] = {50, 60, 60, 100, 100};
// int card[] = {100, 20, 20, 30, 40};
// int ball[] = {50, 50, 50, 50, 50};
// int cup[] = {50, 50, 50, 50, 75};
// int reset[] = {0, 0, 0, 0, 0};
bool written = false; // prevents restarting the pwm signal that has been started from being reset
int grasp_Val;
// Motor t_Motor(PINS::THUMB_PWM);
// Motor i_Motor(PINS::INDEX_PWM);
// Motor m_Motor(PINS::MIDDLE_PWM);
// Motor r_Motor(PINS::RING_PWM);
// Motor p_Motor(PINS::RING_PWM);
Hand myHand;
Wrist wrist(32);
Communication comms(9600);
Emg_signal emg(PINS::EMG_SIG);
// Servo servo;

void setup()
{
    Serial.begin(9600);
    myHand.setup(); //setup from hand attachs all motors to pin outputs
    // t_Motor.setup();
    // i_Motor.setup();
    // m_Motor.setup();
    // r_Motor.setup();
    // p_motor.setup();
    wrist.setup();
    comms.setup();
    // servo.attach(PINS::THUMB_PWM);
    wrist.rotate_by(5*360);
}

void loop()
{   

    if (!written) {
        myHand.grip_Choose(0);
        written = true;
    }
    else if (written) {
        myHand.grip_Choose(5);
        written = false;
    }

    // // Hammer:
    // Serial.println("Hammer");
    // t_Motor.move_to(hammer[0]);
    // i_Motor.move_to(hammer[1]);
    // m_Motor.move_to(hammer[2]);
    // r_Motor.move_to(hammer[3]);
    // p_Motor.move_to(hammer[4]);
    // delay(3000);
    // t_Motor.move_to(reset[0]);
    // i_Motor.move_to(reset[1]);
    // m_Motor.move_to(reset[2]);
    // r_Motor.move_to(reset[3]);
    // p_Motor.move_to(reset[4]);
    // delay(3000);

    // // Cup:
    // Serial.println("Cup");
    // t_Motor.move_to(cup[0]);
    // i_Motor.move_to(cup[1]);
    // m_Motor.move_to(cup[2]);
    // r_Motor.move_to(cup[3]);
    // p_Motor.move_to(cup[4]);
    // delay(3000);
    // t_Motor.move_to(reset[0]);
    // i_Motor.move_to(reset[1]);
    // m_Motor.move_to(reset[2]);
    // r_Motor.move_to(reset[3]);
    // p_Motor.move_to(reset[4]);
    // delay(3000);

    // // Pinch:
    // Serial.println("Pinch");
    // t_Motor.move_to(pinch[0]);
    // i_Motor.move_to(pinch[1]);
    // m_Motor.move_to(pinch[2]);
    // r_Motor.move_to(pinch[3]);
    // p_Motor.move_to(pinch[4]);
    // delay(3000);
    // t_Motor.move_to(reset[0]);
    // i_Motor.move_to(reset[1]);
    // m_Motor.move_to(reset[2]);
    // r_Motor.move_to(reset[3]);
    // p_Motor.move_to(reset[4]);
    // delay(3000);

    // // Card:
    // Serial.println("Card");
    // t_Motor.move_to(card[0]);
    // i_Motor.move_to(card[1]);
    // m_Motor.move_to(card[2]);
    // r_Motor.move_to(card[3]);
    // p_Motor.move_to(card[4]);
    // delay(3000);
    // t_Motor.move_to(reset[0]);
    // i_Motor.move_to(reset[1]);
    // m_Motor.move_to(reset[2]);
    // r_Motor.move_to(reset[3]);
    // p_Motor.move_to(reset[4]);
    // delay(3000);

    // // Ball
    // Serial.println("Ball");
    // t_Motor.move_to(ball[0]);
    // i_Motor.move_to(ball[1]);
    // m_Motor.move_to(ball[2]);
    // r_Motor.move_to(ball[3]);
    // p_Motor.move_to(ball[4]);
    // delay(3000);
    // t_Motor.move_to(reset[0]);
    // i_Motor.move_to(reset[1]);
    // m_Motor.move_to(reset[2]);
    // r_Motor.move_to(reset[3]);
    // p_Motor.move_to(reset[4]);
    // delay(3000);
    
    // delayMicroseconds(wrist.poll());
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
    // float voltage = emg.emg_voltage();
    // Serial.println(voltage);
    //wrist.rotate_by(180);
    // wrist.rotate_by(-180);
    // delay(3000);

    // if (emg.peak_detected(voltage)) {
    //     Serial.println("Flex that");
    //     motor.move_to(100);
    //     delay(2000);
    //     motor.move_to(0);
    //     wrist.rotate_by(100);

    // }
   // delay(2000);
}