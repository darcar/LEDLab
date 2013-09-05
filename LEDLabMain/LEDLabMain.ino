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
  
  Serial.begin(9600);
} 

// the loop routine runs over and over again forever:
void loop()  { 
  
  // call read button function
  output = read_buttons();
  Serial.println(output);   
  
  // change the brightness for next time through the loop:
  if (brightness >= 5) {
    brightness = brightness + output*fadeAmount;
    Serial.println(brightness);
  }

  // set the brightness of pin 9:
  analogWrite(led, brightness); 
  
  // case
  
  while (brightness >= 255) {
     flashing();
     delay(5);
  }
  
  
  // wait for 30 milliseconds to see the dimming effect    
  delay(30);                            
}

void flashing() {
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW); 
  delay(500);
}



