#include <HapticFeedback/HapticFeedback.h>

Haptic::Haptic(int pin) {
    this->pin = pin;
}

void Haptic::setup() {
    pinMode(this->pin, OUTPUT);
}

void Haptic::haptic(int power, int time) {
    //turning the motor on to specified power for 1000ms
    analogWrite(pin, power);
    delay(1000);
    Serial.println("specified power");

    //turning the motor off for specified time
    analogWrite(pin, 255);
    delay(time);
    Serial.println("off");
}

// example of usages
/*

haptic.haptic(50, 200); // High power vibrate and short delay
  
haptic.haptic(50, 1000); // high power vibrate with medium delay
 
haptic.haptic(50, 2000); // high power vibrate with long delay

haptic.haptic(165, 200); // low power vibrate with short delay

haptic.haptic(165, 1000); // low power vibrate with medium delay

haptic.haptic(165, 2000); // low power vibrate with long delay

*/
