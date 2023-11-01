/*
 * Project pub_sub_var_func
 * Description:
 * Author:
 * Date:
 */

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