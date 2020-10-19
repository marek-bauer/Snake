/* 
 * 0 - UP
 * 1 - RIGHT
 * 2 - DOWN
 * 3 - LEFT
 */
class Adafruit_PCD8544;

class SnakePart
{
  char x, y, type;
  public: 
  SnakePart ( char _x, char _y, char _type )
  {
   x = _x;
   y = _y;
   type = _type;
  }
  
  char getX () 
  {
    return x;
  }
  
  char getY () 
  {
    return y;
  }

  void tailTransform();
  
  void display(Adafruit_PCD8544 & display);
};
