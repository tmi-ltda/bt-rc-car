#ifndef __DCMOTOR_H__
#define __DCMOTOR_H__

class DCMotor {
  private:
    int spd, pin1, pin2;
  
  public:
    DCMotor(int in1, int in2);
    void Forward();
    void Backward();
    void Stop();
};

#include "DCMotor.cpp"
#endif