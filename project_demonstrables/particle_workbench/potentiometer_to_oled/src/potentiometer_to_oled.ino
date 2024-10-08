/*
 * Project potentiometer_to_oled
 * Description: read the value of a potentiometer and display it on an OLED screen
 * Author: Jeff Lubow
 * Date: 10/01/23
 */

#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"
#include "splash.h" //this is our custom header containing the splash screen bitmap

SYSTEM_THREAD(ENABLED);

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define SCREEN_ADDRESS 0x3D // OLED display address (for the 128x64)
#define POT_PIN A0 // Potentiometer is connected to A0

// Instantiate SSD1306 driver display object via I2C interface; note that no reset is used
Adafruit_SSD1306 disp(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void draw_splash(void); //our splash screen function
float draw_potval(float val); //our potentiometer value display function
void draw_bitmap(const unsigned char* bitmap, int x, int y, int w, int h, int color);
int potval = 0;

void setup(){
  Serial.begin(9600);
  delay(8); 
  // if initialization fails print failure to Serial, and enter an infinite loop
  bool test_access = disp.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);

  if(!test_access){
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }else{
    Serial.println("SSD1306 allocation success");
    draw_splash();
    delay(2000);
  }
}

void loop(){
  int potval = map(analogRead(POT_PIN), 4095, 0, 0, 1000);
  float potval_float = (float)potval / 1000.0;

  Serial.printf("potval: %f\n", potval_float);
  draw_potval(potval_float);
  delay(200); // Pause for 1/10 second
}

void draw_splash(void){
  disp.clearDisplay();
  disp.drawBitmap(0, 0, epd_pirate_small, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
  disp.display();
}

float draw_potval(float val){
  disp.clearDisplay();
  disp.setTextSize(1);
  disp.setTextColor(WHITE);
  disp.setCursor(0,0);
  disp.printf("potentiometer value: %f", val);
  disp.display();
  return val;
}

void draw_bitmap(const unsigned char* bitmap, int x, int y, int w, int h, int color) {
  int byte_width = (w + 7) / 8;
  for (int j = 0; j < h; j++) {
    for (int i = 0; i < w; i++ ) {
      if (pgm_read_byte(bitmap + j * byte_width + i / 8) & (128 >> (i & 7))) {
        disp.drawPixel(x + i, y + j, color);
      }
    }
  }
}
