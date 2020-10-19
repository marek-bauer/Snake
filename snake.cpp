#include "snake.h"
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include "Arduino.h"

using namespace std;

Snake::Snake (char _up, char _down, char _right, char _left)
{
  up = _up;
  down = _down;
  right = _right;
  left = _left;
  up_pressed = false;
  left_pressed = false;
  down_pressed = false;
  right_pressed = false;
  
  parts.push_back(SnakePart(5,5,D_RIGHT*4+D_RIGHT));
  parts.push_back(SnakePart(4,5,D_RIGHT*4+D_RIGHT));
  parts.push_back(SnakePart(3,5,D_RIGHT*4+D_RIGHT));
  lastMove = D_RIGHT;
  x = 6;
  y = 5;  
  mode = 1;
  timer = 0;
  getNewBonus();
}

Snake::~Snake()
{  
}

int Snake::getTimeBetweenFrames ()
{
  return timeStep;
}

void Snake::getInput()
{
   if (digitalRead (up) == LOW) up_pressed = true;
   if (digitalRead (down) == LOW) down_pressed = true;
   if (digitalRead (left) == LOW) left_pressed = true;
   if (digitalRead (right) == LOW) right_pressed = true;
}

char Snake::moveDirection()
{
  char buttonPressed = 0;
  char direction;
  if (up_pressed == true && lastMove != D_DOWN)
  {
    direction = D_UP;
    buttonPressed++;
  }
  if (left_pressed == true && lastMove != D_RIGHT)
  {
    direction = D_LEFT;
    buttonPressed++;
  }
  if (down_pressed == true && lastMove != D_UP)
  {
    direction = D_DOWN;
    buttonPressed++;
  }
  if (right_pressed == true && lastMove != D_LEFT)
  {
    direction = D_RIGHT;
    buttonPressed++;
  }
  up_pressed = false;
  left_pressed = false;
  down_pressed = false;
  right_pressed = false;
  if (buttonPressed == 1) return direction;
  else return lastMove;
}

void Snake::move (char direction)
{
  parts.push_front( SnakePart(x, y, lastMove*4+direction) );
  if ( direction == D_UP) y--;
  else if ( direction == D_DOWN) y++;
  else if ( direction == D_LEFT) x--;
  else x++;
  lastMove = direction;
  checkMove();
  parts.pop_back();
  (*(parts.rbegin())).tailTransform();
}

void Snake::checkMove()
{
  if (isCollision(x, y)) mode = 2;
  else if (x == bX && y == bY)
  {
    parts.push_back(SnakePart(-10, -10, -1));
    getNewBonus();
  }
}

bool Snake::play()
{
  getInput();
  if (mode == 1)
  {
    if (timer >= 8)
    {
      move( moveDirection() );
      timer = 0;
    }
    else timer++;
  }
}

void Snake::getNewBonus()
{
  do
  {
    bX = rand()%19;
    bY = rand()%8;
  }
  while (isCollision (bX, bY) || (x == bX && y == bY) );
}

bool Snake::isCollision (char xx, char yy)
{
  if (xx > 19 || xx < 0 || yy > 8 || yy < 0) return true;
  for (list<SnakePart>::iterator it = parts.begin(); it != parts.end(); it++)
  {
    if ((*it).getX() == xx && (*it).getY() == yy) return true;
  }
  return false;
}

void Snake::display (Adafruit_PCD8544 & display)
{
  display.clearDisplay();
  if (mode == 1 || mode == 2)
  {
    display.setCursor(0, 0); 
    display.print(parts.size()-3);    
    display.drawRect(0, 8, 84, 40, 1);
    display.drawRect(1, 9, 82, 38, 1);
    display.drawRect(bX*4+2, bY*4+10, 4, 4, 1);
    for (list<SnakePart>::iterator it = parts.begin(); it != parts.end(); it++)
    {
      (*it).display(display);
    }
    displayHead (display);
  }
  if (mode == 2)
  {
    display.drawRect(14, 12, 57, 11, 1);
    display.fillRect(15, 13, 55, 9, 0);
    display.setCursor(16, 14);    
    display.print("GAME OVER");
  }
  display.display();
}

void Snake::displayHead (Adafruit_PCD8544 & display)
{
  if (lastMove == D_LEFT)
  {
    display.drawPixel(x*4 + 3, y*4 + 10, BLACK);
    display.drawPixel(x*4 + 2, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 5, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 2, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 3, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 5, y*4 + 12, BLACK);
  }
  else if (lastMove == D_RIGHT)
  {
    display.drawPixel(x*4 + 4, y*4 + 10, BLACK);
    display.drawPixel(x*4 + 2, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 3, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 5, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 2, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 3, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 5, y*4 + 12, BLACK);
  }
  else if (lastMove == D_UP)
  {
    display.drawPixel(x*4 + 3, y*4 + 10, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 10, BLACK);
    display.drawPixel(x*4 + 3, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 2, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 3, y*4 + 13, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 13, BLACK);
  }
  else if (lastMove == D_DOWN)
  {
    display.drawPixel(x*4 + 3, y*4 + 10, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 10, BLACK);
    display.drawPixel(x*4 + 2, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 11, BLACK);
    display.drawPixel(x*4 + 3, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 12, BLACK);
    display.drawPixel(x*4 + 3, y*4 + 13, BLACK);
    display.drawPixel(x*4 + 4, y*4 + 13, BLACK);
  }
}

