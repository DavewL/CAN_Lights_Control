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
#include <carloop.h>
#include "CANrec.h"
#include "CANinit.h"
#include <PixelControl.h>

/* ======================= prototypes =============================== */
int changePattern(String pattern);
int changeColor(String color);
int changeDelay(String ms_delay);

typedef enum
{
  CHASE,
  BREATHE,
  SOLID
} FlashPatterns;

typedef enum
{
  RED,
  GREEN,
  BLUE
} Colors;

FlashPatterns LED_Pattern;
Colors LED_Color;
int LED_delay = 20;

/* ======================= extra-examples.cpp ======================== */
SYSTEM_MODE(AUTOMATIC);

void setup() {
  Particle.function("pattern", changePattern);
  Particle.function("color", changeColor);
  Particle.function("delay", changeDelay);
  initCAN();
  initPixel();
}

void loop() {
  int red_val;
  int green_val;
  int blue_val;

  if (LED_Color == RED){
    red_val = 255;
    green_val = 0;
    blue_val = 0;
  }
  if (LED_Color == GREEN){
    red_val = 0;
    green_val = 255;
    blue_val = 0;
  }
  if (LED_Color == BLUE){
    red_val = 0;
    green_val = 0;
    blue_val = 255;
  }

  if (LED_Pattern == CHASE){
    chase(red_val,green_val,blue_val,LED_delay);
  }
  else if (LED_Pattern == BREATHE){
    breathe(red_val,green_val,blue_val,LED_delay);
  }
  else if (LED_Pattern == SOLID){
    solid(red_val,green_val,blue_val);
    delay(50);
 }
}

int changePattern(String pattern){
  if (pattern == "breathe") {
    LED_Pattern = BREATHE;
    return 1;
  }
  else if (pattern == "chase"){
    LED_Pattern = CHASE;
    return 1;
  }
  else if (pattern == "solid"){
    LED_Pattern = SOLID;
    return 1;
  }
  else { 
    return -1;
  }
  
}

int changeColor(String color){
  if (color == "red") {
    LED_Color = RED;
      return 1;
  }
  else if (color == "green"){
    LED_Color = GREEN;
    return 1;
}
  else if (color == "blue"){
    LED_Color = BLUE;
    return 1;
}
  else { 
  return -1;
  }
}

int changeDelay(String ms_delay){
    LED_delay = ms_delay.toInt();
    return 1;
}
