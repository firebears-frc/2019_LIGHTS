
#include <Adafruit_NeoPixel.h>
#include "tippinglight.h"

long colour9 = 0;

void tippinglight::reset(Adafruit_NeoPixel *strip) {
  strip->begin();

}

void tippinglight::draw(Adafruit_NeoPixel *strip) {
  if (isTimedout()) {
    for (int i = 0; i < strip->numPixels(); i++) {
      strip->setPixelColor (i, colour9);
    }
    delay(waitTime);
    strip->show();

    if (colour9 == 0) {
      colour9 = PixelColour8;
    }
    else {
      colour9 = 0;
    }

  }
}



