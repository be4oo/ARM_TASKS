#include "stm32f10x_rtc.h"

int main(void)
{
  // Initialize the RTC
  RTC_ITConfig(RTC_IT_SEC, ENABLE);
  RTC_WaitForLastTask();

  while (1)
  {
    if (RTC_GetITStatus(RTC_IT_SEC) == SET)
    {
      // Handle the second interrupt
      RTC_ClearITPendingBit(RTC_IT_SEC);
    }
  }
}
