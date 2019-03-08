#include "Click_Thunder_types.h"

const uint32_t _THUNDER_SPI_CFG[ 3 ] = 
{ 
	1000000,  
	_SPI_MSB_FIRST, 
	_SPI_CLK_IDLE_HIGH | 
	_SPI_SAMPLE_DATA_RISING_EDGE 
};

const uint32_t _THUNDER_I2C_CFG[ 1 ] = 
{ 
	_I2C_100KHZ 
};
