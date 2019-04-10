#include <Adafruit_NeoPixel.h>
#include "CargoAnimation.h"

int pixelState1 = 0;

int Add_Subbtract1 = 1;
int currentPixel1 = 1;
long PixelColour4 = (0xff3000);
long PixelColour5 = (0xff3000);
long PixelColour6 = (0xff3000);

void CargoAnimation::reset(Adafruit_NeoPixel *strip) {
  strip->begin();
  setTimeout(waitTime);
}

void CargoAnimation::draw(Adafruit_NeoPixel *strip) {
  if (isTimedout()) {





    strip->clear();
    currentPixel1 = currentPixel1 + Add_Subbtract1;

    for (int i = 0; i < (strip->numPixels()); i ++) {

      strip->setPixelColor (i, 0x000000);

      strip->setPixelColor(currentPixel1,     PixelColour6);
      strip->setPixelColor(currentPixel1 + 2, PixelColour5);
      strip->setPixelColor(currentPixel1 + 3, PixelColour5);
      strip->setPixelColor(currentPixel1 + 4, PixelColour5);
      strip->setPixelColor(currentPixel1 + 5, PixelColour5);
      strip->setPixelColor(currentPixel1 + 6, PixelColour4);
      strip->setPixelColor(currentPixel1 - 6, PixelColour4);
      strip->setPixelColor(currentPixel1 - 5, PixelColour5);
      strip->setPixelColor(currentPixel1 - 4, PixelColour5);
      strip->setPixelColor(currentPixel1 - 3, PixelColour5);
      strip->setPixelColor(currentPixel1 - 2, PixelColour5);
      strip->setPixelColor(currentPixel1 - 7, PixelColour4);
      strip->setPixelColor(currentPixel1 - 8, PixelColour4);
      strip->setPixelColor(currentPixel1 - 9, PixelColour4);
      strip->setPixelColor(currentPixel1 - 10, PixelColour4);
      strip->setPixelColor(currentPixel1 + 7, PixelColour4);
      strip->setPixelColor(currentPixel1 + 8, PixelColour4);
      strip->setPixelColor(currentPixel1 + 9, PixelColour4);
      strip->setPixelColor(currentPixel1 + 10, PixelColour4);
      strip->setPixelColor(currentPixel1 + 1, PixelColour6);
      strip->setPixelColor(currentPixel1 - 1, PixelColour6);
      strip->show();
      //strip->isTimeout(1);

    }
  }
  if (currentPixel1 == strip->numPixels()) {
    Add_Subbtract1 = - 1;

  }
  if (currentPixel1 == -5) {
    Add_Subbtract1 = + 1;
  }
}

