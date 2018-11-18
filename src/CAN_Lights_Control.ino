/*
 * Project CAN_Lights_Control
 * Description:
 * Author:
 * Date:
 */
/*
 * This is a minimal example, see extra-examples.cpp for a version
 * with more explantory documentation, example routines, how to
 * hook up your pixels and all of the pixel types that are supported.
 *
 */
/* ======================= includes ================================= */

#include "Particle.h"
#include "neopixel.h"

/* ======================= prototypes =============================== */

void colorAll(uint32_t c, uint8_t wait);
void colorWipe(uint32_t c, uint8_t wait);
void rainbow(uint8_t wait);
void rainbowCycle(uint8_t wait);
uint32_t Wheel(byte WheelPos);

/* ======================= extra-examples.cpp ======================== */

SYSTEM_MODE(AUTOMATIC);

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_COUNT 32
#define PIXEL_PIN D2
#define PIXEL_TYPE SK6812RGBW

// Parameter 1 = number of pixels in strip
//               note: for some stripes like those with the TM1829, you
//                     need to count the number of segments, i.e. the
//                     number of controllers in your stripe, not the number
//                     of individual LEDs!
// Parameter 2 = pin number (most are valid)
//               note: if not specified, D2 is selected for you.
// Parameter 3 = pixel type [ WS2812, WS2812B, WS2812B2, WS2813, WS2811,
//                            TM1803, TM1829, SK6812RGBW, WS2812B_FAST,
//                            WS2812B2_FAST ]
//               note: if not specified, WS2812B is selected for you which
//                     is the same as WS2812 or WS2813 in operation.
//               note: RGB order is automatically applied to WS2811,
//                     WS2812/WS2812B/WS2812B2/WS2813/TM1803 is GRB order.
//               note: For legacy 50us reset pulse timing on WS2812/WS2812B
//                     or WS2812B2, select WS2812B_FAST or WS2812B2_FAST
//                     respectively.  Otherwise 300us timing will be used.
//
// 800 KHz bitstream 800 KHz bitstream (most NeoPixel products
//               WS2812/WS2813 (6-pin part)/WS2812B (4-pin part)/SK6812RGBW (RGB+W) )
//
// 400 KHz bitstream (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//                   (Radio Shack Tri-Color LED Strip - TM1803 driver
//                    NOTE: RS Tri-Color LED's are grouped in sets of 3)

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
 if (false){
  chase(0,255,0,20);
 }
 if (true){
   breathe(0,0,100,10);
 }

}

void breathe (int r, int g, int b, int delay_time){
  static int i = 1;
  static bool up_down = 0;
  int new_r = 0;
  int new_g = 0;
  int new_b = 0;

  int max_i = 0;
  if ((r >= g) && (r >= b)){
    max_i = r;
  }
  else if ((g >= r) && (g >= b)) {
    max_i = g;
  }
  else{
    max_i = b;
  }

  if ((i <= max_i) && (i > 0)){
    if (up_down == 0){
      i++;
    }
    else {
      i--;
    }

    if (r >= i){
      new_r = r - i;
    }
    if (g >= i){
      new_g = g - i;
    }
    if (b >= i){
      new_b = b - i;
    }
    //Serial.printlnf("%d, %d, %d", new_r, new_g, new_b);

    for (int j = 0; j < strip.numPixels(); j++){
      strip.setPixelColor(j, strip.Color(new_g, new_r, new_b));  //(g, r, b)
    }
    delay(delay_time);
    strip.show();
  }
  else {
    up_down = !up_down;
    if (i > max_i){
      i = max_i - 1;
    }
    else{
      i = 1;
    }
  }
}

void chase (int r, int g, int b, int delay_time){
  static int i = 0;
  static int on_off = 0;

  if (i < strip.numPixels()){
    if (on_off == 0) {
      strip.setPixelColor(i, strip.Color(g, r, b));  //(g, r, b)
      i++;
    }
    else{
      strip.setPixelColor(i, strip.Color(0, 0, 0));
      i++;
    }
    delay(delay_time);
  }
  else {
      if (on_off == 0){
        on_off = 1;
      }
      else{
        on_off = 0;
      }
    i = 0;
  } 
  strip.show();
}