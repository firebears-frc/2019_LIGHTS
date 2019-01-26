#include <Adafruit_NeoPixel.h>
#include "BlueAnimation.h"

long blueColorb = 255;
long blueEndb = 255;
long blueStartb = 255;
long greenColorb = 0;
long greenEndb = 0;
long greenStartb = 0;
long redColorb = 0;
long redEndb = 0;
long redStartb = 0;
int cycle1b = 1;
int cycle3b = 10;
int brightnessb = 12;
int brightnessStartb = 12;
int brightnessEndb = 5;
int pixelNumb = 0;
int multb = 1;
boolean startb = true;


  
void colorb () {
  greenStartb = greenColorb;
  blueStartb = blueColorb;
  redStartb = redColorb;
  brightnessStartb = brightnessb;
  blueEndb = random(200, 255);
  greenEndb = random(80, 190);
  redEndb = random(0, 100);
  brightnessEndb = random(150, 200);
}

void visColorb (int numPixel) {
  greenColorb = greenStartb + ((greenEndb - greenStartb) * cycle1b / cycle3b);
  blueColorb = blueStartb + ((blueEndb - blueStartb) * cycle1b / cycle3b);
  redColorb = redStartb + ((redEndb - redStartb) * cycle1b / cycle3b);
  brightnessb = brightnessStartb + ((brightnessEndb - brightnessStartb) * cycle1b / cycle3b);
  if (cycle1b == cycle3b) {
    cycle1b = 1;
    colorb();
    if (pixelNumb < numPixel) {
      pixelNumb = pixelNumb + 1;
    }
    else {
      pixelNumb = 1;
    }
  }
}

void BlueAnimation::reset(Adafruit_NeoPixel *strip) {
  strip->begin();
  setTimeout(waitTime);
  startb = true;
}

void BlueAnimation::draw(Adafruit_NeoPixel *strip) {
  if (startb == true) {
  for (int pix = 0; pix < strip->numPixels(); pix ++){
    strip->setPixelColor(pix, 0, 0, 255);
    }
    startb = false;
  }
  if (isTimedout()) {
    cycle1b = cycle1b + 1;
    strip->setPixelColor((3*multb - (pixelNumb + 1)), redColorb, greenColorb, blueColorb);
    strip->setPixelColor((8*multb - (pixelNumb + 1)), 0x000000);
    strip->setBrightness(brightnessb);
    visColorb(3);
    setTimeout(waitTime);
    multb = multb + 1;
  }
  if (multb > 67){
    multb = 0;
  }
}
