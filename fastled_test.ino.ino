#include <FastLED.h>
#define NUM_LEDS 60
#define DATA_PIN 6

int sensor_pin = 7;
int calibration_time = 30;
boolean hasItRun = false;

CRGB leds[NUM_LEDS]; // memory for storing and manipulating data


void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS); // strand of leds at pin 6, using led array with 60 leds
  
  Serial.begin(9600);
  pinMode(sensor_pin, INPUT);
  digitalWrite(sensor_pin, LOW);

  // calibrate the sensor
  Serial.print("Calibrating sensor...");
  for(int i = 0; i < calibration_time; i++) {
    Serial.print("~");
    delay(100);
  }
  Serial.println("Done calibrating");
  Serial.println("Sensor is active!");
}

void loop() {

  if(digitalRead(sensor_pin) == HIGH) {
    Serial.println("-----------Motion detected-----------");
    for (int i = 0; i <= 59; i++) {
      leds[i] = CRGB (0, 0, 255);
      FastLED.show();
      delay(10);
    }
    for (int i = 59; i >= 0; i--) {
      leds[i] = CRGB::HTMLColorCode::DeepPink;
      FastLED.show();
      delay(10);
    }
    hasItRun = false;
  }
  if(digitalRead(sensor_pin) == LOW && !hasItRun) {
    hasItRun = true;
    for (int i = 0; i <= 59; i++) {
      leds[i] = CRGB::Black;
      FastLED.show();
      delay(10);
    }
  }
  Serial.println("loop");
}
// https://github.com/FastLED/FastLED/wiki/Basic-usage
