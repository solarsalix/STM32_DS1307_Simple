//======================================================================
//
//  WARNING: Simplified example, for demonstration purposes only
//
//======================================================================

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "libs/stm32_ds1307.h"
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

/* USER CODE BEGIN PV */
static uint8_t seconds, minutes, hours, weekday, date, month, year;
/* USER CODE END PV */

int main(void)
{
  /* USER CODE BEGIN Init */
  ds1307_init(&hi2c1);
  /* USER CODE END Init */
  
  /* USER CODE BEGIN 2 */
  ds1307_write(RTC_HOURS, 12);    // Write hours
  ds1307_write(RTC_MINUTES, 34);  // Write minutes
  ds1307_write(RTC_WEEKDAY, 1);   // Write weekday
  ds1307_write(RTC_DATE, 17);     // Write date
  ds1307_write(RTC_MONTH, 6);     // Write month
  ds1307_write(RTC_YEAR, 25);     // Write year as 2-digit value 0-99 (e.g., 25 for 2025)
  /* USER CODE END 2 */
  
  /* Infinite loop */
  while (1)
  {
    // ATTENTION: Avoid calling these functions in a tight loop
    // without using timers and flags to prevent excessive RTC polling
    seconds = ds1307_read(RTC_SECONDS);
    minutes = ds1307_read(RTC_MINUTES);
    hours = ds1307_read(RTC_HOURS);
    weekday = ds1307_read(RTC_WEEKDAY);
    date = ds1307_read(RTC_DATE);
    month = ds1307_read(RTC_MONTH);
    year = ds1307_read(RTC_YEAR);
    
    // Some code...
  }
}
