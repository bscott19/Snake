// Snake for MeggyJr by Brent Scott

#include <MeggyJrSimple.h>

//int x, y;

int appleX = random(8);
int appleY = random(8);
int color;

boolean gotApple = false;

int heading = 270;

// Variables for the array

int marker = 0;

struct Point
{
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
  color = 1;
}

void loop()
{
  drawSnake();
  DisplaySlate();
  delay(200);
  ClearSlate();
  updateSnake();
  CheckButtonsPress();
// Update snake head  
  SpawnApple();
  MovePlayer();
}

//------

void drawSnake()
{
  for (int i = 0; i < marker+1; i++)
  {
    DrawPx(snakeArray[i].x, snakeArray[i].y, color);
  }
}

void MovePlayer()
{
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

void changeSnakeColor()
{
  if (Button_A)
  {
    color++;
    Tone_Start(1500,100);
    delay(110);
    Tone_Start(1700,80);
  }
  if (Button_B)
  {
    color--;
    Tone_Start(1500,100);
    delay(100);
    Tone_Start(1300,80);
  }
  if (color>14)
  {
    color=1;
  }
  if (color<1)
  {
    color=14;
  }
  if (color==4)
  {
    color=5;
  }
}
