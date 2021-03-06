/************************************************************************************************************/

/**											USAGE INSTRUCTIONS 											   **/
/************************************************************************************************************/
/* NOTE! The function hook functionality is only available in interrupt mode */
/*

CHANGING THE TIMER MODE:
    To change the timer to INTERRUPT MULTIPLEXING mode (calls functions every period), simply call the
    - timer_name.set_hook(function name, calling period, parameter pointer);
    and change the parameters. 
    *NOTE*! This mode is only available if the a hardware timer interrupt is selected as a source (SOURCE_INTERRUPT) to guarantee
    the correct period.

    To change the timer back to NORMAL mode, simply call the function
    - timer_name.set_hook(function name, calling period, parameter pointer);
    where first and last parameter are nullptr, and the second 0.

STARTING THE TIMER:
    - To start the timer, call timer.value() function.
GETTING THE TIMER VALUE:
    - To get the timer value, call the timer.value() function
RESETTING THE ELAPSED TIME:
    - To reset the elapsed time call the timer.reset() function */																		
/************************************************************************************************************/

/*********************************************	SETTINGS	*************************************************/


/*   INTERRUPT MODE   */
#define TIMER_CFG_USE_INTERRUPT                     1
#define TIMER_CFG_ISR_VECTOR				 TIMER3_COMPA_vect  // WARNING! The timer hardware must be configured manually, but you DONT'T need to create an ISR 
#define TIMER_CFG_INCREMENT_VALUE   			    1 


/*  SYSTEM TIME MODE  */
#define TIMER_CFG_USE_SYSTEM_TIME                   0
#define TIMER_CFG_SYSTEM_TIME_FUNCTION      system_timer_elapsed_ms()    // System time function call 
#define TIMER_CFG_SYSTEM_TIME_HEADER            "path_to_header"          // Path to the header where the system time function is located



/* 
 If SOURCE_INTERRUPT is enabled, the timers will be added to a linked list and get incremented thru an
 Interrupt Service Rouitine (this is just the source for the ticks, not connected with the timer mode).
 To use this settings you need to manually start a hardware timer and write it's vector
 in the TIMER_CFG_ISR_VECTOR macro, the timer period does not have to be 1ms, it can be anything, but make sure you update the TIMER_CFG_INCREMENT_VALUE
 
 If SOURCE_SYSTEM_TIME is enabled and SOURCE_INTERRUPT disabled, then the timer will use the difference between the system time and the timestamp from last reset */