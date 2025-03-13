#include "Car.h"
#include "Arduino.h"

Car::Car(uint8_t lPin1, uint8_t lPin2, uint8_t rPin1, uint8_t rPin2, uint8_t lPin1Channel, uint8_t lPin2Channel, uint8_t rPin1Channel, uint8_t rPin2Channel) 
  : motorL(lPin1, lPin2, lPin1Channel, lPin2Channel), motorR(rPin1, rPin2, rPin1Channel, rPin2Channel) {}

void Car::forward() {
  resetSpeed();
  motorL.forward();
  motorR.forward();
}

void Car::backward() {
  resetSpeed();
  motorL.backward();
  motorR.backward();
}

void Car::left() {
  resetSpeed();
  motorL.forward();
  motorR.backward();
}

void Car::right() {
  resetSpeed();
  motorL.backward();
  motorR.forward(); 
}

void Car::forwardLeft() {
  motorL.speed(255);
  motorR.speed(127);
  motorL.forward();
  motorR.forward();
}

void Car::forwardRight() {
  motorL.speed(127);
  motorR.speed(255);
  motorL.forward();
  motorR.forward();
}

void Car::stop() {
  motorL.stop();
  motorR.stop();
}

void Car::resetSpeed() {
  motorL.speed(255);
  motorR.speed(255);
}