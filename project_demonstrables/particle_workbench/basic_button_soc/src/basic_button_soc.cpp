/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/jml/Documents/programming/git_repositories/tdf-fa23-equilet/project_demonstrables/basic_button_pw/basic_button_pw/src/basic_button_pw.ino"
/*
 * Project basic_button_pw
 * Description: button config for p5js web sketch 
 * Author: Jeff Lubow 
 * Date: 9/17/23
 */

void setup(void);
void loop(void);
#line 8 "/Users/jml/Documents/programming/git_repositories/tdf-fa23-equilet/project_demonstrables/basic_button_pw/basic_button_pw/src/basic_button_pw.ino"
int button = D10; // button leg is connected to D10
int ledpin = D7; 
const char *be = "button_event"; //the name of our webhook event
volatile int state = 0;
volatile int state_was = 0;

void button_update(void);
 
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  pinMode(ledpin, OUTPUT); // sets pin as output
  pinMode(button, INPUT_PULLDOWN); // sets pin as input; defaults to low state
}
 
void button_update(void) {
  String state_str = String(state);
  digitalWrite(ledpin, state); // sets the LED on  
  Particle.publish(be, state_str, PRIVATE);
}

//the fast stuff
void loop(void) {
  state = digitalRead(button);
  String state_str = String(state);

  Serial.printf("state: %d\n", state);
  // String state_str = String(state);
  // digitalWrite(ledpin, state); // sets the LED on  
  if(state == 1 && state_was == 0) {
    Particle.publish(be, state_str, PRIVATE);
  } 
  if(state == 0 && state_was == 1) {
    Particle.publish(be, state_str, PRIVATE);
  }

  state_was = state;
  delay(100);
}