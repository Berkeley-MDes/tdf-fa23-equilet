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
#line 8 "/Users/jml/Documents/programming/git_repositories/tdf-fa23-equilet/project_demonstrables/particle_workbench/accel_to_servo/src/accel_to_servo.ino"
SYSTEM_THREAD(ENABLED);

ADXL362 adxl362;
Servo serv;

const int servoPin = D1;
int pos = 0;

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
  adxl362.readXYZTData(x, y, z, temp);

  //process the data
  //map the approaximate range of the accelerometer's x value to the servo speed
  //note that values between 0 and 90 are "backwards" and values between 90 and 180 are "forwards"
  pos = map(x, -1200, 1200, 0, 180);

  //output: set the servo position
  serv.write(pos);

  //print raw data to the serial monitor
  Serial.printf("x: %d y: %d z: %d\n", x, y, z);
  Serial.printf("position: %d\n", pos);

  //wait for 1.5seconds
  delay(1500);
  //stop the servo from moving
  serv.write(90);
  //wait for 1.5seconds
  delay(1500);
}
