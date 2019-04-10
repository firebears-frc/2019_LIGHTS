#include <Adafruit_NeoPixel.h>
#include "RocketAnimation.h"
int pixr = 0;
long blueColorr = 0;
int blueEndr = 0;
long blueStartr = 0;
long greenColorr = 100;
int greenEndr = 50;
long greenStartr = 100;
long redColorr = 200;
int redEndr = 255;
long redStartr = 200;
int cycle1r = 1;
int cycle2r = 0;
int cycle3r = 50;
int brightnessr = 12;
int brightnessStartr = 12;
int brightnessEndr = 5;
int lightNumr = random(25, 35);

void colorr () {
  greenStartr = greenColorr;
  redStartr = redColorr;
  brightnessStartr = brightnessr;
  if (cycle2r == 0) {
    redEndr = 200;
    greenEndr = 100;
    cycle2r = 1;
  }
  else {
    redEndr = 255;
    greenEndr = 30;
    cycle2r = 0;
  }
  brightnessEndr = random(50, 200);
}

void visColorr () {
  greenColorr = greenStartr + ((greenEndr - greenStartr) * cycle1r / cycle3r);
  redColorr = redStartr + ((redEndr - redStartr) * cycle1r / cycle3r);
  brightnessr = brightnessStartr + ((brightnessEndr - brightnessStartr) * cycle1r / cycle3r);
  if (cycle1r == cycle3r) {
    cycle1r = 1;
    colorr();
  }
}

void RocketAnimation::reset(Adafruit_NeoPixel *strip) {
  strip->begin();
  setTimeout(waitTimer);
}

void RocketAnimation::draw(Adafruit_NeoPixel *strip) {
  visColorr();
  strip->setPixelColor((pixr + 2), colorr);
  strip->setPixelColor((pixr + 1), colorr);
  strip->setPixelColor((pixr), redColorr, greenColorr, blueColorr);
  strip->setPixelColor((pixr - 1), 0X000000);
  strip->setPixelColor(lightNumr, 0xFFFFFF);
  cycle1r = cycle1r + 1;
  if (isTimedout()) {
    if ((pixr + 3) < lightNumr) {
      pixr = pixr + 1;
    }
    else {
      strip->setPixelColor(lightNumr, 0x000000);
      strip->setPixelColor((pixr + 2), 0x000000);
      strip->setPixelColor((pixr + 1), 0x000000);
      strip->setPixelColor((pixr), 0x000000);
      strip->setPixelColor((pixr - 1), 0X000000);
      pixr = 0;
      lightNumr = random(25, 35);
    }
  
    setTimeout(waitTimer);

  }

}

