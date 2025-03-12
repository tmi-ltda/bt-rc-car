#include "DCMotor.h"
#include <Arduino.h>

DCMotor::DCMotor(uint8_t in1, uint8_t in2) : spd(255) {
  pin1 = in1;
  pin2 = in2;
  ledcAttach(pin1, 5000, 255);
  ledcAttach(pin2, 5000, 255);
}

void DCMotor::speed(uint8_t speed) {
  spd = speed;
}

void DCMotor::forward() {
  ledcWrite(pin1, spd);
  ledcWrite(pin2, LOW);
}

void DCMotor::backward() {
  ledcWrite(pin1, LOW);
  ledcWrite(pin2, spd);
}

void DCMotor::stop() {
  ledcWrite(pin1, LOW);
  ledcWrite(pin2, LOW);
}