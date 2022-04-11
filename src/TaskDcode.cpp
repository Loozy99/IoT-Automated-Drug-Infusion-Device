#include "ProjectFunctions.h"
#ifndef BlynkSimpleEsp32_h
#include <BlynkSimpleEsp32.h>
#endif

void TaskDcode( void * pvParameters ){
  //Serial.print("TaskD running on core ");
  //Serial.println(xPortGetCoreID());
  
  for(;;){
    Blynk.run();
    if (infState == true){
        
        pinState = digitalRead(DripPin);
        
        if (pinState == LOW) {
          
          timePassed = millis()-lastTime;
          lastTime = millis();
          
          // turn LED on
          digitalWrite(ledPin, HIGH);
          vTaskDelay(50/portTICK_PERIOD_MS);
          dripCount = dripCount + 0.05;

          Blynk.virtualWrite(V8, dripCount);
    
          if (dripCount >= 0.05){
            flowRate_RT = 0.05 / timePassed * 3600000;
            Blynk.virtualWrite(V9, flowRate_RT);
            }            
        } 
        else {
          // turn LED off
          digitalWrite(ledPin, LOW);
        }
    }
    unsigned long inf_timePassed = millis() - infStart_Time;
    double infTime_Left =  infCounter - ((double)inf_timePassed/3600000);
    
    //Converting decimal number into hours, minutes, and seconds.
    Inf_Hours = (int)infTime_Left;
    double minutesRemainder = (infTime_Left - (double)Inf_Hours) * 60;
    Inf_Minutes = (int)minutesRemainder;
  }
}