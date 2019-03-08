#include "Click_Thunder_types.h"

const uint32_t _THUNDER_SPI_CFG[ 4 ] = 
{ 
	_SPI_MASTER_OSC_DIV64, 
	_SPI_DATA_SAMPLE_MIDDLE, 
	_SPI_CLK_IDLE_HIGH, 
	_SPI_HIGH_2_LOW 
};

const uint32_t _THUNDER_I2C_CFG[ 1 ] = 
{
	100000
};
