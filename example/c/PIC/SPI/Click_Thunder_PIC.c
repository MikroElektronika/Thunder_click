/*
Example for Thunder Click

    Date          : May 2018.
    Author        : Nemanja Medakovic

Test configuration PIC :
    
    MCU             : P18F87K22
    Dev. Board      : EasyPIC PRO v7
    PIC Compiler ver : v7.2.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes SPI driver and performs the reset command and RCO calibrate command.
  Also configures the device for working properly.
- Application Task - (code snippet) - Always checks is interrupt event happend (Listening mode) and after that gets
  the informations about storm. Results logs on UART.

*/

#include "Click_Thunder_types.h"
#include "Click_Thunder_config.h"

uint8_t stormMode;
uint32_t stormEnergy;
uint8_t stormDistance;
char text[ 100 ];

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );

    mikrobus_spiInit( _MIKROBUS1, &_THUNDER_SPI_CFG[0] );

    mikrobus_logInit( _LOG_USBUART, 19200 );
    mikrobus_logWrite( "Initializing...", _LOG_LINE );

    Delay_ms( 100 );
}

void applicationInit()
{
    thunder_spiDriverInit( (T_THUNDER_P)&_MIKROBUS1_GPIO, (T_THUNDER_P)&_MIKROBUS1_SPI );
    Delay_ms( 200 );
    
    thunder_sendCommand( _THUNDER_RESET_COMM );
    thunder_sendCommand( _THUNDER_CALIB_RCO_COMM );
    
    thunder_writeReg( _THUNDER_CONFIG_0_REG, _THUNDER_OUTDOOR | _THUNDER_NORMAL_MODE );
    thunder_writeReg( _THUNDER_CONFIG_1_REG, 0x21 );
    thunder_writeReg( _THUNDER_CONFIG_2_REG, _THUNDER_CLEAR_STAT | _THUNDER_1_LIGHTNING | 0x02 );
    thunder_writeReg( _THUNDER_CONFIG_3_INTERR_REG, _THUNDER_DIV_RATIO_32 | _THUNDER_UNMASK_DISTURBER );
    thunder_writeReg( _THUNDER_INTERR_PIN_CONFIG_REG, _THUNDER_NO_DISPLAY_ON_IRQ_PIN );

    mikrobus_logWrite( "Thunder is initialized", _LOG_LINE );
    mikrobus_logWrite( "", _LOG_LINE );
    Delay_ms( 300 );
}

void applicationTask()
{
    stormMode = thunder_checkInterr();

    if (stormMode == _THUNDER_NOISE_LEVEL_INTERR)
    {
        mikrobus_logWrite( "Noise level too high", _LOG_LINE );
        mikrobus_logWrite( "", _LOG_LINE );
    }
    else if (stormMode == _THUNDER_DISTURBER_INTERR)
    {
        mikrobus_logWrite( "Disturber detected", _LOG_LINE );
        mikrobus_logWrite( "", _LOG_LINE );
    }
    else if (stormMode == _THUNDER_LIGHTNING_INTERR)
    {
        thunder_getStormInfo( &stormEnergy, &stormDistance );

        mikrobus_logWrite( "Energy of the single lightning : ", _LOG_TEXT );
        LongWordToStr( stormEnergy, text );
        mikrobus_logWrite( text, _LOG_LINE );
        mikrobus_logWrite( "Distance estimation : ", _LOG_TEXT );
        WordToStr( stormDistance, text );
        mikrobus_logWrite( text, _LOG_TEXT );
        mikrobus_logWrite( " km", _LOG_LINE );
        mikrobus_logWrite( "", _LOG_LINE );
    }
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}
