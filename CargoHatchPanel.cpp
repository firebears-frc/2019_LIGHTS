#include <Adafruit_NeoPixel.h>
#include "CargoHatchPanel.h"

int pixelState = 0;

int Add_Subbtract = 1;
int currentPixel = 1;
long PixelColour1 = (0xf0f000);
long PixelColour2 = (0xffffff);
long PixelColour3 = (0xf0f000);

void CargoHatchPanel::reset(Adafruit_NeoPixel *strip) {
  strip->begin();
  setTimeout(waitTime);
}

void CargoHatchPanel::draw(Adafruit_NeoPixel *strip) {
  if (isTimedout()) {
    



  
    //strip->clear();
    currentPixel = currentPixel + Add_Subbtract;

    for (int i = 0; i < 36; i ++) {

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
  
    /*strip->setPixelColor(0, (pixelState%3==0) ? 0x008800 : 0x000000);
    pixelState = (pixelState + 1) % 3;
    for (int pixelNum = 0; pixelNum < strip->numPixels(); pixelNum++) {
      unsigned long pixelColor = ((pixelNum + pixelState) % 3 == 0) ? color : 0x000000;
      strip->setPixelColor(pixelNum, pixelColor);
    }
    setTimeout(waitTime);
  }
}

#include <Adafruit_NeoPixel.h>
#include <PixelStrip.h>
#include <Animation.h>

const int PIN = 7;
const int NUM_PIXELS = 36;
const int BRIGHTNESS = 50;
int Add_Subbtract = 1;
int currentPixel = 1;
long PixelColour1 = (0x8844ff);
long PixelColour2 = (0xff00ff);
long PixelColour3 = (0xFF0000);


PixelStrip *strip = new PixelStrip(NUM_PIXELS, PIN, NEO_GRB);

void setup() {
  strip->setup();
  strip->setTimeout(10);
  strip->setBrightness(BRIGHTNESS);
  
}

void loop() {*/




