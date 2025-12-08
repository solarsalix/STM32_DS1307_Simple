/*
 *      stm32_ds1307.h
 *
 *      Created on: 15 июн. 2025 г.
 *      Author: SolarSalix
 */

#pragma once

#define RTC_SECONDS     0x00
#define RTC_MINUTES     0x01
#define RTC_HOURS       0x02
#define RTC_WEEKDAY     0x03
#define RTC_DATE        0x04
#define RTC_MONTH       0x05
#define RTC_YEAR        0x06

#define RTC_I2C_TIMEOUT 10

void ds1307_init(I2C_HandleTypeDef *hi2c);
void ds1307_write(uint8_t reg_addr, uint8_t value);
uint8_t ds1307_read(uint8_t reg_addr);

//#ifndef SRC_LIBS_STM32_DS1307_H_
//#define SRC_LIBS_STM32_DS1307_H_
//
//
//
//#endif /* SRC_LIBS_STM32_DS1307_H_ */
