/*
    __thunder_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__thunder_driver.h"
#include "__thunder_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __THUNDER_DRV_I2C__
static uint8_t _slaveAddress;
#endif

static uint8_t selectedDriver;

const uint8_t _THUNDER_DEV_ADDR_0 = 0x00;
const uint8_t _THUNDER_DEV_ADDR_1 = 0x01;
const uint8_t _THUNDER_DEV_ADDR_2 = 0x02;
const uint8_t _THUNDER_DEV_ADDR_3 = 0x03;

const uint8_t _THUNDER_CONFIG_0_REG = 0x00;
const uint8_t _THUNDER_CONFIG_1_REG = 0x01;
const uint8_t _THUNDER_CONFIG_2_REG = 0x02;
const uint8_t _THUNDER_CONFIG_3_INTERR_REG = 0x03;
const uint8_t _THUNDER_ENERGY_LIGHTNING_LSBYTE_REG = 0x04;
const uint8_t _THUNDER_ENERGY_LIGHTNING_MSBYTE_REG = 0x05;
const uint8_t _THUNDER_ENERGY_LIGHTNING_MMSBYTE_REG = 0x06;
const uint8_t _THUNDER_DISTANCE_REG = 0x07;
const uint8_t _THUNDER_INTERR_PIN_CONFIG_REG = 0x08;
const uint8_t _THUNDER_LDLUT_1_REG = 0x09;
const uint8_t _THUNDER_LDLUT_2_REG = 0x0A;
const uint8_t _THUNDER_LDLUT_3_REG = 0x0B;
const uint8_t _THUNDER_LDLUT_4_REG = 0x0C;
const uint8_t _THUNDER_LDLUT_5_REG = 0x0D;
const uint8_t _THUNDER_LDLUT_6_REG = 0x0E;
const uint8_t _THUNDER_LDLUT_7_REG = 0x0F;
const uint8_t _THUNDER_LDLUT_8_REG = 0x10;
const uint8_t _THUNDER_LDLUT_9_REG = 0x11;
const uint8_t _THUNDER_LDLUT_10_REG = 0x12;
const uint8_t _THUNDER_LDLUT_11_REG = 0x13;
const uint8_t _THUNDER_LDLUT_12_REG = 0x14;
const uint8_t _THUNDER_LDLUT_13_REG = 0x15;
const uint8_t _THUNDER_LDLUT_14_REG = 0x16;
const uint8_t _THUNDER_LDLUT_15_REG = 0x17;
const uint8_t _THUNDER_LDLUT_16_REG = 0x18;
const uint8_t _THUNDER_LDLUT_17_REG = 0x19;
const uint8_t _THUNDER_LDLUT_18_REG = 0x1A;
const uint8_t _THUNDER_LDLUT_19_REG = 0x1B;
const uint8_t _THUNDER_LDLUT_20_REG = 0x1C;
const uint8_t _THUNDER_LDLUT_21_REG = 0x1D;
const uint8_t _THUNDER_LDLUT_22_REG = 0x1E;
const uint8_t _THUNDER_LDLUT_23_REG = 0x1F;
const uint8_t _THUNDER_LDLUT_24_REG = 0x20;
const uint8_t _THUNDER_LDLUT_25_REG = 0x21;
const uint8_t _THUNDER_LDLUT_26_REG = 0x22;
const uint8_t _THUNDER_LDLUT_27_REG = 0x23;
const uint8_t _THUNDER_LDLUT_28_REG = 0x24;
const uint8_t _THUNDER_LDLUT_29_REG = 0x25;
const uint8_t _THUNDER_LDLUT_30_REG = 0x26;
const uint8_t _THUNDER_LDLUT_31_REG = 0x27;
const uint8_t _THUNDER_LDLUT_32_REG = 0x28;
const uint8_t _THUNDER_LDLUT_33_REG = 0x29;
const uint8_t _THUNDER_LDLUT_34_REG = 0x2A;
const uint8_t _THUNDER_LDLUT_35_REG = 0x2B;
const uint8_t _THUNDER_LDLUT_36_REG = 0x2C;
const uint8_t _THUNDER_LDLUT_37_REG = 0x2D;
const uint8_t _THUNDER_LDLUT_38_REG = 0x2E;
const uint8_t _THUNDER_LDLUT_39_REG = 0x2F;
const uint8_t _THUNDER_LDLUT_40_REG = 0x30;
const uint8_t _THUNDER_LDLUT_41_REG = 0x31;
const uint8_t _THUNDER_LDLUT_42_REG = 0x32;
const uint8_t _THUNDER_RESET_REG = 0x3C;
const uint8_t _THUNDER_CALIB_REG = 0x3D;

const uint8_t _THUNDER_INDOOR = 0x24;
const uint8_t _THUNDER_OUTDOOR = 0x1C;
const uint8_t _THUNDER_NORMAL_MODE = 0x00;
const uint8_t _THUNDER_POWER_DOWN = 0x01;

const uint8_t _THUNDER_CLEAR_STAT = 0xC0;
const uint8_t _THUNDER_1_LIGHTNING = 0x80;
const uint8_t _THUNDER_5_LIGHTNINGS = 0x90;
const uint8_t _THUNDER_9_LIGHTNINGS = 0xA0;
const uint8_t _THUNDER_16_LIGHTNINGS = 0xB0;

const uint8_t _THUNDER_DIV_RATIO_16 = 0x00;
const uint8_t _THUNDER_DIV_RATIO_32 = 0x40;
const uint8_t _THUNDER_DIV_RATIO_64 = 0x80;
const uint8_t _THUNDER_DIV_RATIO_128 = 0xC0;
const uint8_t _THUNDER_MASK_DISTURBER = 0x20;
const uint8_t _THUNDER_UNMASK_DISTURBER = 0x00;
const uint8_t _THUNDER_NO_INTERR = 0x00;
const uint8_t _THUNDER_NOISE_LEVEL_INTERR = 0x01;
const uint8_t _THUNDER_DISTURBER_INTERR = 0x04;
const uint8_t _THUNDER_LIGHTNING_INTERR = 0x08;

const uint8_t _THUNDER_LCO_ON_IRQ_PIN = 0x80;
const uint8_t _THUNDER_SRCO_ON_IRQ_PIN = 0x40;
const uint8_t _THUNDER_TRCO_ON_IRQ_PIN = 0x20;
const uint8_t _THUNDER_NO_DISPLAY_ON_IRQ_PIN = 0x00;

const uint8_t _THUNDER_RESET_COMM = 0x00;
const uint8_t _THUNDER_CALIB_RCO_COMM = 0x01;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __THUNDER_DRV_SPI__

void thunder_spiDriverInit(T_THUNDER_P gpioObj, T_THUNDER_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    selectedDriver = 0;
    hal_gpio_csSet( 1 );
}

#endif
#ifdef   __THUNDER_DRV_I2C__

void thunder_i2cDriverInit(T_THUNDER_P gpioObj, T_THUNDER_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    selectedDriver = 1;
    hal_gpio_csSet( 1 );
}

#endif
#ifdef   __THUNDER_DRV_UART__

void thunder_uartDriverInit(T_THUNDER_P gpioObj, T_THUNDER_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

uint8_t thunder_writeReg( uint8_t register_address, uint8_t transfer_data )
{
    uint8_t buffData[ 2 ];
    
    if (((register_address > 0x32) || (register_address > 0x03 && register_address < 0x08)) && (register_address != 0x3C && register_address != 0x3D))
    {
        return 1;
    }
    
    buffData[ 0 ] = register_address;
    buffData[ 1 ] = transfer_data;
    
    if (register_address == 0x3C || register_address == 0x3D)
    {
        buffData[ 1 ] = 0x96;
    }
    
    if (selectedDriver)
    {
        hal_i2cStart();
        hal_i2cWrite( _slaveAddress, buffData, 2, END_MODE_STOP );
    }
    else
    {
        hal_gpio_csSet( 0 );
        hal_spiWrite( buffData, 2 );
        hal_gpio_csSet( 1 );
    }
    
    return 0;
}

uint8_t thunder_readReg( uint8_t register_address, uint8_t *dataOut, uint8_t nBytes )
{
    uint8_t buffDataIn[ 52 ] = { 0 };
    uint8_t buffDataOut[ 52 ] = { 0 };
    uint8_t cnt;
    
    if (register_address > 0x32)
    {
        return 1;
    }
    if (nBytes > 51)
    {
        return 2;
    }
    
    if (selectedDriver)
    {
        buffDataIn[ 0 ] = register_address;
        
        hal_i2cStart();
        hal_i2cWrite( _slaveAddress, buffDataIn, 1, END_MODE_RESTART );
        hal_i2cRead( _slaveAddress, dataOut, nBytes, END_MODE_STOP );
    }
    else
    {
        buffDataIn[ 0 ] = register_address | 0x40;
        
        hal_gpio_csSet( 0 );
        hal_spiTransfer( buffDataIn, buffDataOut, nBytes + 1 );
        //hal_spiWrite( buffDataIn, 1 );
        //hal_spiRead( dataOut, nBytes );
        hal_gpio_csSet( 1 );
        
        for (cnt = 0; cnt < nBytes; cnt++)
        {
            dataOut[ cnt ] = buffDataOut[ cnt + 1 ];
        }
    }
    
    return 0;
}

void thunder_sendCommand( uint8_t selCommand )
{
    if (selCommand == 0)
    {
        thunder_writeReg( _THUNDER_RESET_REG, 0x96 );
    }
    else
    {
        thunder_writeReg( _THUNDER_CALIB_REG, 0x96 );
    }
    
    Delay_100ms();
    Delay_100ms();
    Delay_100ms();
}

uint8_t thunder_checkInterr( void )
{
    uint8_t interrCheck;
    
    if (hal_gpio_intGet())
    {
        Delay_1ms();
        Delay_1ms();
        Delay_1ms();
        Delay_1ms();
    
        thunder_readReg( _THUNDER_CONFIG_3_INTERR_REG, &interrCheck, 1 );
        interrCheck &= 0x0F;
    }
    else
    {
        interrCheck = 0;
    }
    
    return interrCheck;
}

void thunder_getStormInfo( uint32_t *energyOut, uint8_t *distanceOut )
{
    uint32_t temp;
    uint8_t tmp[ 4 ];

    thunder_readReg( _THUNDER_ENERGY_LIGHTNING_LSBYTE_REG, tmp, 4 );
    
    temp = tmp[ 2 ] & 0x1F;
    temp <<= 8;
    temp |= tmp[ 1 ];
    temp <<= 8;
    temp |= tmp[ 0 ];
    *energyOut = temp;
    
    *distanceOut = tmp[ 3 ] & 0x3F;
}

uint8_t thunder_checkIRQPin( void )
{
    return hal_gpio_intGet();
}

/* -------------------------------------------------------------------------- */
/*
  __thunder_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */