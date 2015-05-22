#include "AMCILIB.h"

AmciLib IngeniaDriveInstance;

const int PWMPin = 6;

void setup()
{
	IngeniaDriveInstance.begin(PWM_MODE, PWMPin);
}

void loop()
{
  // put your main code here, to run repeatedly:
  for (int i = MIN_POSITION; i < MAX_POSITION; i++)
  {
    IngeniaDriveInstance.SetPosition(i);
    delay(10);
  }
  for (int i = MAX_POSITION; i >= MIN_POSITION; i--)
  {
    IngeniaDriveInstance.SetPosition(i);
    delay(10);
  }

  for (int i = MIN_POSITION; i < MAX_POSITION; i++)
  {
    IngeniaDriveInstance.SetPosition(i);
    delay(5);
  }
  for (int i = MAX_POSITION; i >= MIN_POSITION; i--)
  {
    IngeniaDriveInstance.SetPosition(i);
    delay(5);
  }
  
  for (int i = MIN_POSITION; i < MAX_POSITION; i++)
  {
    IngeniaDriveInstance.SetPosition(i);
    delay(2);
  }
  for (int i = MAX_POSITION; i >= MIN_POSITION; i--)
  {
    IngeniaDriveInstance.SetPosition(i);
    delay(2);
  }
}

















