#ifndef CargoAnimation_h
#define CargoAnimation_h
#include <Animation.h>

/**

*/
class CargoAnimation : public Animation {
  public:
    void reset(Adafruit_NeoPixel *strip);
    void draw(Adafruit_NeoPixel *strip);
    unsigned long waitTime = 1;
    unsigned long color = 0x558800;
  private:
};
#endif
