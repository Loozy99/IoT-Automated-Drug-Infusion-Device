#include "ProjectFunctions.h"

void TaskCcode( void * pvParameters ){
  //Serial.print("TaskC running on core ");
  //Serial.println(xPortGetCoreID());

  for(;;){
    if (infState == true){
        display.clearDisplay();
        display.setTextSize(1);             // Normal 1:1 pixel scale
        display.setTextColor(SSD1306_WHITE);        // Draw white text
        display.setCursor(0,0);
        display.print(">>>>>>");
        display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
        display.print("Infusing");
        display.setTextColor(SSD1306_WHITE);
        display.println(">>>>>>");
        display.print("TimeLeft: ");
        display.print(Inf_Hours);
        display.print(":");
        display.print(Inf_Minutes);
        display.println(" Hr:min");
        display.print("Vol inf: ");
        display.println(dripCount);
        display.print("FlowRate: ");
        display.println(flowRate_RT);
        display.display();
        vTaskDelay(1000/portTICK_PERIOD_MS);
      }
  } 
}