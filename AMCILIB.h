/**
  ******************************************************************************
  * @file    AMCILIB.h
  * @author  Javier Fernandez Cepeda
  ******************************************************************************
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __AMCILIB_H
#define __AMCILIB_H

/* Includes ------------------------------------------------------------------*/
#include <Arduino.h>

/* Exported define -----------------------------------------------------------*/
#define MAX_POSITION 1000
#define MIN_POSITION -1000
/* Exported types ------------------------------------------------------------*/
typedef enum
{
	SERIAL_MODE = 0,
	PWM_MODE,
	ANALOG_MODE
}EControlModes;
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
class AmciLib {
private:
	char controlMode;
	bool isLogEnabled;
	int attachedPin;
public:
	AmciLib();
	~AmciLib();
	int begin(char Mode, int AttachedPin);
	void LogMode(bool status);
	void SetPosition(int position);
	
};

#endif /* __PROCARDULIB_H */
	
	
