#include <Arduino.h>
// #include <Servo.h>
#include <hand.h>
#include <wrist.h>
#include <communication.h>
#include <constants.h>
#include <emg.h>
#include <motor.h>
#include <TaskManager.h>
#include <PololuMaestro.h>
#include <SoftwareSerial.h>

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
Communication comms(9600);
Emg_signal emg(PINS::EMG_SIG);
TaskManager manager;
bool safetyOff = true;
// Servo servo;

// Maestro servo controller stuff
// #ifdef SERIAL_PORT_HARDWARE_OPEN
//   #define maestroSerial SERIAL_PORT_HARDWARE_OPEN
// #else
//   #include <HardwareSerial.h>
  SoftwareSerial maestroSerial(PA12, PB12);
// #endif
MicroMaestro maestro(maestroSerial);

Motor motor1(0,1, &maestro);
// Motor motor2(1,1, &maestro);
// Motor motor3(2,1, &maestro);

Hand myHand(&maestro);

Wrist wrist(32);

void setup()
{
    Serial.begin(9600);
    myHand.setup(); //setup from hand attachs all motors to pin outputs  
    Serial.println("setup");
    maestroSerial.begin(9600);
   
}

void loop()
{
    Serial.println("hi");
    // motor1.move_to(4001);


    myHand.grip_Choose(0);
    delay(2000);
    myHand.grip_Choose(1);
    // delay(2000);
    // motor1.move_to(7999);
    // motor2.move_to(4500);
    // motor3.move_to(4500);
    // maestro.setTarget(0, 7999);
    // myHand.grip_Choose(1);
    delay(2000);
    // wrist.rotate_by(180);
    // delay(2000);
    // wrist.rotate_by(-180);
    // Serial.println("hello");

}