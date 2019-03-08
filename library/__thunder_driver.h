/*
    __thunder_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __thunder_driver.h
@brief    Thunder Driver
@mainpage Thunder Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   THUNDER
@brief      Thunder Click Driver
@{

| Global Library Prefix | **THUNDER** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **May 2018.**      |
| Developer             | **Nemanja Medakovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _THUNDER_H_
#define _THUNDER_H_

/** 
 * @macro T_THUNDER_P
 * @brief Driver Abstract type 
 */
#define T_THUNDER_P    const uint8_t*

/** @defgroup THUNDER_COMPILE Compilation Config */              /** @{ */

   #define   __THUNDER_DRV_SPI__                            /**<     @macro __THUNDER_DRV_SPI__  @brief SPI driver selector */
   #define   __THUNDER_DRV_I2C__                            /**<     @macro __THUNDER_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __THUNDER_DRV_UART__                           /**<     @macro __THUNDER_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup THUNDER_VAR Variables */                           /** @{ */

/** Possible device addresses **/
extern const uint8_t _THUNDER_DEV_ADDR_0;
extern const uint8_t _THUNDER_DEV_ADDR_1;
extern const uint8_t _THUNDER_DEV_ADDR_2;
extern const uint8_t _THUNDER_DEV_ADDR_3;

/** Register addresses **/
const uint8_t _THUNDER_CONFIG_0_REG;
const uint8_t _THUNDER_CONFIG_1_REG;
const uint8_t _THUNDER_CONFIG_2_REG;
const uint8_t _THUNDER_CONFIG_3_INTERR_REG;
const uint8_t _THUNDER_ENERGY_LIGHTNING_LSBYTE_REG;
const uint8_t _THUNDER_ENERGY_LIGHTNING_MSBYTE_REG;
const uint8_t _THUNDER_ENERGY_LIGHTNING_MMSBYTE_REG;
const uint8_t _THUNDER_DISTANCE_REG;
const uint8_t _THUNDER_INTERR_PIN_CONFIG_REG;
const uint8_t _THUNDER_LDLUT_1_REG;
const uint8_t _THUNDER_LDLUT_2_REG;
const uint8_t _THUNDER_LDLUT_3_REG;
const uint8_t _THUNDER_LDLUT_4_REG;
const uint8_t _THUNDER_LDLUT_5_REG;
const uint8_t _THUNDER_LDLUT_6_REG;
const uint8_t _THUNDER_LDLUT_7_REG;
const uint8_t _THUNDER_LDLUT_8_REG;
const uint8_t _THUNDER_LDLUT_9_REG;
const uint8_t _THUNDER_LDLUT_10_REG;
const uint8_t _THUNDER_LDLUT_11_REG;
const uint8_t _THUNDER_LDLUT_12_REG;
const uint8_t _THUNDER_LDLUT_13_REG;
const uint8_t _THUNDER_LDLUT_14_REG;
const uint8_t _THUNDER_LDLUT_15_REG;
const uint8_t _THUNDER_LDLUT_16_REG;
const uint8_t _THUNDER_LDLUT_17_REG;
const uint8_t _THUNDER_LDLUT_18_REG;
const uint8_t _THUNDER_LDLUT_19_REG;
const uint8_t _THUNDER_LDLUT_20_REG;
const uint8_t _THUNDER_LDLUT_21_REG;
const uint8_t _THUNDER_LDLUT_22_REG;
const uint8_t _THUNDER_LDLUT_23_REG;
const uint8_t _THUNDER_LDLUT_24_REG;
const uint8_t _THUNDER_LDLUT_25_REG;
const uint8_t _THUNDER_LDLUT_26_REG;
const uint8_t _THUNDER_LDLUT_27_REG;
const uint8_t _THUNDER_LDLUT_28_REG;
const uint8_t _THUNDER_LDLUT_29_REG;
const uint8_t _THUNDER_LDLUT_30_REG;
const uint8_t _THUNDER_LDLUT_31_REG;
const uint8_t _THUNDER_LDLUT_32_REG;
const uint8_t _THUNDER_LDLUT_33_REG;
const uint8_t _THUNDER_LDLUT_34_REG;
const uint8_t _THUNDER_LDLUT_35_REG;
const uint8_t _THUNDER_LDLUT_36_REG;
const uint8_t _THUNDER_LDLUT_37_REG;
const uint8_t _THUNDER_LDLUT_38_REG;
const uint8_t _THUNDER_LDLUT_39_REG;
const uint8_t _THUNDER_LDLUT_40_REG;
const uint8_t _THUNDER_LDLUT_41_REG;
const uint8_t _THUNDER_LDLUT_42_REG;
const uint8_t _THUNDER_RESET_REG;
const uint8_t _THUNDER_CALIB_REG;

/** Options for Config 0 register **/
const uint8_t _THUNDER_INDOOR;
const uint8_t _THUNDER_OUTDOOR;
const uint8_t _THUNDER_NORMAL_MODE;
const uint8_t _THUNDER_POWER_DOWN;

/** Options for Config 2 register **/
const uint8_t _THUNDER_CLEAR_STAT;
const uint8_t _THUNDER_1_LIGHTNING;
const uint8_t _THUNDER_5_LIGHTNINGS;
const uint8_t _THUNDER_9_LIGHTNINGS;
const uint8_t _THUNDER_16_LIGHTNINGS;

/** Options for Config 3 register **/
const uint8_t _THUNDER_DIV_RATIO_16;
const uint8_t _THUNDER_DIV_RATIO_32;
const uint8_t _THUNDER_DIV_RATIO_64;
const uint8_t _THUNDER_DIV_RATIO_128;
const uint8_t _THUNDER_MASK_DISTURBER;
const uint8_t _THUNDER_UNMASK_DISTURBER;
const uint8_t _THUNDER_NO_INTERR;
const uint8_t _THUNDER_NOISE_LEVEL_INTERR;
const uint8_t _THUNDER_DISTURBER_INTERR;
const uint8_t _THUNDER_LIGHTNING_INTERR;

/** Options for Interrupt pin (IRQ) config register **/
const uint8_t _THUNDER_LCO_ON_IRQ_PIN;
const uint8_t _THUNDER_SRCO_ON_IRQ_PIN;
const uint8_t _THUNDER_TRCO_ON_IRQ_PIN;
const uint8_t _THUNDER_NO_DISPLAY_ON_IRQ_PIN;

/** Reset and RCO calibrate commands **/
const uint8_t _THUNDER_RESET_COMM;
const uint8_t _THUNDER_CALIB_RCO_COMM;

                                                                       /** @} */
/** @defgroup THUNDER_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup THUNDER_INIT Driver Initialization */              /** @{ */

#ifdef   __THUNDER_DRV_SPI__
void thunder_spiDriverInit(T_THUNDER_P gpioObj, T_THUNDER_P spiObj);
#endif
#ifdef   __THUNDER_DRV_I2C__
void thunder_i2cDriverInit(T_THUNDER_P gpioObj, T_THUNDER_P i2cObj, uint8_t slave);
#endif
#ifdef   __THUNDER_DRV_UART__
void thunder_uartDriverInit(T_THUNDER_P gpioObj, T_THUNDER_P uartObj);
#endif

                                                                       /** @} */
/** @defgroup THUNDER_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Generic Write function
 *
 * @param[in] register_address     Address where data be written
 * @param[in] transfer_data        Data to be written
 *
 * @returns 0 - OK, 1 - Wrong address parameter
 *
 * Function writes one byte to the register.
 */
uint8_t thunder_writeReg( uint8_t register_address, uint8_t transfer_data );

/**
 * @brief Generic Read function
 *
 * @param[in] register_address     Address which from data be read
 * @param[out] dataOut             Buffer where data be stored
 * @param[in] nBytes               Number of bytes to be read
 *
 * @returns 0 - OK, 1 - Wrong address parameter, 2 - Too large number of bytes parameter (MAX 51 bytes)
 *
 * Function reads the desired number of bytes from the registers.
 */
uint8_t thunder_readReg( uint8_t register_address, uint8_t *dataOut, uint8_t nBytes );

/**
 * @brief Command Send function
 *
 * @param[in] selCommand       0 - Reset command, Value different from 0 - RCO calibrate command
 *
 * Function performs the one of two possible commands.
 */
void thunder_sendCommand( uint8_t selCommand );

/**
 * @brief Interrupt Check function
 *
 * @returns 0x00 - No interrupt, 0x01 - Noise level too high, 0x04 - Disturber detected, 0x08 - Lightning interrupt
 *
 * Function checks and returns the interrupt value.
 */
uint8_t thunder_checkInterr( void );

/**
 * @brief Storm Information Get function
 *
 * @param[out] energyOut        Energy of the single lightning
 * @param[out] distanceOut      Distance estimation for the head of the storm
 *
 * Function gets energy of the single lightning and distance estimation for the head of the storm.
 */
void thunder_getStormInfo( uint32_t *energyOut, uint8_t *distanceOut );

/**
 * @brief IRQ Pin Check function
 *
 * Function returns the value of the IRQ pin (INT).
 */
uint8_t thunder_checkIRQPin( void );

                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Thunder_STM.c
    @example Click_Thunder_TIVA.c
    @example Click_Thunder_CEC.c
    @example Click_Thunder_KINETIS.c
    @example Click_Thunder_MSP.c
    @example Click_Thunder_PIC.c
    @example Click_Thunder_PIC32.c
    @example Click_Thunder_DSPIC.c
    @example Click_Thunder_AVR.c
    @example Click_Thunder_FT90x.c
    @example Click_Thunder_STM.mbas
    @example Click_Thunder_TIVA.mbas
    @example Click_Thunder_CEC.mbas
    @example Click_Thunder_KINETIS.mbas
    @example Click_Thunder_MSP.mbas
    @example Click_Thunder_PIC.mbas
    @example Click_Thunder_PIC32.mbas
    @example Click_Thunder_DSPIC.mbas
    @example Click_Thunder_AVR.mbas
    @example Click_Thunder_FT90x.mbas
    @example Click_Thunder_STM.mpas
    @example Click_Thunder_TIVA.mpas
    @example Click_Thunder_CEC.mpas
    @example Click_Thunder_KINETIS.mpas
    @example Click_Thunder_MSP.mpas
    @example Click_Thunder_PIC.mpas
    @example Click_Thunder_PIC32.mpas
    @example Click_Thunder_DSPIC.mpas
    @example Click_Thunder_AVR.mpas
    @example Click_Thunder_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __thunder_driver.h

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