// Snake for MeggyJr by Brent Scott

#include <MeggyJrSimple.h>

int x, y;

int appleX = random(8);
int appleY = random(8);

boolean gotApple = false;

int heading = 270;

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
//  delay(200);
  MovePlayer();
  ClearSlate();
}

//------

void DrawDot()
{
  DrawPx(x,y,FullOn);
}

void MovePlayer()
{
  delay(300);
  if (Button_Up)
  {
    heading = 360;
  }
  if (Button_Right)
  {
    heading = 90;
  }
  if (Button_Down)
  {
    heading = 180;
  }
  if (Button_Left)
  {
    heading = 270;
  }
  if(heading == 360)
  {
    y++;
  }
  if(heading == 90)
  {
    x++;
  }
  if(heading == 180)
  {
    y--;
  }
  if(heading == 270)
  {
    x--;
  }
    if(x < 0)
  {
    x = 7;
  }
  if(x > 7)
  {
  x = 0;
  }
  if (y > 7)
  {
    y = 0;
  }
  if (y < 0)
  {
    y = 7;
  }
}

void SpawnApple()
{
  DrawPx(appleX,appleY,4);
  if (x == appleX && y == appleY)
  {
    gotApple=true;
  }
  if (gotApple == true)
  {
    appleX = random(8);
    appleY = random(8);
    gotApple = false;
  }
}


/*
void RespawnApple()
{
  if (x == appleX && y == appleY)
  {
    gotApple=true;
  }
  if (gotApple == true)
  {
    appleX = random(8);
    appleY = random(8);
    gotApple == false;
  }
}
*/
