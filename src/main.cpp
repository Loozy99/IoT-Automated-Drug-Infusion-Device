#include "ProjectFunctions.h"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "SSID";  // WiFi credentials.
char pass[] = "Wifi_Password";

ezButton buttonUp(4);       // create Up Button object that attach to pin GIOP4;
ezButton buttonDown(16);    // create Down Button object that attach to pin GIOP16;
ezButton buttonStart(17);   // create Start Button object that attach to pin GIOP17;
ezButton buttonCancel(5);  // create Cancel Button object that attach to pin GIOP5;
ezButton buttonEnter(18);   // create Enter Button object that attach to pin GIOP18;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

BlynkWifi Blynk(_blynkTransport);

//Global Variables
const int stepsPerRevolution = 2048;
volatile double FlowRate = 0;
volatile double VTBI = 0;
int Inf_Hours;
int Inf_Minutes;
int Inf_Seconds;
int totalSteps;
float rpm;
bool Start_Infuse = false;
bool Cancel_Infuse = false;

// variable for storing the drip status 
int pinState = 0;
float dripCount = 0;
float flowRate_RT = 0;
unsigned long timePassed;
unsigned long lastTime;
unsigned long infStart_Time;
double infCounter;

//flags
volatile bool infState = false;

// When FlowRate is entered tru app/dashboard
BLYNK_WRITE(V0) {
  FlowRate = param.asDouble();
}

// When FlowRate is entered tru app/dashboard
BLYNK_WRITE(V1) {
  VTBI = param.asDouble();
}

// When Start is entered tru app/dashboard
BLYNK_WRITE(V6) {
  Start_Infuse = true;
}

BLYNK_WRITE(V7) {
  Cancel_Infuse = true;
}


void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  
  buttonUp.setDebounceTime(DEBOUNCE_TIME); // set debounce time to 50 milliseconds
  buttonDown.setDebounceTime(DEBOUNCE_TIME); // set debounce time to 50 milliseconds
  buttonStart.setDebounceTime(DEBOUNCE_TIME); // set debounce time to 50 milliseconds
  buttonCancel.setDebounceTime(DEBOUNCE_TIME); // set debounce time to 50 milliseconds
  buttonEnter.setDebounceTime(DEBOUNCE_TIME); // set debounce time to 50 milliseconds

  // initialize the drip pin as an input
  pinMode(DripPin, INPUT);
  // initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);

  pinMode(motor_pin_1, OUTPUT);
  pinMode(motor_pin_2, OUTPUT);
  pinMode(motor_pin_3, OUTPUT);
  pinMode(motor_pin_4, OUTPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  vTaskDelay(1000/portTICK_PERIOD_MS);

  Blynk.virtualWrite(V3, 0);

  display.clearDisplay();

  attachInterrupt(intrPin, airBubble_ISR, RISING);

  //create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
                    TaskBcode,   /* Task function. */
                    "TaskB",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &TaskB,      /* Task handle to keep track of created task */
                    1);          /* pin task to core 1 */

  //create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
                    TaskCcode,   /* Task function. */
                    "TaskC",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &TaskC,      /* Task handle to keep track of created task */
                    1);          /* pin task to core 1 */

  //create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
                    TaskDcode,   /* Task function. */
                    "TaskD",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &TaskD,      /* Task handle to keep track of created task */
                    1);          /* pin task to core 1 */
  
  vTaskDelay(500/portTICK_PERIOD_MS);

}

//Task_B
void TaskBcode( void * pvParameters ){
  for(;;){
     Blynk.run();
    Blynk.virtualWrite(V4, "select input data");
    buttonEnter.loop(); // MUST call the loop() function first
    buttonStart.loop(); // MUST call the loop() function first
    
    if (buttonEnter.isPressed()){
      buttonEnter.loop();
      Blynk.virtualWrite(V3, 0);
      FlowRate = FlowRate_Option ();
      VTBI = VTBI_Option (FlowRate);
      Blynk.virtualWrite(V0, FlowRate);
      Blynk.virtualWrite(V1, VTBI);
    }

    
    Infusion_Duration(FlowRate, VTBI, &Inf_Hours, &Inf_Minutes, &Inf_Seconds);
    String Inf_Duration = String(Inf_Hours)+":"+String(Inf_Minutes)+":"+String(Inf_Seconds);  //Convert infusion duration to string for sending to server
    Send_Time (Inf_Hours, Inf_Minutes, Inf_Seconds, true, 2);

    if (buttonStart.isPressed()){
      buttonStart.loop();

      if(FlowRate == 0 && VTBI == 0){
        Blynk.virtualWrite(V3, 1);
        Blynk.virtualWrite(V4, "Flow Rate & VTBI is 0mL/hr and 0mL, please re-enter");
      }
      else if (FlowRate == 0){
        Blynk.virtualWrite(V3, 1);
        Blynk.virtualWrite(V4, "Flow Rate is 0mL/hr, please re-enter");
      }
      else if (VTBI == 0){
        Blynk.virtualWrite(V3, 1);
        Blynk.virtualWrite(V4, "Volume to be infused is 0mL, please re-enter");
      }
      else{
        Blynk.virtualWrite(V3, 2);
        Calibration_Infusion (FlowRate, VTBI, 0.2, &totalSteps, &rpm);
        step_delay =  SetSpeed(rpm, stepsPerRevolution);
        
        display.clearDisplay();
        display.setTextSize(1);             // Normal 1:1 pixel scale
        display.setTextColor(SSD1306_WHITE);        // Draw white text
        display.setCursor(0,0);
        display.print("FlowRate is ");
        display.println(FlowRate);
        display.print("VTBI is ");
        display.println(VTBI);
        display.print("Duration is ");
        display.println(Inf_Duration);
        display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
        display.print("Enter");
        display.setTextColor(SSD1306_WHITE);
        display.print("          ");
        display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
        display.print("Cancel");
        display.display(); 
        vTaskDelay(100);
        Blynk.virtualWrite(V4, "Please press start to initialize infusion");
        
        do{
          Blynk.run();
          buttonEnter.loop(); // MUST call the loop() function first
          buttonCancel.loop(); // MUST call the loop() function first
          buttonStart.loop();
          if (buttonEnter.isPressed()){
            Start_Infuse = true;
          }
          else if (buttonCancel.isPressed()){
            Cancel_Infuse = true;
          }
        }while(Start_Infuse != true && Cancel_Infuse != true );

        buttonEnter.loop();
        buttonCancel.loop();
        Cancel_Infuse = false;

        if(Start_Infuse == true){
          display.clearDisplay();
          display.setTextSize(1);             // Normal 1:1 pixel scale
          display.setTextColor(SSD1306_WHITE);        // Draw white text
          display.setCursor(0,0);
          display.print("Infusing... ");
          display.display();
          Blynk.virtualWrite(V3, 3);
          Blynk.virtualWrite(V4, "Infusing");
          vTaskDelay(100/portTICK_PERIOD_MS);
          infStart_Time = millis();
          lastTime = millis();
          infState = true;
          Infusion_Process(totalSteps);
          infState = false;
          vTaskDelay(500/portTICK_PERIOD_MS);
          Blynk.virtualWrite(V3, 5);
          Blynk.virtualWrite(V4, "Completed");
          Start_Infuse = false;
        }
      }
    }

    display.clearDisplay();
    display.setTextSize(1);             // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE);        // Draw white text
    display.setCursor(0,0);
    display.print("FR:");
    display.print(FlowRate);
    display.print("|VTBI:");
    display.println(VTBI);
    display.print("Duration is ");
    display.println(Inf_Duration);
    display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
    display.print("Start");
    display.setTextColor(SSD1306_WHITE);
    display.println("->infuse");
    display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
    display.print("Enter");
    display.setTextColor(SSD1306_WHITE);
    display.println("->edit");
    display.display();
  
  }
}

void loop() {
 vTaskDelete(NULL);
}