#include <delay_u.h>
#include "msp.h"
#include "ms5837.h"
#include "mx25.h"
#include "i2c_driver.h"
#include "printf.h"
#include "user.h"
#include "driverlib.h"

static volatile RTC_C_Calendar newTime;
int hour_u,min_u,sec_u;

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	initI2C();
	rtc_initialise();
	spi_initialise();
	lcd_initialise();

	while(1){

	  float  D1= MS5837_Temperature ();
	    float  D2= MS5837_Pressure ();

	        //  printf();

	       //   delay_u(120);
	}
}

	// Starts the interrupt when Button is pressed ...

	void Port1_ISR (void)
	{
	    switch( P1IV ) {
	        case P1IV__NONE:   break;                               // None

	        case P1IV__P1IFG1:                                       // Pin 1 (button 1)
	            // Read_Mx25();
	             break;

	        case P1IV__P1IFG4:                                       // Pin 4 (button 2)
	          //   Predict_value();
	             break;

	       default:                                       // Pin 6
	             __no_operation();
	             break;


	    }
	}


	void RTC_C_IRQHandler(void)
	{
	    uint32_t status;

	    status = MAP_RTC_C_getEnabledInterruptStatus();
	    MAP_RTC_C_clearInterruptFlag(status);

	    if (status & RTC_C_CLOCK_READ_READY_INTERRUPT)
	    {
	        MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
	    }

	    if (status & RTC_C_TIME_EVENT_INTERRUPT)
	    {
	        /* Interrupts every minute - Set breakpoint here */
	        __no_operation();
	        newTime = MAP_RTC_C_getCalendarTime();

	    }

	    if (status & RTC_C_CLOCK_ALARM_INTERRUPT)
	    {
	        /* Interrupts at 10:04pm */
	        __no_operation();
	    }

	}




