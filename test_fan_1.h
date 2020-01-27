#include "esphome.h"
using namespace esphome;

//#define PIN_1 23 //Low
//#define PIN_2 21 //Med
//#define PIN_3 19 //High


class CustomFanOutput : public Component, public FloatOutput {
  public:
    void write_state(float state) override {
      if (state < 0.3) {
        // OFF
        digitalWrite(23, LOW);
        digitalWrite(21, LOW);
        digitalWrite(19, LOW);
      } else if (state < 0.6) {
        // low speed
        digitalWrite(23, HIGH);
        digitalWrite(21, LOW);
        digitalWrite(19, LOW);
      } else if (state < 0.9) {
        // medium speed
        digitalWrite(23, LOW);
        digitalWrite(21, HIGH);
        digitalWrite(19, LOW);
      } else {
        // high speed
        digitalWrite(23, LOW);
        digitalWrite(21, LOW);
        digitalWrite(19, HIGH);
      }
    }
};