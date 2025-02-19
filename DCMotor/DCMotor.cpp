#include "DCMotor.h"
#include "Arduino.h"

DCMotor::DCMotor(int in1, int in2): spd(255) {
  pin1 = in1;
  pin2 = in2;

  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);

  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
}

void DCMotor::Forward() {
  analogWrite(pin1, spd);
  digitalWrite(pin2, LOW);
}

void DCMotor::Backward() {
  digitalWrite(pin1, LOW);
  analogWrite(pin2, spd);
}

void DCMotor::Stop() {
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
}