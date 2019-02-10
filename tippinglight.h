#ifndef tippinglight_h
#define tippinglight_h
#include <Animation.h>

/**

*/
class tippinglight : public Animation {
  public:
    void reset(Adafruit_NeoPixel *strip);
    void draw(Adafruit_NeoPixel *strip);
    unsigned long waitTime = 250;
    unsigned long PixelColour1 = 0xff0000;
  private:
};
#endif
