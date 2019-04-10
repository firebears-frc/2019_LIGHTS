#include <Adafruit_NeoPixel.h>
#include "RainbowAnimation.h"

long bluecolorc = 0;
long blueEndc = 0;
long blueStartc = 0;
long greencolorc = 0;
long greenEndc = 0;
long greenStartc = 0;
long redcolorc = 0;
long redEndc = 0;
long redStartc = 0;
int cycle1c = 1;
int cycle3c = 10;
int brightnessc = 12;
int brightnessStartc = 12;
int brightnessEndc = 5;
int pixelNumc = 0;
int multc = 1;

void colorc () {
  greenStartc = greencolorc;
  blueStartc = bluecolorc;
  redStartc = redcolorc;
  brightnessStartc = brightnessc;
  greenEndc = random(255);
  redEndc = random(255);
  blueEndc = random(255);
  brightnessEndc = random(50, 200);
}

void viscolorc (int numpixel) {
  greencolorc = greenStartc + ((greenEndc - greenStartc) * cycle1c / cycle3c);
  bluecolorc = blueStartc + ((blueEndc - blueStartc) * cycle1c / cycle3c);
  redcolorc = redStartc + ((redEndc - redStartc) * cycle1c / cycle3c);
  brightnessc = brightnessStartc + ((brightnessEndc - brightnessStartc) * cycle1c / cycle3c);
  if (cycle1c == cycle3c) {
    cycle1c = 1;
    colorc();
    if (pixelNumc < numpixel) {
      pixelNumc = pixelNumc + 1;
    }
    else {
      pixelNumc = 1;
    }
  }
}


void RainbowAnimation::reset(Adafruit_NeoPixel *strip) {
  strip->begin();
  setTimeout(waitTimec);
}

void RainbowAnimation::draw(Adafruit_NeoPixel *strip) {
  if (isTimedout()) {
    cycle1c = cycle1c + 1;
    strip->setPixelColor((3*multc - (pixelNumc + 1)), redcolorc, greencolorc, bluecolorc);
    strip->setBrightness(brightnessc);
    viscolorc(4);
    setTimeout(waitTimec);
    multc = multc + 1;
  }
  if (multc > 42){
    multc = 0;
  }
}
