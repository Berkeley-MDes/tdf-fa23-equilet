/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/jml/Documents/programming/git_repositories/tdf-fa23-equilet/project_demonstrables/particle_workbench/basic_fsr_clockrates/src/basic_fsr_clockrates.ino"
/* FSR testing sketch. 
 
Connect one end of FSR to 3.3V, the other end to Analog 0.
Then connect one end of a ?K resistor from Analog 0 to ground
Connect LED from pin 11 through a resistor to ground 
 
For more information see www.ladyada.net/learn/sensors/fsr.html */

void setup(void);
void loop(void);
#line 9 "/Users/jml/Documents/programming/git_repositories/tdf-fa23-equilet/project_demonstrables/particle_workbench/basic_fsr_clockrates/src/basic_fsr_clockrates.ino"
int fsrAnalogPin = 0; // FSR is connected to analog 0
int fsrReading;      // the analog reading from the FSR resistor divider
 
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
}
 
void loop(void) {
  fsrReading = analogRead(fsrAnalogPin);
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);
 
  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map!

  String sensorVal = "{ analogread: " + String(fsrReading) + " }";
  Particle.publish("sensorval", sensorVal);
  delay(3000);
}