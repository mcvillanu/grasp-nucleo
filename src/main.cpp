#include <Arduino.h>
// #include <Servo.h>
#include <hand.h>
#include <wrist.h>
#include <communication.h>
#include <constants.h>
#include <emg.h>
#include <TaskManager.h>
#include <PololuMaestro.h>

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
bool safetyOff = false;
// Servo servo;

// Maestro servo controller stuff
// #ifdef SERIAL_PORT_HARDWARE_OPEN
//   #define maestroSerial SERIAL_PORT_HARDWARE_OPEN
// #else
  #include <SoftwareSerial.h>
  #include <HardwareSerial.h>
  SoftwareSerial maestroSerial(PA12, PB13);
// #endif
MicroMaestro maestro(maestroSerial);

Hand myHand(&maestro);
Wrist wrist(32);

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
    // wrist.rotate_by(5*360); 
    pinMode(3, INPUT);
    pinMode(PC12, OUTPUT);
    // Choose which emg pin to read. 
    // start with close hand. if read to close hand then switch to
      //   read the other emg for the close signal
    maestroSerial.begin(9600);
}

void loop()
{
    // if( safetyOff == false)
    // {
    //     if(comms.get_order() == MSG::SAFETY_OFF)
    //     {
    //         Serial.println("Safety is still turned off");
    //         safetyOff = true;
    //     }
    // }
    // else if(safetyOff == true)
    // {
    //     delayMicroseconds(wrist.poll());

    //     if (!written) {
    //         myHand.grip_Choose(0);
    //          written = true;
    //     }
    //     else if (written) {
    //         myHand.grip_Choose(5);
    //         written = false;
    //     }
    //     // // if (comms.get_order() == MSG::GRIP_HAMMER){
    //     // //     comms.send_confirmation();
    //     // //     motor.move_to(0);
    //     // //     motor2.move_to(0);
    //     // //     // servo.write(100);
    //     // //     delay(3000);
    //     // //     motor.move_to(50);
    //     // //     motor2.move_to(50);
    //     // //     delay(3000);
    //     // //     // servo.write(60);
    //     // //     motor.move_to(100);
    //     // //     motor2.move_to(100);
    //     // //     delay(5000);
    //     // // }
        
    //     int order = comms.get_order();
    //     manager.executeOrder(order);

    //     float voltage = emg.emg_voltage();
    //     Serial.println(voltage);
    //     //wrist.rotate_by(180);
    //     // wrist.rotate_by(-180);
    //     // delay(3000);

    // // delay(2000);
    // }
    maestro.setTarget(0, 5000);
    delay(2000);
    maestro.setTarget(0, 7999);
    delay(2000);
    wrist.rotate_by(180);
    delay(2000);
    wrist.rotate_by(-180);
    Serial.println("hello");

}