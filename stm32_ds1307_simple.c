/*
 *      stm32_ds1307.c
 *
 *      Created on: 15 июн. 2025 г.
 *      Author: SolarSalix
 */

#include "stm32f1xx_hal.h"
#include "stm32_ds1307.h"

I2C_HandleTypeDef *ds1307_i2c;

uint8_t ConvToRTC(uint8_t byte);
uint8_t ConvFromRTC(uint8_t byte);

//================================================================================
//	DS1307 INIT
//================================================================================
void ds1307_init(I2C_HandleTypeDef *hi2c)
{
	ds1307_i2c = hi2c;
	uint8_t start_register;
	start_register = ds1307_read(RTC_SECONDS) & 0b01111111;	// Reset 7-th bit to start DS1307 (0 - start, 1 - stop)
	ds1307_write(RTC_SECONDS, start_register);
}

//================================================================================
//	WRITE DATA TO DS1307
//================================================================================
void ds1307_write(uint8_t reg_addr, uint8_t value)
{
	uint8_t tx[2];
	tx[0] = reg_addr;
	tx[1] = ConvToRTC(value);
	HAL_I2C_Master_Transmit(ds1307_i2c, 0xD0, tx, 2, RTC_I2C_TIMEOUT);
}

//================================================================================
//	READ DATA FROM DS1307
//================================================================================
uint8_t ds1307_read(uint8_t reg_addr)
{
	uint8_t data;
	HAL_I2C_Master_Transmit(ds1307_i2c, 0xD0, &reg_addr, 1, RTC_I2C_TIMEOUT);
	HAL_I2C_Master_Receive(ds1307_i2c, 0xD0, &data, 1, RTC_I2C_TIMEOUT);
	return ConvFromRTC(data);
}

//================================================================================
//	CONVERT DATA TO DS1307 FORMAT
//================================================================================
uint8_t ConvToRTC(uint8_t byte)
{
	uint8_t result = (((byte/10) << 4) | (byte%10));
	return result;
}

//================================================================================
//	CONVERT DATA FROM DS1307 FORMAT
//================================================================================
uint8_t ConvFromRTC(uint8_t byte)
{
	uint8_t result = ((byte >> 4) * 10 + (0x0F & byte));
	return result;
}
//================================================================================

