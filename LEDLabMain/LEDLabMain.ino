/*
 Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 
 This example code is in the public domain.
 */

int led = 9;           // the pin that the LED is attached to
int upbutt = 4;        // increase brightness button
int downbutt = 2;      // decrease brightness button
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int output;

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  pinMode(upbutt, INPUT);
  pinMode(downbutt, INPUT);
} 

// the loop routine runs over and over again forever:
void loop()  { 
  
  output = read_buttons();
  
  
  
  
  // set the brightness of pin 9:
  analogWrite(led, brightness);    
  
  // change the brightness for next time through the loop:
  brightness = brightness + output*fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(30);                            
}



