// Snake for MeggyJr by Brent Scott

#include <MeggyJrSimple.h>

//Player Variables:
int x, y;

//Apple Variables:
int appleX, appleY;

//------

void setup()
{
  MeggyJrSimpleSetup();
  x = 3;
  y = 3;
}

void loop()
{
  DrawDot();
  SpawnApple();
  DisplaySlate();
  CheckButtonsDown();
  delay(200);
  MovePlayer();
  ClearSlate();
}

//------

void DrawDot()
{
  DrawPx(x,y,1);
}

void MovePlayer()
{
  if(Button_Left)
  {
    x--;
  }
  if(Button_Right)
  {
    x++;
  }
  if(Button_Up)
  {
    y++;
  }
  if(Button_Down)
  {
    y--;
  }
    if(x < 0)
  {
    x = 0;
  }
  if(x > 7)
  {
  x = 7;
  }
  if (y > 7)
  {
    y = 7;
  }
  if (y < 0)
  {
    y = 0;
  }
}

void SpawnApple()
{
  int appleX = random(7)+1;
  int appleY = random(7)+1;
  DrawPx(appleX,appleY,4);
}
