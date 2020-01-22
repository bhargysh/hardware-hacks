#include <FastLED.h>
#define NUM_LEDS 60
#define DATA_PIN 6

int sensor_pin = 7;
int calibration_time = 30;

CRGB leds[NUM_LEDS]; // memory for storing and manipulating data


void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS); // strand of leds at pin 6, using led array with 60 leds
  
  Serial.begin(9600);
  pinMode(sensor_pin, INPUT);
  digitalWrite(sensor_pin, LOW);

}

void loop() {

  if(digitalRead(sensor_pin) == HIGH) {
    Serial.println("-----------Sound detected-----------");
    for (int i = 0; i <= 59; i++) {
      leds[i] = CRGB (0, 0, 255);
      FastLED.show();
      delay(40);
    }
    for (int i = 59; i >= 0; i--) {
      leds[i] = CRGB::Red;
      FastLED.show();
      delay(40);
    }
    delay(50);
  }
  if(digitalRead(sensor_pin) == LOW) {
    Serial.println("xxxxxxxx No Sound detected xxxxxxxx");
    for (int i = 0; i <= 59; i++) {
      leds[i] = CRGB::Black;
      FastLED.show();
      delay(50);
    }
  }

}
// https://github.com/FastLED/FastLED/wiki/Basic-usage
