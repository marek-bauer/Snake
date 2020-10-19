#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include "snake.h"

#define CLK 13
#define MOSI 12
#define DC 11
#define RES 10
#define UP 4
#define DOWN 5
#define RIGHT 6
#define LEFT 7

Adafruit_PCD8544 lcd = Adafruit_PCD8544(CLK, MOSI, DC, RES);
Snake game = Snake (UP, DOWN, RIGHT, LEFT);

unsigned long last = 0;

void setup() {
  Serial.begin(9600); 
  pinMode ( UP , INPUT_PULLUP ); 
  pinMode ( DOWN , INPUT_PULLUP ); 
  pinMode ( RIGHT , INPUT_PULLUP ); 
  pinMode ( LEFT , INPUT_PULLUP ); 
  lcd.begin();
  lcd.setContrast(50);
  last = millis();
}

void loop() { 
 if( (millis() - last) > game.getTimeBetweenFrames())
 {
  last = millis();
  game.play();
  game.display(lcd);  
 }
}
