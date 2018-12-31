//Remote controlled LEDs 
// Work began in 5/5/18 and finished on 26/5/18 (Because of school work)

int Yellow_LED = 8;
int Blue_LED = 9;
int Green_LED = 10;
int White_LED = 11;
int LED_on_off [] = {0,0,0,0,0}; // The array of LEDs. Note: The zeros must be the number of LEDs + 1
                                
#include "IRremote.h"
int receiver = 12; // Signal Pin of IR receiver to Arduino Digital Pin 11

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

/*-----( Function )-----*/
void translateIR(){} // takes action based on IR code received

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn(); // Start the receiver
  pinMode (Yellow_LED, OUTPUT);
  pinMode (Blue_LED, OUTPUT);
  pinMode (Green_LED, OUTPUT);
  pinMode (White_LED, OUTPUT);
}/*--(end setup )---*/


void loop() {
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    translateIR(); 
    irrecv.resume(); // receive the next value
    switch(results.value) {
          case 0xFF30CF:
              if (LED_on_off [1]== 1) {
                  digitalWrite(Yellow_LED, LOW);       
                  LED_on_off [1] = 0;
                  Serial.println ("YELLOW LIGHT OFF");
              }
              else {
                  digitalWrite (Yellow_LED, HIGH);
                  LED_on_off [1] = 1;
                  Serial.println("YELLOW LIGHT ON");
              }
              break;
              
          case 0xFF18E7: 
              if (LED_on_off [2]== 1) {
                digitalWrite(Blue_LED, LOW);
                LED_on_off [2] = 0;
                Serial.println("BLUE LIGHT OFF");
              }
              else {
                digitalWrite(Blue_LED, HIGH);
                LED_on_off [2] = 1;
                Serial.println("BLUE LIGHT ON");
              }
              break;

          case 0xFF7A85: 
              if (LED_on_off [3] == 1) {
                digitalWrite(Green_LED, LOW);
                LED_on_off [3] = 0;
                Serial.println("GREEN LIGHT OFF");
              }
              else {
                  digitalWrite (Green_LED, HIGH);
                  LED_on_off [3] = 1;
                  Serial.println("GREEN LIGHT ON");
              }
              break;

          case 0xFF10EF:
              if (LED_on_off [4] == 1){
                digitalWrite(White_LED, LOW); 
                LED_on_off [4] = 0;
                Serial.println("WHITE LIGHT OFF");
              }
              else {
                digitalWrite (White_LED, HIGH);
                LED_on_off [4] = 1;
                Serial.println("WHITE LIGHT ON");
              }
              break;
          }
    }
  }  

/* --(end main loop )-- */


