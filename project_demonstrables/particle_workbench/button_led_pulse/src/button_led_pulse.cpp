/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/jml/Documents/programming/git_repositories/tdf-fa23-equilet/project_demonstrables/particle_workbench/button_led_pulse/src/button_led_pulse.ino"
/*
 * Project button_led_pulse
 * Description: use a button to change the pulse rate of an LED
 * Author: Jeff Lubow
 * Date: 10/8/23
 */

void setup();
void buttonPressed();
void loop();
#line 8 "/Users/jml/Documents/programming/git_repositories/tdf-fa23-equilet/project_demonstrables/particle_workbench/button_led_pulse/src/button_led_pulse.ino"
SYSTEM_THREAD(ENABLED);
const int ledPin = D7; // the pin that the LED is attached to
const int buttonPin = D6; // this pin can be used as an interrupt pin
int pulserate = 900; // variable to store the read value
bool buttonval = false;

// setup() runs once, when the device is first turned on.
void setup() {
  interrupts(); //enable interrupts
  pinMode(ledPin, OUTPUT); // initialize the LED pin as an output:
  pinMode(buttonPin, INPUT_PULLDOWN); // initialize the pushbutton pin as an input:
  attachInterrupt(buttonPin, buttonPressed, RISING); //attach an interrupt to the button pin, based on the rising edge
  // Put initialization like pinMode and begin functions here.

}

//this function is called whenever the button is pressed
//this happens separately from the main loop
void buttonPressed() {
    pulserate = pulserate - 50;
    
    if (pulserate < 50) {
      pulserate = 900;
    }
  
}
// loop() runs over and over again, as quickly as it can execute.
void loop() {
  digitalWrite(ledPin, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(pulserate);  // delay for the pulse value (ms)
  digitalWrite(ledPin, LOW); // turn the LED off by making the voltage LOW
  delay(pulserate); // delay for the pulse value (ms)
}