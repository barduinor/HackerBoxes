// This demo sketch uses the Adafruit NeoPixel Library

#include <Adafruit_NeoPixel.h>

#define PIN            5
#define NUMPIXELS      5

#define lux           20  //saturation level for NeoPixels colors

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop()
{
  BlueLEDcycle(100);
  delay(200);
  RainbowLEDcycle(100);
  delay(200);
}

void RainbowLEDcycle(int cycles)
{
  int i=0;
  while(cycles) 
  { 
    pixels.setPixelColor(i, pixels.Color(lux,0,0));
    i = (i==4) ? 0 : (i+1);
    pixels.setPixelColor(i, pixels.Color(lux,lux,0));
    i = (i==4) ? 0 : (i+1);
    pixels.setPixelColor(i, pixels.Color(0,lux,0));
    i = (i==4) ? 0 : (i+1);
    pixels.setPixelColor(i, pixels.Color(0,0,lux));
    i = (i==4) ? 0 : (i+1);
    pixels.setPixelColor(i, pixels.Color(lux,0,lux));
    i = (i==4) ? 0 : (i+1);
    i = (i==4) ? 0 : (i+1);
    pixels.show();
    delay(150);
    cycles--;
  }
}

void BlueLEDcycle(int cycles)
{
  int i=0;
  while(cycles) 
  { 
    pixels.setPixelColor(i, pixels.Color(0,0,lux*2));
    i = (i==4) ? 0 : (i+1);
    pixels.setPixelColor(i, pixels.Color(0,0,lux/2));
    i = (i==4) ? 0 : (i+1);
    pixels.setPixelColor(i, pixels.Color(0,0,lux/2));
    i = (i==4) ? 0 : (i+1);
    pixels.setPixelColor(i, pixels.Color(0,0,lux/2));
    i = (i==4) ? 0 : (i+1);
    pixels.setPixelColor(i, pixels.Color(0,0,lux/2));
    i = (i==4) ? 0 : (i+1);
    i = (i==4) ? 0 : (i+1);
    pixels.show();
    delay(150);
    cycles--;
  }
}

