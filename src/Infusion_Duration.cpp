#include "ProjectFunctions.h"

// inputs: FlowRate, VTBI
// outputs: Hour, Min, Sec

void Infusion_Duration(double FlowRate, double VTBI, int* Hour, int* Min, int* Sec) {

    double Time;
    
    if(FlowRate == 0 || VTBI == 0){
      Time = 0;
    }
    else{
      Time = VTBI / FlowRate;    //Calculate the time in decimal form
    }
    
    //if (FlowRate == 0){
    //  *Hour = 0;
    //  *Min = 0;
    //  *Sec = 0
    //}
    
    //Converting decimal number into hours, minutes, and seconds.
    int Hours = (int)Time;
    *Hour = Hours;
    double minutesRemainder = (Time - (double)Hours) * 60;
    int Minutes = (int)minutesRemainder;
    *Min = Minutes;
    double secondsRemainder = (minutesRemainder - (double)Minutes) * 60;
    int Seconds = (int)secondsRemainder;
    *Sec = Seconds;

    return;  // no return value
}