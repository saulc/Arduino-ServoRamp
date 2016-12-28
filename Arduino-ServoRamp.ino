/*
 * 
 * Copyright [2016] [Saul Castro]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.


 Controlling a servo speed/acceleration

 Saul Castro
 12/2016
*/

#include "ServoRamp.h"
#include "Debounce.h"

//servo ramp param: pwm pin, midpoint, min, max, rampUpMS, rampDownMS
ServoRamp esc(6, 1500, 1000, 2000, 2000, 1000); 
ServoRamp s2(5, 1500, 1000, 2000, 500, 1200);
Debounce btn(3);
int pos = 1000;


void setup() {
  Serial.begin(9600);
  esc.ini();
  delay(20);
  s2.ini();
  btn.ini();
}

void loop() {
  if(btn.checkButton()){
    pl("on");
    
      esc.stepUp();
      s2.stepUp();
     // delay(10);
    

  } else{
    pl("off");
    esc.stepDown();
    s2.stepDown();
    //delay(10);

  }
  //pl(pos);
  delay(20);                           // waits for the servo to get there
}


void pt(String s){
  
  Serial.print(s);
}
void pl(String s){
  
  Serial.println(s);
}

void pt(int s){
  
  Serial.print(s);
}
void pl(int s){
  
  Serial.println(s);
}



