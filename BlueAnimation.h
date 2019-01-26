#ifndef BlueAnimation_h
#define BlueAnimation_h
#include <Animation.h>

/**

*/
class BlueAnimation : public Animation {
  public:
    void reset(Adafruit_NeoPixel *strip);
    void draw(Adafruit_NeoPixel *strip);
    unsigned long waitTime = 0;
    unsigned long color = 0x008800;
  private:
};
#endif
