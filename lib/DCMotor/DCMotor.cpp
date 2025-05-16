#include "DCMotor.h"
#include "Arduino.h"

#define PWM_FREQUENCY 5000
#define PWM_RESOLUTION 8

DCMotor::DCMotor(uint8_t in1, uint8_t in2): spd(255) {
  pin1 = in1;
  pin2 = in2;

  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);

  ledcAttach(pin1, PWM_FREQUENCY, PWM_RESOLUTION);
  ledcAttach(pin2, PWM_FREQUENCY, PWM_RESOLUTION);

  ledcWrite(pinChannel1, 0);
  ledcWrite(pinChannel2, 0);
}

void DCMotor::forward() {
  ledcWrite(pinChannel1, spd);
  ledcWrite(pinChannel2, 0);
}

void DCMotor::backward() {
  ledcWrite(pinChannel1, 0);
  ledcWrite(pinChannel2, spd);
}

void DCMotor::stop() {
  ledcWrite(pinChannel1, 0);
  ledcWrite(pinChannel2, 0);
}

void DCMotor::speed(uint8_t speed) {
  spd = speed;
}