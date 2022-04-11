#include "ProjectFunctions.h"

double FlowRate_Option (){
  int digit4 = 0;
  int digit3 = 0;
  int digit2 = 0;
  int digit1 = 0;
  int decimal = 0;
  double Flowrate = 0;

  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,9);
  display.print("FlowRate: ");
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
  display.print(digit4);
  display.setTextColor(SSD1306_WHITE); 
  display.println("000.0mL/Hr");
  display.println("VTBI: 0000.0 mL");
  display.println("Duration: __Hr__min");
  display.display();

//------MSB-----------------------------------------------------------------------
  do{
    buttonUp.loop(); // MUST call the loop() function first
    buttonDown.loop(); // MUST call the loop() function first
    buttonEnter.loop(); // MUST call the loop() function first
    
    if (buttonUp.isPressed() && digit4<9){
      digit4 ++;
      display.clearDisplay();
      display.setTextSize(1);             // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE);        // Draw white text
      display.setCursor(0,9);
      display.print("FlowRate: ");
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
      display.print(digit4);
      display.setTextColor(SSD1306_WHITE); 
      display.println("000.0mL/Hr");
      display.println("VTBI: 0000.0 mL");
      display.println("Duration: __Hr__min");
      display.display(); 
    }

    if (buttonDown.isPressed() && digit4>0){
      digit4 --;
      display.clearDisplay();
      display.setTextSize(1);             // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE);        // Draw white text
      display.setCursor(0,9);
      display.print("FlowRate: ");
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
      display.print(digit4);
      display.setTextColor(SSD1306_WHITE); 
      display.println("000.0mL/Hr");
      display.println("VTBI: 0000.0 mL");
      display.println("Duration: __Hr__min");
      display.display(); 
    }
    
  }while (buttonEnter.isPressed()!= true);
//-----------------------------------------------------------------------------------
      display.clearDisplay();
      display.setTextSize(1);             // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE);        // Draw white text
      display.setCursor(0,9);
      display.print("FlowRate: ");
      display.print(digit4);
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
      display.print(digit3);
      display.setTextColor(SSD1306_WHITE); 
      display.println("00.0mL/Hr");
      display.println("VTBI: 0000.0 mL");
      display.println("Duration: __Hr__min");
      display.display(); 
//----------Hundred------------------------------------------------------------------
  do{
    buttonUp.loop(); // MUST call the loop() function first
    buttonDown.loop(); // MUST call the loop() function first
    buttonEnter.loop(); // MUST call the loop() function first
    
    if (buttonUp.isPressed() && digit3<9){
      digit3 ++;
      display.clearDisplay();
      display.setTextSize(1);             // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE);        // Draw white text
      display.setCursor(0,9);
      display.print("FlowRate: ");
      display.print(digit4);
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
      display.print(digit3);
      display.setTextColor(SSD1306_WHITE); 
      display.println("00.0mL/Hr");
      display.println("VTBI: 0000.0 mL");
      display.println("Duration: __Hr__min");
      display.display(); 
    }

    if (buttonDown.isPressed() && digit3>0){
      digit3 --;
      display.clearDisplay();
      display.setTextSize(1);             // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE);        // Draw white text
      display.setCursor(0,9);
      display.print("FlowRate: ");
      display.print(digit4);
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
      display.print(digit3);
      display.setTextColor(SSD1306_WHITE); 
      display.println("00.0mL/Hr");
      display.println("VTBI: 0000.0 mL");
      display.println("Duration: __Hr__min");
      display.display(); 
    }
    
  }while (buttonEnter.isPressed()!= true);
//------------------------------------------------------------------------------------
      display.clearDisplay();
      display.setTextSize(1);             // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE);        // Draw white text
      display.setCursor(0,9);
      display.print("FlowRate: ");
      display.print(digit4);
      display.print(digit3);
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
      display.print(digit2);
      display.setTextColor(SSD1306_WHITE); 
      display.println("0.0mL/Hr");
      display.println("VTBI: 0000.0 mL");
      display.println("Duration: __Hr__min");
      display.display();
//----------Tenth------------------------------------------------------------------
  do{
    buttonUp.loop(); // MUST call the loop() function first
    buttonDown.loop(); // MUST call the loop() function first
    buttonEnter.loop(); // MUST call the loop() function first
    
    if (buttonUp.isPressed() && digit2<9){
      digit2 ++;
      display.clearDisplay();
      display.setTextSize(1);             // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE);        // Draw white text
      display.setCursor(0,9);
      display.print("FlowRate: ");
      display.print(digit4);
      display.print(digit3);
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
      display.print(digit2);
      display.setTextColor(SSD1306_WHITE); 
      display.println("0.0mL/Hr");
      display.println("VTBI: 0000.0 mL");
      display.println("Duration: __Hr__min");
      display.display(); 
    }

    if (buttonDown.isPressed() && digit2>0){
      digit2 --;
      display.clearDisplay();
      display.setTextSize(1);             // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE);        // Draw white text
      display.setCursor(0,9);
      display.print("FlowRate: ");
      display.print(digit4);
      display.print(digit3);
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
      display.print(digit2);
      display.setTextColor(SSD1306_WHITE); 
      display.println("0.0mL/Hr");
      display.println("VTBI: 0000.0 mL");
      display.println("Duration: __Hr__min");
      display.display(); 
    }
    
  }while (buttonEnter.isPressed()!= true);
//------------------------------------------------------------------------------------
      display.clearDisplay();
      display.setTextSize(1);             // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE);        // Draw white text
      display.setCursor(0,9);
      display.print("FlowRate: ");
      display.print(digit4);
      display.print(digit3);
      display.print(digit2);
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
      display.print(digit1);
      display.setTextColor(SSD1306_WHITE); 
      display.println(".0mL/Hr");
      display.println("VTBI: 0000.0 mL");
      display.println("Duration: __Hr__min");
      display.display(); 
//----------One------------------------------------------------------------------
  do{
    buttonUp.loop(); // MUST call the loop() function first
    buttonDown.loop(); // MUST call the loop() function first
    buttonEnter.loop(); // MUST call the loop() function first
    
    if (buttonUp.isPressed() && digit1<9){
      digit1 ++;
      display.clearDisplay();
      display.setTextSize(1);             // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE);        // Draw white text
      display.setCursor(0,9);
      display.print("FlowRate: ");
      display.print(digit4);
      display.print(digit3);
      display.print(digit2);
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
      display.print(digit1);
      display.setTextColor(SSD1306_WHITE); 
      display.println(".0mL/Hr");
      display.println("VTBI: 0000.0 mL");
      display.println("Duration: __Hr__min");
      display.display(); 
    }

    if (buttonDown.isPressed() && digit1>0){
      digit1 --;
      display.clearDisplay();
      display.setTextSize(1);             // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE);        // Draw white text
      display.setCursor(0,9);
      display.print("FlowRate: ");
      display.print(digit4);
      display.print(digit3);
      display.print(digit2);
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
      display.print(digit1);
      display.setTextColor(SSD1306_WHITE); 
      display.println(".0mL/Hr");
      display.println("VTBI: 0000.0 mL");
      display.println("Duration: __Hr__min");
      display.display();  
    }
    
  }while (buttonEnter.isPressed()!= true);
//------------------------------------------------------------------------------------
      display.clearDisplay();
      display.setTextSize(1);             // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE);        // Draw white text
      display.setCursor(0,9);
      display.print("FlowRate: ");
      display.print(digit4);
      display.print(digit3);
      display.print(digit2);
      display.print(digit1);
      display.print(".");
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
      display.print(decimal);
      display.setTextColor(SSD1306_WHITE); 
      display.println("mL/Hr");
      display.println("VTBI: 0000.0 mL");
      display.println("Duration: __Hr__min");
      display.display(); 
//----------Decimal------------------------------------------------------------------
  do{
    buttonUp.loop(); // MUST call the loop() function first
    buttonDown.loop(); // MUST call the loop() function first
    buttonEnter.loop(); // MUST call the loop() function first
    
    if (buttonUp.isPressed() && decimal<9){
      decimal ++;
      display.clearDisplay();
      display.setTextSize(1);             // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE);        // Draw white text
      display.setCursor(0,9);
      display.print("FlowRate: ");
      display.print(digit4);
      display.print(digit3);
      display.print(digit2);
      display.print(digit1);
      display.print(".");
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
      display.print(decimal);
      display.setTextColor(SSD1306_WHITE); 
      display.println("mL/Hr");
      display.println("VTBI: 0000.0 mL");
      display.println("Duration: __Hr__min");
      display.display(); 
    }

    if (buttonDown.isPressed() && decimal>0){
      decimal --;
      display.clearDisplay();
      display.setTextSize(1);             // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE);        // Draw white text
      display.setCursor(0,9);
      display.print("FlowRate: ");
      display.print(digit4);
      display.print(digit3);
      display.print(digit2);
      display.print(digit1);
      display.print(".");
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
      display.print(decimal);
      display.setTextColor(SSD1306_WHITE); 
      display.println("mL/Hr");
      display.println("VTBI: 0000.0 mL");
      display.println("Duration: __Hr__min");
      display.display();   
    }
    
  }while (buttonEnter.isPressed()!= true);
//------------------------------------------------------------------------------------

  Flowrate = (digit4 * 1000)+(digit3 * 100)+(digit2 * 10)+(digit1)+(decimal*0.1);
  return Flowrate;
}