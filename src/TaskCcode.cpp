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

        int finalflag = flagB_Priority(battStatus, wifiStatus, flowHalt, overFlow, lowFlow, hiFlow, finalflag);

        buttonCancel.loop();
        if(buttonCancel.isPressed()){
          display.clearDisplay();
          display.setTextSize(1);             // Normal 1:1 pixel scale
          display.setTextColor(SSD1306_WHITE);        // Draw white text
          display.setCursor(0,0);
          display.print("......");
          display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
          display.print("Paused");
          display.setTextColor(SSD1306_WHITE);
          display.println("......");
          display.print("TimeLeft: ");
          display.print(Inf_Hours);
          display.print(":");
          display.print(Inf_Minutes);
          display.println(" Hr:min");
          display.println(" Hr:min");
          display.print("Vol inf: ");
          display.println(dripCount);
          display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
          display.print("Enter");
          display.setTextColor(SSD1306_WHITE);
          display.print(": yes  ");
          display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
          display.print("Cancel");
          display.setTextColor(SSD1306_WHITE);
          display.print(": no");
          display.display();

          vTaskSuspend(TaskB);//suspend taskB

          if(buttonCancel.isPressed()){
            infComplete = true;
          }
          if(buttonStart.isPressed()){
            vTaskResume(TaskB);
          }
        }

        if(finalflag == 1){
          display.clearDisplay();
          display.setTextSize(1);             // Normal 1:1 pixel scale
          display.setTextColor(SSD1306_WHITE);        // Draw white text
          display.setCursor(0,0);
          display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
          display.print("Infusing");
          display.setTextColor(SSD1306_WHITE);
          display.print("> !");
          display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
          display.println("LowBatt");
          display.setTextColor(SSD1306_WHITE);
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
        }

        if(finalflag == 2){
          display.clearDisplay();
          display.setTextSize(1);             // Normal 1:1 pixel scale
          display.setTextColor(SSD1306_WHITE);        // Draw white text
          display.setCursor(0,0);
          display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
          display.print("Infusing");
          display.setTextColor(SSD1306_WHITE);
          display.print("> !");
          display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
          display.println("noWiFi");
          display.setTextColor(SSD1306_WHITE);
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
        }

        if(finalflag == 5){
          display.clearDisplay();
          display.setTextSize(1);             // Normal 1:1 pixel scale
          display.setTextColor(SSD1306_WHITE);        // Draw white text
          display.setCursor(0,0);
          display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
          display.print("Infusing");
          display.setTextColor(SSD1306_WHITE);
          display.print(">!");
          display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
          display.println("LowFlow");
          display.setTextColor(SSD1306_WHITE);
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
        }
        if(finalflag == 6){
          display.clearDisplay();
          display.setTextSize(1);             // Normal 1:1 pixel scale
          display.setTextColor(SSD1306_WHITE);        // Draw white text
          display.setCursor(0,0);
          display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
          display.print("Infusing");
          display.setTextColor(SSD1306_WHITE);
          display.print(">  !");
          display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
          display.println("HiFlow");
          display.setTextColor(SSD1306_WHITE);
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
        }
        if(finalflag == 3){
          display.clearDisplay();
          display.setTextSize(10);             // 10:1 pixel scale
          display.setTextColor(SSD1306_WHITE);        // Draw white text
          display.setCursor(0,0);
          display.println("   FlowHalt");
          display.setTextSize(1);
          display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
          display.print("Start");
          display.setTextColor(SSD1306_WHITE);
          display.print(": infuse  ");
          display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
          display.print("Cancel");
          display.setTextColor(SSD1306_WHITE);
          display.print(": stop");
          display.display();
        }
        if(finalflag == 4){
          display.clearDisplay();
          display.setTextSize(10);             // 10:1 pixel scale
          display.setTextColor(SSD1306_WHITE);        // Draw white text
          display.setCursor(0,0);
          display.println("   OverFlow");
          display.setTextSize(1);
          display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
          display.print("Start");
          display.setTextColor(SSD1306_WHITE);
          display.print(": infuse  ");
          display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
          display.print("Cancel");
          display.setTextColor(SSD1306_WHITE);
          display.print(": stop");
          display.display();
        }

        vTaskDelay(1000/portTICK_PERIOD_MS);
      }
  } 
}