#ifndef HatchPanelAnimation_h
#define HatchPanelAnimation_h
#include <Animation.h>

class HatchPanelAnimation : public Animation {
  public:
    void reset(Adafruit_NeoPixel *strip);
    void draw(Adafruit_NeoPixel *strip);
    unsigned long waitTime = 1;
    unsigned long color = 0x008800;
  private:
};
#endif
