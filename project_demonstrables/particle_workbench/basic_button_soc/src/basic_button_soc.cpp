/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/jml/Documents/programming/git_repositories/tdf-fa23-equilet/project_demonstrables/particle_workbench/basic_button_soc/src/basic_button_soc.ino"
/*
 * Project basic_button_pw
 * Description: button publishes event upon state change
 * Author: Jeff Lubow 
 * Date: 10/12/2023
 */

void setup(void);
void loop(void);
#line 8 "/Users/jml/Documents/programming/git_repositories/tdf-fa23-equilet/project_demonstrables/particle_workbench/basic_button_soc/src/basic_button_soc.ino"
int button = D10; // button leg is connected to D10
int ledpin = D7;  // onboard LED is normalled to D7
const char *be = "button_event"; //the name of our published event
volatile int state = 0;
volatile int state_was = 0;

SYSTEM_THREAD(ENABLED); //this will allow the device to connect to the cloud while in setup()
 
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  pinMode(ledpin, OUTPUT); // sets pin as output
  pinMode(button, INPUT_PULLDOWN); // sets pin as input; defaults to low state
}

// //the fast stuff
void loop(void) {
  state = digitalRead(button);
  digitalWrite(ledpin, state); // sets the LED on, which can operate more frequently 
  String state_str = String(state);

  //only send on change (avoid spamming the cloud)
  if(state == 1 && state_was == 0) {
    Particle.publish(be, state_str, PRIVATE);
    Serial.printf("state: %d\n", state);
  } 
  //only send on change (avoid spamming the cloud)
  if(state == 0 && state_was == 1) {
    Particle.publish(be, state_str, PRIVATE);
    Serial.printf("state: %d\n", state);
  }

  state_was = state;
  delay(100);
}