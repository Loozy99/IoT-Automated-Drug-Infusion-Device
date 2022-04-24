#include "ProjectFunctions.h"

void PID_Control (float ref, float out, unsigned long T)
{
  float error = ref - out;
  unsigned long delT = T/1000;

  total_error += error; //accumalates the error - integral term
  delta_error = error - last_error; //difference of error for derivative term

  int Kp = 10;
  int Ki = 15;
  int Kd = 2;

  float control_signal = Kp*error + (Ki*delT)*total_error + (Kd/delT)*delta_error; //PID control compute

  if (control_signal >= 15) control_signal = 15;
  else if (control_signal <= 0) control_signal =0;

  step_delay = SetSpeed(control_signal, stepsPerRevolution);

  last_error = error;

  return;
  }