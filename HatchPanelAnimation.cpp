#include <Adafruit_NeoPixel.h>
#include "HatchPanelAnimation.h"

int pixelState = 0;

int Add_Subbtract = 1;
int currentPixel = 1;
long PixelColour1 = (0xf0f000);
long PixelColour2 = (0xffffff);
long PixelColour3 = (0xf0f000);

void HatchPanelAnimation::reset(Adafruit_NeoPixel *strip) {
  strip->begin();
  setTimeout(waitTime);
}

void HatchPanelAnimation::draw(Adafruit_NeoPixel *strip) {
  if (isTimedout()) {
    



  
    //strip->clear();
    currentPixel = currentPixel + Add_Subbtract;

    for (int i = 0; i < (strip->numPixels()); i ++) {

      strip->setPixelColor (i, 0x555555);

      strip->setPixelColor(currentPixel,     PixelColour3);
      strip->setPixelColor(currentPixel + 2, PixelColour2);
      strip->setPixelColor(currentPixel + 3, PixelColour2);
      strip->setPixelColor(currentPixel + 4, PixelColour2);
      strip->setPixelColor(currentPixel + 5, PixelColour2);
      strip->setPixelColor(currentPixel + 6, PixelColour1);
      strip->setPixelColor(currentPixel - 6, PixelColour1);
      strip->setPixelColor(currentPixel - 5, PixelColour2);
      strip->setPixelColor(currentPixel - 4, PixelColour2);
      strip->setPixelColor(currentPixel - 3, PixelColour2);
      strip->setPixelColor(currentPixel - 2, PixelColour2);
      strip->setPixelColor(currentPixel - 7, PixelColour1);
      strip->setPixelColor(currentPixel - 8, PixelColour1);
      strip->setPixelColor(currentPixel - 9, PixelColour1);
      strip->setPixelColor(currentPixel - 10,PixelColour1);
      strip->setPixelColor(currentPixel + 7, PixelColour1);
      strip->setPixelColor(currentPixel + 8, PixelColour1);
      strip->setPixelColor(currentPixel + 9, PixelColour1);
      strip->setPixelColor(currentPixel + 10,PixelColour1);
      strip->setPixelColor(currentPixel + 1, PixelColour3);
      strip->setPixelColor(currentPixel - 1, PixelColour3);
      strip->show();
      //strip->isTimeout(1);
       
    }
  }
  if (currentPixel == strip->numPixels()) {
    Add_Subbtract = - 1;

  }
  if (currentPixel == -15) {
    Add_Subbtract = + 1;
  }

}
  
    




