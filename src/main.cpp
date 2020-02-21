#include <Arduino.h>
#include <Servo.h>
#include <Communication/MaeComm/MaeComm.h>
#include <Hand/hand.h>
#include <Wrist/wrist.h>
#include <Communication/PiComm/PiComm.h>
#include <Utilities/Constants.h>
#include <Communication/EMGComm/EMGComm.h>
#include <TaskManager/TaskManager.h>
#include <PololuMaestro.h>
#include <Utilities/JSON/Object/Object.h>
#include <Utilities/JSON/Array/Array.h>
#include <Utilities/JSON/Base/Base.h>
#include <Utilities/JSON/Interpreter/Interpreter.h>
#include <Utilities/Miscellaneous/Miscellaneous.h>
#include <iostream>


void setup() {
  Pi::setup();
}

void loop() {
  String * const message = new String("{\"a\":24, \"b\":\"stringVal\", \"c\":true}");
  Object * const obj = Interpreter::deserialize<Object>(message);

  int * x = obj->getValue<int>("a");
  String * y = obj->getValue<String>("b");
  bool * z = obj->getValue<bool>("c");
  
  if (x) Pi::write(String(*x));
  if (y) Pi::write(*y);
  if (z) Pi::write(String(*z));

  delete x;
  delete y;
  delete z;
  Pi::write("test");
  Pi::write("1");
  Pi::write("2");
  Pi::write("3");

  delete message;
  delete obj;
}

// void loop() {
  // char const * const msg = Pi::read().c_str();
  // int const rSize = JSON_OBJECT_SIZE(1);
  // DynamicJsonDocument doc(rSize);
  // DeserializationError err = deserializeJson(doc,msg);
  // if (!err) {
  //   if (doc["asd"].as<int>() == 21) {
  //     Pi::write("{\"result\":\"3\"}");
  //   } else {
  //     Pi::write("{\"result\":\"2\"}");
  //   }
  //   // int const size = JSON_OBJECT_SIZE(1);
  //   // DynamicJsonDocument doc_out(size);
  //   // doc_out["result"] = "success";
  //   // serializeJson(doc_out,Serial);
  // } else {
  //   Pi::write("{\"result\":\"0\"}");
  //   // int const size = JSON_OBJECT_SIZE(1);
  //   // DynamicJsonDocument doc_out(size);
  //   // doc_out["result"] = "failed";
  //   // serializeJson(doc_out,Serial);
  // }
  // deserializeJson(doc,msg);
  // if (doc["asd"].as<int>() == 21) Pi::write("{\"result\":x}");
  // else Pi::write("{\"result\":\"failed\"}");
  // int x = doc["asd"].as<int>();
  // Serial.print("{\"result\":");
  // Serial.print(x);
  // Serial.print("}\n");
// }

// Different grip positions for the hand (values in arrays correspond to actuator movement to orient fingers)
// array value in order {thumb, index, middle, ring, pinky}
// int hammer[] = {100, 100, 100, 100, 100}; // Need to move this into hand.cpp
// int pinch[] = {50, 60, 60, 100, 100};
// int card[] = {100, 20, 20, 30, 40};
// int ball[] = {50, 50, 50, 50, 50};
// int cup[] = {50, 50, 50, 50, 75};
// int reset[] = {0, 0, 0, 0, 0};

// Uncomment:
// bool written = false; // prevents restarting the pwm signal that has been started from being reset
// int grasp_Val;
// -Uncomment


// Motor t_Motor(PINS::FINGERS::THUMB_PWM);
// Motor i_Motor(PINS::FINGERS::INDEX_PWM);
// Motor m_Motor(PINS::FINGERS::MIDDLE_PWM);
// Motor r_Motor(PINS::FINGERS::RING_PWM);
// Motor p_Motor(PINS::FINGERS::RING_PWM);
// Communication comms(9600);

// Uncomment
// Emg_signal emg(PINS::EMG::EMGSIGNAL);
// Wrist wrist(32);
// TaskManager manager;
// bool safetyOff = false;
// -Uncomment

// Emg_signal emg(PINS::EMG::EMGSIGNAL);
// Servo servo;

// void setup() {
//     /* Begin serial communication: */
//     // Serial.begin(9600);
    
//     /* Set up the motors */
//     comms.setup();
//     motor1.setup();
//     motor2.setup();
//     wrist.setup();

//     // servo.attach(PINS::THUMB_PWM);
//     wrist.rotate_by(5*360);
//     pinMode(3, INPUT);
//     pinMode(PC12, OUTPUT);
//     // Choose which emg pin to read.
//     // start with close hand. if read to close hand then switch to
//       //   read the other emg for the close signal
// }

// Uncomment
// Maestro servo controller stuff
// <<<<<<< HEAD
// #ifdef SERIAL_PORT_HARDWARE_OPEN
//   #define maestroSerial SERIAL_PORT_HARDWARE_OPEN
// #else
//   #include <SoftwareSerial.h>
//   SoftwareSerial maestroSerial(10, 11);
// #endif
// MicroMaestro maestro(maestroSerial);

// Hand myHand(&maestro);
// Wrist wrist(32);
// -Uncomment
// ======
// #ifdef SERIAL_PORT_HARDWARE_OPEN
//   #define maestroSerial SERIAL_PORT_HARDWARE_OPEN
// #else
//   #include <SoftwareSerial.h>
//   #include <HardwareSerial.h>
//   HardwareSerial maestroSerial(PA9, PB7);
// #endif
// MicroMaestro maestro(maestroSerial);

// Hand myHand(&maestro);
// Wrist wrist(32);

// void setup()
// {
//     Serial.begin(9600);
//     myHand.setup(); //setup from hand attachs all motors to pin outputs
//     // t_Motor.setup();
//     // i_Motor.setup();
//     // m_Motor.setup();
//     // r_Motor.setup();
//     // p_motor.setup();
//     wrist.setup();
//     comms.setup();
//     // servo.attach(PINS::THUMB_PWM);
//     wrist.rotate_by(5*360); 
//     pinMode(3, INPUT);
//     pinMode(PC12, OUTPUT);
//     // Choose which emg pin to read. 
//     // start with close hand. if read to close hand then switch to
//       //   read the other emg for the close signal
//     maestroSerial.begin(9600);
// }
// >>>>>>> ac7c5aa27ee78441d5c131610eb7b8509266de5b

// void setup()
// {
//     Serial.begin(9600);
//     myHand.setup(); //setup from hand attachs all motors to pin outputs
//     // t_Motor.setup();
//     // i_Motor.setup();
//     // m_Motor.setup();
//     // r_Motor.setup();
//     // p_motor.setup();
//     wrist.setup();
//     comms.setup();
//     // servo.attach(PINS::THUMB_PWM);
//     wrist.rotate_by(5*360); 
//     pinMode(3, INPUT);
//     pinMode(PC12, OUTPUT);
//     // Choose which emg pin to read. 
//     // start with close hand. if read to close hand then switch to
//       //   read the other emg for the close signal
//     maestroSerial.begin(9600);
// }

// void loop()
// {
//     if( safetyOff == false)
//     {
//         if(comms.get_order() == MSG::SAFETY_OFF)
//         {
//             Serial.println("Safety is still turned off");
//             safetyOff = true;
//         }
//     }
//     else if(safetyOff == true)
//     {
//         delayMicroseconds(wrist.poll());

//         if (!written) {
//             myHand.grip_Choose(0);
//              written = true;
//         }
//         else if (written) {
//             myHand.grip_Choose(5);
//             written = false;
//         }
//         // // if (comms.get_order() == MSG::GRIP_HAMMER){
//         // //     comms.send_confirmation();
//         // //     motor.move_to(0);
//         // //     motor2.move_to(0);
//         // //     // servo.write(100);
//         // //     delay(3000);
//         // //     motor.move_to(50);
//         // //     motor2.move_to(50);
//         // //     delay(3000);
//         // //     // servo.write(60);
//         // //     motor.move_to(100);
//         // //     motor2.move_to(100);
//         // //     delay(5000);
//         // // }
        
//         int order = comms.get_order();
//         manager.executeOrder(order);
//     }
// }

// void loop() {
//     if (!safetyOff) {
//         if (comms.get_order() == STATE::SAFE_SHUTDOWN) {
//             Serial.println("Safety is still turned off");
//             safetyOff = true;
//         }
//     } else if (safetyOff) {
//         delayMicroseconds(wrist.poll());
//         // // if (comms.get_order() == MSG::GRIP_HAMMER){
//         // //     comms.send_confirmation();
//         // //     motor.move_to(0);
//         // //     motor2.move_to(0);
//         // //     // servo.write(100);
//         // //     delay(3000);
//         // //     motor.move_to(50);
//         // //     motor2.move_to(50);
//         // //     delay(3000);
//         // //     // servo.write(60);
//         // //     motor.move_to(100);
//         // //     motor2.move_to(100);
//         // //     delay(5000);
//         // // }
//         int order = comms.get_order();
//         manager.executeOrder(order);

//         float voltage = emg.emg_voltage();
//         Serial.println(voltage);
//         //wrist.rotate_by(180);
//         // wrist.rotate_by(-180);
//         // delay(3000);

//         if (emg.peak_detected(voltage)) {
//             Serial.println("Flex that");
//             motor1.move_to(100);
//             delay(2000);
//             motor1.move_to(0);
//             wrist.rotate_by(100);
//         }
//     // delay(2000);
//     }
// }
