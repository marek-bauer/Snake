#include "snakePart.h"
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include "Arduino.h"

void SnakePart::tailTransform()
{
  type = type % 4 + 16;
}

void SnakePart::display(Adafruit_PCD8544 & display)
{
  switch (type)
  {
  case 5:
  case 15:
    display.drawPixel(x*4 + 2, y*4 + 11, BLACK); //RR
    display.drawPixel(x*4 + 2, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 3, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 5, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 5, y*4 + 11, BLACK);
  break;
  case 0:
  case 10:
    display.drawPixel(x*4 + 3, y*4 + 10, BLACK);//UU
    display.drawPixel(x*4 + 3, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 3, y*4 + 13, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 10, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 13, BLACK);
  break;
  case 9:
  case 12:
    display.drawPixel(x*4 + 3, y*4 + 10, BLACK);//UR
    display.drawPixel(x*4 + 4, y*4 + 10, BLACK);
    display.drawPixel(x*4 + 3, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 5, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 5, y*4 + 12, BLACK);
  break;
  case 1:
  case 14:
    display.drawPixel(x*4 + 4, y*4 + 11, BLACK);//RD
    display.drawPixel(x*4 + 5, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 3, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 5, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 3, y*4 + 13, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 13, BLACK);
  break;
  case 3:
  case 6:
    display.drawPixel(x*4 + 2, y*4 + 11, BLACK);//DL
    display.drawPixel(x*4 + 3, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 2, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 3, y*4 + 13, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 13, BLACK);
  break;
  case 4:
  case 11:
    display.drawPixel(x*4 + 3, y*4 + 10, BLACK);//LU
    display.drawPixel(x*4 + 4, y*4 + 10, BLACK);
    display.drawPixel(x*4 + 2, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 2, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 3, y*4 + 12, BLACK);
  break;
  case 16:
    display.drawPixel(x*4 + 3, y*4 + 10, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 10, BLACK);
    display.drawPixel(x*4 + 3, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 3, y*4 + 12, BLACK);
  break;
  case 17:
    display.drawPixel(x*4 + 4, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 5, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 3, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 5, y*4 + 12, BLACK);
  break;
  case 18:
    display.drawPixel(x*4 + 4, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 3, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 3, y*4 + 13, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 13, BLACK);
  break;
  case 19:
    display.drawPixel(x*4 + 2, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 3, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 2, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 3, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 12, BLACK);
  break;
  }
}

