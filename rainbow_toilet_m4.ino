#include "Arduino.h"
#include <Adafruit_NeoPixel.h>


/******************************************************************************
 * Defines
 */

#define NR_PIXELS (8u)

/******************************************************************************
 * Globals
 */

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NR_PIXELS, 2);
Adafruit_NeoPixel onb = Adafruit_NeoPixel(1,40);

uint32_t rgbc = 0;

void setup()
{
  Serial.begin(115200);
  delay(1000);

  strip.begin();
  strip.clear();
  onb.begin();
  onb.clear();

}


void loop()
{
  delay(1000);
  Serial.println("Red!");
  rgbc = strip.gamma32(strip.ColorHSV(0, 250, 100));
  strip.fill(rgbc,0,0);
  onb.fill(rgbc,0,0);
  Serial.print(rgbc);Serial.print("\t");Serial.println(strip.getBrightness());

  strip.show();
  onb.show();

  delay(1000);
  Serial.println("Bluish!");
  rgbc = strip.gamma32(strip.ColorHSV(30000, 250, 100));
  strip.fill(rgbc, 0,0);
  onb.fill(rgbc, 0,0);
  Serial.print(rgbc);Serial.print("\t");Serial.println(onb.getBrightness());
  strip.show();
  onb.show();
}
