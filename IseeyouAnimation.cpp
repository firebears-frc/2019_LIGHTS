
#include <Adafruit_NeoPixel.h>
#include "IseeyouAnimation.h"

long colour7 = 0;

void IseeyouAnimation::reset(Adafruit_NeoPixel *strip) {
  strip->begin();

}

void IseeyouAnimation::draw(Adafruit_NeoPixel *strip) {
  if (isTimedout()) {
    for (int i = 0; i < strip->numPixels(); i++) {
      strip->setPixelColor (i, colour7);
    }
    delay(250);


    if (colour7 == 0) {
      colour7 = PixelColour10;
    }

    else {
      colour7 = 0x000000;
    }
    strip->show();


  }
}

