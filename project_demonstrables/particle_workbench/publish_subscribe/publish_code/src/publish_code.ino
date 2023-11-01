/*
 * Project pub_sub_var_func
 * Description:
 * Author:
 * Date:
 */

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