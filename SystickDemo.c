#include "Systick.h"
#include "Derivative.h"
#include "mcg.h"

#define RED_LED     (1<<18)

static volatile unsigned int Time=0;

void Init_Systick()
{
	//This initializes the timer
    //set RVR the value that the background timer counts up to before it flags the main processor.
	SYST_RVR =  CORE_CLOCK/1000u;
	//3 reset current value. back to zero because we're just starting
	SYST_CVR = 0;
    //now we set the control status register.
	SYST_CSR = 0x7     ;//SysTick_CSR_ENABLE_MASK | SysTick_CSR_CLKSOURCE_MASK | SysTick_CSR_CLKSOURCE_MASK;
}

void SysTick_Handler()
{
    //we broke the timer down so that it generates an
    //interrupt in here once every 1/1000th of a second.
    Time++;//counts
    if(Time==1000)
    {
        Time = 0;//resets the counter back to zero.
        GPIOB_PTOR = RED_LED;//This toggles the red led
    }
    
}