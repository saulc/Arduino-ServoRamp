


#include "ServoRamp.h"


ServoRamp::ServoRamp(int spin){
    pin = spin;
   
}

ServoRamp::ServoRamp(int spin, int midd, int st, int ed){
    pin = spin;
    mid = midd;   //neutral
    mn = st;    //start point
    mx = ed;    //end point
    //ini();
}

ServoRamp::ServoRamp(int spin, int midd, int st, int ed, int upms, int downms){
    pin = spin;
    mid = midd;   //neutral
    mn = st;    //start point
    mx = ed;    //end point
    rampUpMS = upms;
    rampDownMS = downms;
    //ini();
}

ServoRamp::~ServoRamp(){
       
}


void ServoRamp::stepUp(){
    if(value < mx){
        value += upSteps;
        setValue(value);      
        //delay(10);
    }
}
void ServoRamp::stepDown(){
    if(value > mn){
        value -= downSteps;
        setValue(value);      
        //delay(10);
    }
}

void ServoRamp::rampUp(){
    for(value; value < mx; value += upSteps){
      setValue(value);      
      delay(10);
    }
}

void ServoRamp::rampDown(){
    for(value; value > mn; value -= downSteps){
      setValue(value);   
      delay(10);   
    }
}

void ServoRamp::ini(){
     downSteps = rampDownMS/(1000/rampSteps);
     upSteps = rampUpMS/(1000/rampSteps);
  servo.attach(pin, mn, mx);
  
}

int ServoRamp::setValue(int v){
  if(v >= mn & v <= mx){
   // if(v < nrange && v > -nrange) v = 0;  //add neutral range
    
    servo.writeMicroseconds(v);
  }
}

void ServoRamp::setNeutral(int v){
    mid = v;
}
 
int ServoRamp::getNeutral(){
  return mid;
}


