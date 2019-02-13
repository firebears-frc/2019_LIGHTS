#ifndef RocketAnimation_h
#define RocketAnimation_h
#include <Animation.h>

/**

*/
class RocketAnimation : public Animation {
  public:
    void reset(Adafruit_NeoPixel *strip);
    void draw(Adafruit_NeoPixel *strip);
    unsigned long waitTimer = 50;
    unsigned long colorr = 0x444444;
  private:
};
#endif
