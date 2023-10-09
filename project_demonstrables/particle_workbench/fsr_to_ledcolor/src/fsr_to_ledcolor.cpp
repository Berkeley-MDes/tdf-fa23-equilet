/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/jml/Documents/programming/git_repositories/tdf-fa23-equilet/project_demonstrables/particle_workbench/fsr_to_ledcolor/src/fsr_to_ledcolor.ino"
/*
 * Project fsr_to_ledcolor
 * Description:
 * Author:
 * Date:
 */

//RGB mappings - no resistors needed
// const int red = D1; //R is SCL
// const int green = D16; //G is MI
// const int blue = D15; //B is MO
//SYSTEM_THREAD(ENABLED);


void setup();
void loop();
void setTarget(int red, int green, int blue);
void setColor(int R, int G, int B);
#line 15 "/Users/jml/Documents/programming/git_repositories/tdf-fa23-equilet/project_demonstrables/particle_workbench/fsr_to_ledcolor/src/fsr_to_ledcolor.ino"
const int REDPIN = D13;
const int GREENPIN = D14;
const int BLUEPIN = D15;
const int FSRPIN = A1;
const int deltime = 2;

int rValue = 0;
int gValue = 0;
int bValue = 0;
 
void setup() {
  //digital output
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  //analog input
  pinMode(FSRPIN, INPUT); 
}
 
void loop() {
  //Serial.begin(9600);
  int fsr = analogRead(FSRPIN);
  //int mapped = map(fsr, 0, 4095, 0, 255);
  //Serial.printf("fsr: %d\n", fsr);

  switch(fsr){
    case 10 ... 682:
      setTarget(255, 0, 255); // Magenta
      break;
    case 683 ... 1365:
      setTarget(0, 255, 0);   // Green
      break;
    case 1366 ... 2048:
      setTarget(0, 0, 255);   // Blue
      break;
    case 2049 ... 2731:
      setTarget(255, 255, 0); // Yellow
      break;
    case 2732 ... 3414:
      setTarget(255, 0, 0);   // Red
      break;
    case 3415 ... 4095:
      setTarget(0, 255, 255); // Aqua
      break;

    default:
      setTarget(0, 0, 0); // dimmed
      break;
  }
/*
  setTarget(255, 0, 0);   // Red
  setTarget(0, 255, 0);   // Green
  setTarget(0, 0, 255);   // Blue
  setTarget(255, 255, 0); // Yellow
  setTarget(255, 0, 255); // Magenta
  setTarget(0, 255, 255); // Aqua
  */
}
 
void setTarget(int red, int green, int blue) {
  while ( rValue != red || gValue != green || bValue != blue ) {
    if ( rValue < red ) {rValue += 1;}
    if ( rValue > red ) {rValue -= 1;}
 
    if ( gValue < green ) {gValue += 1;}
    if ( gValue > green ) {gValue -= 1;}
 
    if ( bValue < blue ) {bValue += 1;}
    if ( bValue > blue ) {bValue -= 1;}
 
    setColor(rValue, gValue, bValue);
    delay(deltime);
  }
}
 
void setColor(int R, int G, int B) {
  analogWrite(REDPIN, R);
  analogWrite(GREENPIN, G);
  analogWrite(BLUEPIN, B);
}