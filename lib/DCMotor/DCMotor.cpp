#include "DCMotor.h"
#include "Arduino.h"

#define PWM_FREQUENCY 5000
#define PWM_RESOLUTION 8

DCMotor::DCMotor(uint8_t in1, uint8_t in2, uint8_t channel1, uint8_t channel2): spd(255) {
  pin1 = in1;
  pin2 = in2;
  pinChannel1 = channel1;
  pinChannel2 = channel2;

  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);

  ledcSetup(pinChannel1, PWM_FREQUENCY, PWM_RESOLUTION);
  ledcSetup(pinChannel2, PWM_FREQUENCY, PWM_RESOLUTION);
  ledcAttachPin(pin1, pinChannel1);
  ledcAttachPin(pin2, pinChannel2);

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