#include "ProjectFunctions.h"

void Infusion_Process(int steps_to_move)
{
  int steps_left = abs(steps_to_move);  // how many steps to take
  int step_number = 0;
  unsigned long last_step_time = 0;
  bool Direction;

  // determine direction based on whether steps_to_mode is + or -:
  if (steps_to_move > 0) { Direction = 1; }
  if (steps_to_move < 0) { Direction = 0; }


  // decrement the number of steps, moving one step each time:
  while (steps_left > 0)
  {
    unsigned long now = millis();
    // move only if the appropriate delay has passed:
    if (now - last_step_time >= step_delay)
    {
      // get the timeStamp of when you stepped:
      last_step_time = now;
      // increment or decrement the step number,
      // depending on direction:
      if (Direction == 1)
      {
        step_number++;
        if (step_number == 2048) {
          step_number = 0;
        }
      }
      else
      {
        if (step_number == 0) {
          step_number = 2048;
        }
        step_number--;
      }
      // decrement the steps left:
      steps_left--;
      // step the motor to step number 0, 1, ..., {3 or 10}
        stepMotor(step_number % 4);
    }
  }
 return; 
}