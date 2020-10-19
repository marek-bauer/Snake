#include <StandardCplusplus.h>
#include <list>
#include "snakePart.h"
class Adafruit_PCD8544;

#define D_UP 0
#define D_RIGHT 1
#define D_DOWN 2
#define D_LEFT 3

class Snake
{
  char up, down, left, right;
  bool up_pressed, down_pressed, left_pressed, right_pressed;
  const int timeStep = 40;
  std::list <SnakePart> parts;
  char lastMove;
  char x, y;
  char bX, bY;
  char mode, timer;
  public:
  Snake (char _up, char _down, char _right, char _left);
  ~Snake();
  void getInput();
  bool play();
  void checkMove();
  void getNewBonus();
  char moveDirection();
  bool isCollision (char x, char y);
  void move (char direction);
  void display (Adafruit_PCD8544 & display);
  void displayHead (Adafruit_PCD8544 & display);
  int getTimeBetweenFrames ();
};



