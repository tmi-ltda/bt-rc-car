#include "Car.h"
#include "Arduino.h"

Car::Car(int lPin1, int lPin2, int rPin1, int rPin2)
  : motorL(lPin1, lPin2), motorR(rPin1, rPin2) {}

void Car::Forward() {
  motorL.Forward();
  motorR.Forward();
}

void Car::Backward() {
  motorL.Backward();
  motorR.Backward();
}

void Car::Left() {
  motorL.Forward();
  motorR.Backward();
}

void Car::Right() {
  motorL.Backward();
  motorR.Forward();
}

void Car::Stop() {
  motorL.Stop();
  motorR.Stop();
}