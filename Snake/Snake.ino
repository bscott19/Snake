// Snake for MeggyJr by Brent Scott

#include <MeggyJrSimple.h>

//int x, y;

int appleX = random(8);
int appleY = random(8);

boolean gotApple = false;

int heading = 270;

// Variables for the array

int marker = 0;

struct Point {
  int x;
  int y;
};

Point snakeArray[64];
//------

void setup()
{
  MeggyJrSimpleSetup();
  snakeArray[marker].x = 3;
  snakeArray[marker].y = 3;
}

void loop()
{
  drawSnake();
  SpawnApple();
  DisplaySlate();
  CheckButtonsDown();
  
//  delay(200);
  MovePlayer();
  ClearSlate();
  updateSnake();
}

//------

void drawSnake() {
  for (int i = 0; i < marker+1; i++) {
    DrawPx(snakeArray[i].x, snakeArray[i].y, 1);
  }
}

/* void DrawDot()
{
  DrawPx(x,y,FullOn);
} */

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
    snakeArray[marker].y++;
  }
  if(heading == 90)
  {
    snakeArray[marker].x++;
  }
  if(heading == 180)
  {
    snakeArray[marker].y--;
  }
  if(heading == 270)
  {
    snakeArray[marker].x--;
  }
  if(snakeArray[marker].x < 0)
  {
    snakeArray[marker].x = 7;
  }
  if(snakeArray[marker].x > 7)
  {
  snakeArray[marker].x = 0;
  }
  if (snakeArray[marker].y > 7)
  {
    snakeArray[marker].y = 0;
  }
  if (snakeArray[marker].y < 0)
  {
    snakeArray[marker].y = 7;
  }
}

void SpawnApple()
{
  DrawPx(appleX,appleY,4);
  if (snakeArray[marker].x == appleX && snakeArray[marker].y == appleY)
  {
    gotApple=true;
    marker++;
    snakeArray[marker].x = appleX;
    snakeArray[marker].y = appleY;
  }
  if (gotApple == true)
  {
    appleX = random(8);
    appleY = random(8);
    gotApple = false;
  }
}

void updateSnake()
{
   for (int i = marker - 1; i > 0; i--)
  {
      snakeArray[i].x = snakeArray[i-1].x;
      snakeArray[i].y = snakeArray[i-1].y;
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
