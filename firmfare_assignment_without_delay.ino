#include "millisDelay.h"    // include millisDelay library
millisDelay delayLed;       // declare a variable delayLed

int LM35 = A0;   // Analog pin A0 for Temperature sensor
int led = 13;    // Digital pin 13 for LED
float temp = 0;  // variable to store the value coming from the sensor
float tempC=0;   // variable to store the temperature value in degree celcius

void setup() {
 
  pinMode(LM35, INPUT);  // declaring LM35 as an INPUT
  pinMode(led, OUTPUT);  // declaring led as an OUTPUT
  
}

void loop() {
 
  temp = analogRead(LM35);   // read the value from the sensor
  tempC=(temp*500)/1023;     // convert value to degree Celcius

// when Temperature falls below 30 degree celcius:
  if(tempC<30)
  {
  
  digitalWrite(led, HIGH);  // turn the led on

   // stop the program for 250 milliseconds:
    delayLed.start(250);
  
  digitalWrite(led, LOW);   // turn the led off

   // stop the program for 250 milliseconds:
    delayLed.start(250);
  
  }
  
  // when Temperature rises above 30 degree celcius:
  else if(tempC>30)  
  {

  digitalWrite(led, HIGH);   // turn the led on

  // stop the program for 500 milliseconds:
  delayLed.start(500);
  
  digitalWrite(led, LOW);     // turn the led off

  // stop the program for 500 milliseconds:
  delayLed.start(500);

  }
  
}
