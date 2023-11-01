/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/jml/Documents/programming/git_repositories/tdf-fa23-equilet/project_demonstrables/particle_workbench/pub_sub_var_func/src/pub_sub_var_func.ino"
/*
 * Project pub_sub_var_func
 * Description:
 * Author:
 * Date:
 */

void setup();
void loop();
#line 8 "/Users/jml/Documents/programming/git_repositories/tdf-fa23-equilet/project_demonstrables/particle_workbench/pub_sub_var_func/src/pub_sub_var_func.ino"
void photoLedHandler(const char *event, const char *data);

int temp = 0;
double floatval = 0.0;
#define POTPIN = A0;
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  // Particle.variable("temp", &temp, INT);
  // Particle.variable("mymessage", "Hello World", STRING);
  pinMode(A0, INPUT);

  Particle.variable("myfloat", &floatval, DOUBLE);
  Particle.subscribe("photoLed", photoLedHandler);
}

void photoLedHandler(const char *event, const char *data){
  Serial.printf("the raw data event: %s", data);
  float myvalue = (float)(atof(data));
  Serial.printf("the converted value: %f", myvalue); 
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // Particle.variable("temp", &temp, INT);
  // Particle.variable("mymessage", "Hello World", STRING);

  // //article.publish('0a10aced202194944a0446b0', "Hello World", PUBLIC);
  
  // if(temp == 10000){
  //   temp = 0;
  // }else{
  //   temp++;
  // }
  
  // The core of your code will likely live here.
  delay(1000);
}