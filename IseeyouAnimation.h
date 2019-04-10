#ifndef IseeyouAnimation_h
#define IseeyouAnimation_h
#include <Animation.h>


class IseeyouAnimation : public Animation {
  public:
    void reset(Adafruit_NeoPixel *strip);
    void draw(Adafruit_NeoPixel *strip);
    unsigned long waitTime = 250;
    unsigned long PixelColour10 = 0x00ff00;
  private:
};
#endif
