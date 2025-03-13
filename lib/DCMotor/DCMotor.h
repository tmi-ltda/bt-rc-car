#ifndef __DCMOTOR_H__
#define __DCMOTOR_H__
#include "stdint.h"

class DCMotor {
  private:
    uint8_t spd, pin1, pin2, pinChannel1, pinChannel2;
  
  public:
    DCMotor(uint8_t in1, uint8_t in2, uint8_t lChannel, uint8_t rChannel);
    void forward();
    void backward();
    void stop();
    void speed(uint8_t speed);
};

#endif