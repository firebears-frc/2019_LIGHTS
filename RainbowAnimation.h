#ifndef RainbowAnimation_h
#define RainbowAnimation_h
#include <Animation.h>

/**

*/
class RainbowAnimation : public Animation {
  public:
    void reset(Adafruit_NeoPixel *strip);
    void draw(Adafruit_NeoPixel *strip);
    unsigned long waitTimec = 0;
    unsigned long colorc = 0x008800;
  private:
};
#endif
