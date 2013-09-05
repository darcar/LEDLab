// Team Zephyrus
// Daria, Jessica, Trisha, Kristie

// Code modified from Fade (Arduino Example Code)

int led = 9;           // the pin that the LED is attached to
int upbutt = 4;        // increase brightness button
int downbutt = 2;      // decrease brightness button
float brightness = 0;    // how bright the LED is
float fadeAmount = 0.25;    // how many points to fade the LED by
int output;

// the setup routine runs once when you press reset:
void setup()  { 
  
  pinMode(led, OUTPUT);      // declare pin 9 to be an output:
  pinMode(upbutt, INPUT);    // declare pin 4 to be an input:
  pinMode(downbutt, INPUT);  // declare pin 2 to be an input:
  
  Serial.begin(9600);
} 

// the loop routine runs over and over again forever:
void loop()  { 
  
  // call read button function
  output = read_buttons(brightness);  
  
  // adjust brightness. output = 1 if up button, 
  // output = -1 if down button, output = 0 if both or no buttons
  brightness = brightness + output*fadeAmount;

  // set the brightness of pin 9:
  analogWrite(led, brightness);   // writes brightness "analogly" to led
  
  // stuck in while loop once max brightness level was reached
  while (brightness >= 255) {
     flashing();    // call flashing function bc max val has been reached
  }
  
  // wait for 30 milliseconds to see the dimming effect    
  delay(30);                            
}

// flashing function when LED reaches max value
void flashing() {
  digitalWrite(led, HIGH);  // write ON val to LED
  delay(500);
  digitalWrite(led, LOW);   // write ON val to LED
  delay(500);
}



