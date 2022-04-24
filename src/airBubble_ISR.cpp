#include "ProjectFunctions.h"

void IRAM_ATTR airBubble_ISR () {

do{
    display.clearDisplay();
    display.setTextSize(10);             // 10:1 pixel scale
    display.setTextColor(SSD1306_WHITE);        // Draw white text
    display.setCursor(0,0);
    display.println("   Air Bubble");
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

    do{
    buttonCancel.loop();
    buttonStart.loop();
    Blynk.virtualWrite(V10, 1); //notification App
    bool Exit, Resume, Begin;

    if(buttonCancel.isPressed()){
        Exit = true;
    }
    else if{
        Exit = false;  
    }

    if(buttonStart.isPressed()){
        Resume = true;
    }
    else if{
        Resume = false;  
    }
    }while(buttonCancel.isPressed()!=true || buttonStart.isPressed()!=true);
        
    if(Exit == true){
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(SSD1306_WHITE);        // Draw white text
        display.setCursor(0,0);
        display.println("Confirm Terminate Infusion?");
        display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
        display.print("Enter");
        display.setTextColor(SSD1306_WHITE);
        display.print(": yes  ");
        display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
        display.print("Cancel");
        display.setTextColor(SSD1306_WHITE);
        display.print(": no");
        display.display();
    }

    if(Resume == true){
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(SSD1306_WHITE);        // Draw white text
        display.setCursor(0,0);
        display.println("Confirm Continue Infusion?");
        display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
        display.print("Enter");
        display.setTextColor(SSD1306_WHITE);
        display.print(": yes  ");
        display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
        display.print("Cancel");
        display.setTextColor(SSD1306_WHITE);
        display.print(": no");
        display.display();
    }

    do{
        if(buttonCancel.isPressed()){
            Begin = true;
        }
        if(buttonStart.isPressed()){
            Begin = false;
        }
    }while(buttonCancel.isPressed()!=true || buttonStart.isPressed()!=true);
  }while(Begin == true);

    if(Exit == true){
        infComplete = true;
    }

}