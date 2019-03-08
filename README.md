![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Thunder Click

---

- **CIC Prefix**  : THUNDER
- **Author**      : Nemanja Medakovic
- **Verison**     : 1.0.0
- **Date**        : May 2018.

---

### Software Support

We provide a library for the Thunder Click on our [LibStock](https://libstock.mikroe.com/projects/view/750/thunder-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Library has ability to communicate with the device by using SPI or I2C driver, independently.
Library can be used to check what kind of storm is happend and to measure the energy of the single lightning and distance estimation from the head of the storm.
For more details check documentation.

Key functions :

- ``` uint8_t thunder_writeReg( uint8_t register_address, uint8_t transfer_data ) ``` - Function writes one byte to the register.
- ``` uint8_t thunder_readReg( uint8_t register_address, uint8_t *dataOut, uint8_t nBytes ) ``` - Function reads the desired number of bytes from the registers.
- ``` void thunder_getStormInfo( uint32_t *energyOut, uint8_t *distanceOut ) ``` - Function gets energy of the single lightning and distance estimation from the head of the storm.

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes I2C or SPI driver and performs the reset command and RCO calibrate command.
  Also configures the device for working properly.
- Application Task - (code snippet) - Always checks is interrupt event happend (Listening mode) and after that gets
  the informations about storm. Results logs on UART.


```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/750/thunder-click) page.

Other mikroE Libraries used in the example:

- Conversions
- I2C
- SPI
- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
