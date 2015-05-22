/**
  ******************************************************************************
  * @file    AMCILIB.c
  * @author  Javier Fernandez Cepeda
  ******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include <Arduino.h>
#include "AMCILIB.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define MAX_PWM	255
#define MIN_PWM 0
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*Constructors*/
AmciLib::AmciLib()
{
	isLogEnabled = false;
}

AmciLib::~AmciLib()
{
	if( isLogEnabled != false)
	{
		Serial.end();
	}
}

/**
  * @brief  Initializes the Ingenia drive instance
  * @param[in]  Mode	Indicates the connection type:
  *						 - Serial port
  *						 - PWM signal
  *						 - Analog signal
  * @param[in]	AttachedPin For Analog and PWM modes, indicates which pin is used
  *							for signal generation
  * @retval None
  */
int AmciLib::begin(char Mode, int AttachedPin)
{
	switch (Mode)
	{
		case SERIAL_MODE:
			Serial.begin(9600);
			break;
		case PWM_MODE:
			pinMode(AttachedPin, OUTPUT);
			attachedPin = AttachedPin;
			break;
		case ANALOG_MODE:
			break;
	}
	
	controlMode = Mode;
	return 0;
}

/**
  * @brief  Enable/Disable the log messages.
  * @param[in] status true if enabled, false otherwise
  */
void AmciLib::LogMode(bool status)
{	
	if (status == true)
	{
		Serial.begin(9600);
	}
	isLogEnabled = status;
}

/**
  * @brief  Sends a position to the Ingenia drive
  * @param[in] Position a value from -1000 to 1000
  */
void AmciLib::SetPosition(int position)
{
	if( position > MAX_POSITION)
	{
		position = MAX_POSITION;
	}
	
	if( position < MIN_POSITION)
	{
		position = MIN_POSITION;
	}
	
	if( isLogEnabled != false)
	{
		Serial.print("Input position: "); Serial.println(position);
	}
	
	switch(controlMode)
	{
		case SERIAL_MODE:
		break;
		case PWM_MODE:
		int PWMOut;
		PWMOut = map(position, MIN_POSITION, MAX_POSITION, MIN_PWM, MAX_PWM);
		if( isLogEnabled != false)
		{
			Serial.print("Output duty: "); Serial.println(PWMOut);
		}
		analogWrite(attachedPin, PWMOut);
		break;
		case ANALOG_MODE:
		break;
	}
	
	
}
