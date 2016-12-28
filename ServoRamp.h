

#ifndef ServoRamp_h
#define ServoRamp_h

#include "Arduino.h"



#include <Servo.h>


class ServoRamp{

  public:
    ServoRamp(int pin);
    ServoRamp(int pin, int mid, int st, int ed);
    ServoRamp(int spin, int midd, int st, int ed, int upms, int downms);
 
    ~ServoRamp();

    void ini();
    int setValue(int);
    int getNeutral();
    void setNeutral(int);
    void rampUp();
    void rampDown();
    void stepUp();
    void stepDown();
  
  private: 
    int pin;
    int mid = 1500, mx = 2000, mn = 1000, nrange = 20;
    int rampUpMS = 2000, rampDownMS = 1000;
    int rampSteps = 20, upSteps, downSteps;
    
    Servo servo;

    //RAMPNIG VALUES
    int count, value, dir;
  
};

#endif


