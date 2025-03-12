#include "Car.h"
#include <Arduino.h>

Car::Car(uint8_t lPin1, uint8_t lPin2, uint8_t rPin1, uint8_t rPin2) : motorL(lPin1, lPin2), motorR(rPin1, rPin2) {}

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