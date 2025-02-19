#include "DCMotor.h"
#include "Arduino.h"


#define PWM_FREQUENCY 5000
#define PWM_RESOLUTION 8

DCMotor::DCMotor(int in1, int in2): spd(255) {
  pin1 = in1;
  pin2 = in2;

  ledcAttach(pin1, PWM_FREQUENCY, PWM_RESOLUTION);
  ledcAttach(pin2, PWM_FREQUENCY, PWM_RESOLUTION);

  ledcWrite(pin1, LOW);
  ledcWrite(pin2, LOW);
}

void DCMotor::Forward() {
  ledcWrite(pin1, spd);
  ledcWrite(pin2, LOW);
}

void DCMotor::Backward() {
  ledcWrite(pin1, LOW);
  ledcWrite(pin2, spd);
}

void DCMotor::Stop() {
  ledcWrite(pin1, LOW);
  ledcWrite(pin2, LOW);
}