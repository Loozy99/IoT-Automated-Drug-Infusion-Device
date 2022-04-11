#include "ProjectFunctions.h"
#ifndef BlynkSimpleEsp32_h
#include <BlynkSimpleEsp32.h>
#endif

void Send_Time (int hour, int minute, int sec, bool with_Sec, int Virtual_Pin){

  String Inf_Duration;
  
  if (with_Sec == true){
    Inf_Duration = String(hour)+":"+String(minute)+":"+String(sec);  //Convert infusion duration to string for sending to server
    if (Virtual_Pin == 2){
      Blynk.virtualWrite(V2, Inf_Duration);
    }
    else if (Virtual_Pin == 5){
      Blynk.virtualWrite(V5, Inf_Duration);
    }
  }

  else if (with_Sec == false){
    Inf_Duration = String(hour)+":"+String(minute);//Convert infusion duration to string for sending to server
    if (Virtual_Pin == 2){
      Blynk.virtualWrite(V2, Inf_Duration);
    }
    else if (Virtual_Pin == 5){
      Blynk.virtualWrite(V5, Inf_Duration);
    }
  }
  return;
}