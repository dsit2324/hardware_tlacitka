#include <Arduino.h>
#include <Bounce2.h>
#define led_count 3
#define button_count 3
int count = 0;

int leds[led_count] = {2, 3, 4};
int button_pins[button_count] = {6, 7, 8};
Bounce2::Button button[button_count] = {Bounce2::Button()};

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < led_count; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  for (int i = 0; i < button_count; i++)
  {
    button[i].attach(button_pins[i], INPUT);
    button[i].interval(5);
  }
}

void loop()
{
  if (button[0].pressed())
  {
    count++;
  }
  if (button[1].pressed())
  {
    count = 0;
  }
  if (button[2].pressed())
  {
    count--;
  }
  Serial.println(count);
}
