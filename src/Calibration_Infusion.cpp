#include "ProjectFunctions.h"

void Calibration_Infusion (double Flowrate, double vtbi, double mL_revolution, int* Steps_Requred, float* RPM){

  *Steps_Requred = 2048 / mL_revolution * vtbi;

  *RPM = 1 / mL_revolution * Flowrate / 60;

  return;
}