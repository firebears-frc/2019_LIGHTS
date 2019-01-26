#ifndef RedAnimation_h
#define RedAnimation_h
#include <Animation.h>

/**

*/
class RedAnimation : public Animation {
  public:
    void reset(Adafruit_NeoPixel *strip);
    void draw(Adafruit_NeoPixel *strip);
    unsigned long waitTime = 0;
    unsigned long color = 0x008800;
  private:
};
#endif
