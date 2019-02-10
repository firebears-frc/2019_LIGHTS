
#include <Adafruit_NeoPixel.h>
#include "tippinglight.h"

long colour = 0;

void tippinglight::reset(Adafruit_NeoPixel *strip) {
  strip->begin();
  setTimeout(waitTime);
}

void tippinglight::draw(Adafruit_NeoPixel *strip) {
  if (isTimedout()) {
    for (int i = 1; i < strip->numPixels(); i++) {
      strip->setPixelColor (i, colour);
    }
    strip->show();

    if (colour == 0) {
      colour = PixelColour1;
    }
    else {
      colour = 0;
    }
    setTimeout(waitTime);
  }
}



