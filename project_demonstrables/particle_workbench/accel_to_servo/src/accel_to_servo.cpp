/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/jml/Documents/programming/git_repositories/tdf-fa23-equilet/project_demonstrables/particle_workbench/accel_to_servo/src/accel_to_servo.ino"
/*
 * Project accelerometer_example
 * Description:
 * Author:
 * Date:
 */
#include "ADXL362.h"


void setup();
void loop();
#line 10 "/Users/jml/Documents/programming/git_repositories/tdf-fa23-equilet/project_demonstrables/particle_workbench/accel_to_servo/src/accel_to_servo.ino"
int servoPin = D1;
int pos = 0;

ADXL362 adxl362;
Servo serv;

void setup()
{
  Serial.begin(9600);
  Serial.println("Started");
  adxl362.begin(SS);
  adxl362.beginMeasure();

  //pinMode(servoPin, OUTPUT);  
  serv.attach(servoPin);
}

void loop()
{
  int16_t x, y, z, temp;
  //float x_ms2, y_ms2, z_ms2;


  adxl362.readXYZTData(x, y, z, temp);

  pos = map(x, -1200, 1200, 0, 180);

  serv.write(pos);

  //raw data
  Serial.printf("x: %d y: %d z: %d\n", x, y, z);
  Serial.printf("position: %d\n", pos);

  delay(1500);

  serv.write(90);
  delay(1500);
}
