/*
 * Project pub_sub_var_func
 * Description:
 * Author:
 * Date:
 */

SYSTEM_THREAD(ENABLED);
//function definitions
void photoLedHandler(const char *event, const char *data);
//vars
double floatval = 0.0;

// setup() runs once, when the device is first turned on.
void setup() {
 // Particle.variable("myfloat", &floatval, DOUBLE);
  Particle.subscribe("photoLed", photoLedHandler);
  Serial.begin(9600);
}

void photoLedHandler(const char *event, const char *data){
  Serial.printf("the raw data event: %s\n", data);
  float myvalue = (float)(atof(data));
  Serial.printf("the converted value: %f\n", myvalue); 

  
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
}