/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/jml/Documents/programming/git_repositories/tdf-fa23-equilet/project_demonstrables/particle_workbench/pub_sub_pub/src/publish_code.ino"
/*
 * Project pub_sub_var_func
 * Description:
 * Author:
 * Date:
 */

void setup();
void loop();
#line 8 "/Users/jml/Documents/programming/git_repositories/tdf-fa23-equilet/project_demonstrables/particle_workbench/pub_sub_pub/src/publish_code.ino"
double floatval = 0.0;
#define POTPIN = A0;
// setup() runs once, when the device is first turned on.
void setup() {
    pinMode(A0, INPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
    floatval = analogRead(A0);
    Particle.publish("photoLed", String(floatval), PRIVATE);
    Serial.printf("the published value: %f\n", floatval);
    delay(5000);
}