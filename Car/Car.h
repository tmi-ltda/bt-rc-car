#ifndef __CAR_H__
#define __CAR_H__

#include "../DCMotor/DCMotor.h"

class Car {
  private:
    DCMotor motorL, motorR;

  public:
    Car(int lPin1, int lPin2, int rPin1, int rPin2);
    void Forward();
    void Backward();
    void Left();
    void Right();
    void Stop();
};

#include "Car.cpp"
#endif