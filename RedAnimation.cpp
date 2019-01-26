#include <Adafruit_NeoPixel.h>
#include "RedAnimation.h"

long blueColor = 0;
long blueEnd = 0;
long blueStart = 0;
long greenColor = 0;
long greenEnd = 0;
long greenStart = 0;
long redColor = 200;
long redEnd = 200;
long redStart = 255;
int cycle1 = 1;
int cycle3 = 10;
int brightness = 12;
int brightnessStart = 12;
int brightnessEnd = 5;
int pixelNum = 0;
int mult = 1;
boolean start = true;
void color () {
  greenStart = greenColor;
  blueStart = blueColor;
  redStart = redColor;
  brightnessStart = brightness;
  redEnd = random(200, 255);
  greenEnd = random(50, 100);
  blueEnd = random(0, 30);
  brightnessEnd = random(150, 200);
}

void visColor (int numPixel) {
  greenColor = greenStart + ((greenEnd - greenStart) * cycle1 / cycle3);
  blueColor = blueStart + ((blueEnd - blueStart) * cycle1 / cycle3);
  redColor = redStart + ((redEnd - redStart) * cycle1 / cycle3);
  brightness = brightnessStart + ((brightnessEnd - brightnessStart) * cycle1 / cycle3);
  if (cycle1 == cycle3) {
    cycle1 = 1;
    color();
    if (pixelNum < numPixel) {
      pixelNum = pixelNum + 1;
    }
    else {
      pixelNum = 1;
    }
  }
}

void RedAnimation::reset(Adafruit_NeoPixel *strip) {
  strip->begin();
  setTimeout(waitTime);
  start = true;
}

void RedAnimation::draw(Adafruit_NeoPixel *strip) {
  if (start == true) {
    for (int pix = 0; pix < strip->numPixels(); pix ++) {
      strip->setPixelColor(pix, 255, 0, 0);
    }
    start = false;
  }
  if (isTimedout()) {
    cycle1 = cycle1 + 1;
    strip->setPixelColor((3 * mult - (pixelNum + 1)), redColor, greenColor, blueColor);
    strip->setBrightness(brightness);
    strip->setPixelColor((8*mult - (pixelNum + 1)), 0x000000);
    visColor(3);
    setTimeout(waitTime);
    mult = mult + 1;
  }
  if (mult > 67) {
    mult = 0;
  }
}
