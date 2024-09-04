#include "Particle.h"

/*
 * Project pub_sub_var_func
 * Description:
 * Author:
 * Date:
 */


// setup() runs once, when the device is first turned on.
void setup();
void loop();

int random_value = 0;

void setup() {
Particle.variable("random_value", random_value);
}

void loop() {
    //floatval = analogRead(A0);
    random_value = random(0, 255);

  
    //Particle.publish("random_value", String(random_value), PRIVATE);
    
    //Serial.printf("the published value: %d\n", random_value);
    delay(5000);
}