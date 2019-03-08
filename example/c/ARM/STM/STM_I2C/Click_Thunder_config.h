#include "Click_Thunder_types.h"

const uint32_t _THUNDER_SPI_CFG[ 2 ] = 
{ 
        _SPI_FPCLK_DIV256,
        _SPI_FIRST_CLK_EDGE_TRANSITION |
        _SPI_CLK_IDLE_HIGH |
        _SPI_MASTER | 
        _SPI_MSB_FIRST |
        _SPI_8_BIT | 
        _SPI_SSM_ENABLE | 
        _SPI_SS_DISABLE | 
        _SPI_SSI_1
};

const uint32_t _THUNDER_I2C_CFG[ 1 ] = 
{
        100000
};