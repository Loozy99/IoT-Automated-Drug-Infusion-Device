#include "ProjectFunctions.h"

float SetSpeed(float whatSpeed, int total_stepsPerRevolution){
  
  //Calculate the delay between steps in 'milisec' to achieve the required rpm
  float step_delay = 60L * 1000L  / total_stepsPerRevolution / whatSpeed;

  return step_delay;
}