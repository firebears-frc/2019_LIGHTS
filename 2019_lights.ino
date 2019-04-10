#include <Adafruit_NeoPixel.h>
#include <PixelStrip.h>
#include <Animation.h>
#include <Wire.h>
#include "PulseAnimation.h"
#include "RedAnimation.h"
#include "BlueAnimation.h"
#include "CargoAnimation.h"
#include "HatchPanelAnimation.h"
#include "tippinglight.h"
#include "RainbowAnimation.h"
#include "RocketAnimation.h"
#include "IseeyouAnimation.h"

const int MAX_ANIMATIONS = 9;
const int MAX_PIXELSTRIPS = 3;
const int BRIGHTNESS = 25;
const int I2C_ADDRESS = 4;
const int TIPPINGLIGHT = 0;
const int REDANIMATION = 1;
const int BLUEANIMATION = 2;
const int CARGOANIMATION = 3;
const int HATCHPANELANIMATION = 4;
const int RAINBOWANIMATION = 5;
const int PULSEANIMATION = 6;
const int ROCKETANIMATION = 7;
const int ISEEYOUANIMATION = 8;

const int ELEVATOR_STRIP = 0;
const int SUPPORT_STRIP = 1;
const int AFRAME_STRIP = 2;

PixelStrip *strip[MAX_PIXELSTRIPS];
Animation *animation[MAX_ANIMATIONS];
int wireTimeout = 0;

/**
   Change animations when I2C messages are received.
   When a message is received, the built-in LED will flash for a half second.
*/
void setup() {
  Wire.begin(I2C_ADDRESS);
  Wire.onReceive(receiveEvent);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  // set up all Animations
  animation[TIPPINGLIGHT] = new tippinglight();
  animation[REDANIMATION] = new RedAnimation();
  animation[BLUEANIMATION] = new BlueAnimation();
  animation[CARGOANIMATION] = new CargoAnimation();
  animation[HATCHPANELANIMATION] = new HatchPanelAnimation();
  animation[RAINBOWANIMATION] = new RainbowAnimation();
  animation[PULSEANIMATION] = new PulseAnimation();
  animation[ROCKETANIMATION] = new RocketAnimation();
  animation[ISEEYOUANIMATION] = new IseeyouAnimation();
  // set up all PixeLStrips

  strip[ELEVATOR_STRIP] = new PixelStrip(121, 1, NEO_GRB);
  strip[SUPPORT_STRIP] = new PixelStrip(100, 3, NEO_GRB);
  strip[AFRAME_STRIP] = new PixelStrip(108, 4, NEO_GRB);
  for (int s = 0; s < MAX_PIXELSTRIPS; s++) {
    strip[s]->setup();
    strip[s]->setAnimation(animation[REDANIMATION]);
    strip[s]->setBrightness(BRIGHTNESS);


  }

}

void loop() {
  for (int s = 0; s < MAX_PIXELSTRIPS; s++) {
    strip[s]->draw();
    strip[s]->show();
  }
  delay(10);
  if (wireTimeout > 0 && millis() > wireTimeout)  {
    digitalWrite(LED_BUILTIN, LOW);
    wireTimeout = 0;
  }
}

/**
   Expects to receive two characters.
   The first character specifies the pixel strip number.
   The second character sets the animation number on that strip.
*/
void receiveEvent(int howMany) {
  while (Wire.available() > 0) {
    int s = Wire.read() - '0';
    int a = Wire.read() - '0';
    if (a >= 0 && a < MAX_ANIMATIONS) {
      strip[s]->setAnimation(animation[a]);
    } else {
      strip[s]->setAnimation(0);
    }
    digitalWrite(LED_BUILTIN, HIGH);
    wireTimeout = millis() + 500;
   /* Serial.print("receiveEvent(");
    Serial.print(s); Serial.print(",");
    Serial.print(a); Serial.println(")");*/
  }
}
