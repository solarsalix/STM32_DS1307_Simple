# STM32_DS1307_Simple
Very simple HAL library for DS1307 RTC. It has only three functions: RTC initialization, data reading and data writing.

| _Function name_ | _Attributes_ | _Values_ |
| - | - | - |
| ds1307_init(*hi2c)  | I2C_HandleTypeDef *hi2c | _I2C stream name_ |
| ds1307_read(reg_addr)  | uint8_t reg_addr | _Address of the register to be read_ |
| ds1307_write(reg_addr, value) | uint8_t reg_addr | _Address for sending data_
|  | uint8_t value | _Data to send_ |


---


Instead of specifying DS1307 register addresses, the following names can be used:
| _Defined register names_ |
| - |
| RTC_SECONDS |
| RTC_MINUTES |
| RTC_HOURS |
| RTC_WEEKDAY |
| RTC_DATE |
| RTC_MONTH |
| RTC_YEAR |
