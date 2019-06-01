#include <Arduino.h>
#include <Servo.h>
#include <motor.h>
#include <constants.h>

// Motor motor(PINS::THUMB_PWM);
Servo servo;
void setup()
{
    Serial.begin(9600);
    // motor.move_to(0);
    servo.attach(PINS::THUMB_PWM);
}

void loop()
{
    Serial.println("loopy boi");
    // motor.move_to(180);
    servo.write(50);
    delay(5000);
    servo.write(0);
    // motor.move_to(100);
    delay(5000);
}