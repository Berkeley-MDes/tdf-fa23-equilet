// button testing sketch. 

int button = D10; // button leg is connected to D10
int buttonReading;      // the analog reading from the button resistor divider
 
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  pinMode(button, INPUT_PULLDOWN); // sets pin as input
}
 
void loop(void) {
  buttonReading = digitalRead(button);
  Serial.print("Dig reading = ");
  Serial.println(buttonReading);
 
  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map!

  String buttonVal = "{ digitalread: " + String(buttonReading) + " }";
  Particle.publish("buttonval", buttonVal);
  delay(1000);
}