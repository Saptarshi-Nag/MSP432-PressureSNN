
#include "mx25.h"
#include "driverlib.h"
#include <stdbool.h>
#include <stdint.h>
#include "msp.h"

void rtc_initialise()
{
    const RTC_C_Calendar currentTime =
      {
      0x00,
      0x03,
      0x22,
      0x12,
      0x11,
      0x2018
      };



    RTC_C_Calendar currTime;


    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_PJ,
               GPIO_PIN0 | GPIO_PIN1, GPIO_PRIMARY_MODULE_FUNCTION);
       MAP_GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);

       CS_setExternalClockSourceFrequency(32000,48000000);


           CS_startLFXT(false);
           MAP_RTC_C_initCalendar(&currentTime, RTC_C_FORMAT_BCD);

           MAP_RTC_C_setCalendarEvent(RTC_C_CALENDAREVENT_MINUTECHANGE);

           MAP_RTC_C_clearInterruptFlag(
                      RTC_C_CLOCK_READ_READY_INTERRUPT | RTC_C_TIME_EVENT_INTERRUPT);
              MAP_RTC_C_enableInterrupt(
                      RTC_C_CLOCK_READ_READY_INTERRUPT | RTC_C_TIME_EVENT_INTERRUPT);

              /* Start RTC Clock */
              MAP_RTC_C_startClock();

              MAP_Interrupt_enableInterrupt(INT_RTC_C);
                 MAP_Interrupt_enableSleepOnIsrExit();
                 MAP_Interrupt_enableMaster();

}





