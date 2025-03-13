#ifndef __CAR_H__
#define __CAR_H__
#include "DCMotor.h"
#include "stdint.h"

class Car {
  private:
    DCMotor motorL, motorR;

  public:
    Car(uint8_t lPin1, uint8_t lPin2, uint8_t rPin1, uint8_t rPin2, uint8_t lPin1Channel, uint8_t lPin2Channel, uint8_t rPin1Channel, uint8_t rPin2Channel);
    void forward();
    void backward();
    void left();
    void right();
    void forwardLeft();
    void forwardRight();
    void stop();
    void resetSpeed();
};

#endif