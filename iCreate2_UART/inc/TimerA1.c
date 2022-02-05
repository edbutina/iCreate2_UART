/*
// TimerA1.c
// Runs on MSP432
// Use Timer A1 in periodic mode to request interrupts at a particular
// period.
*/

#include <stdint.h>
#include "msp.h"

void (*TimerA1Task)(void);   // user function

// ***************** TimerA1_Init ****************
// Activate Timer A1 interrupts to run user task periodically
// Inputs:  task is a pointer to a user function
//          period in units (24/SMCLK), 16 bits
// Outputs: none
// With SMCLK 12 MHz, period has units 2us
void TimerA1_Init(void(*task)(void), uint16_t period){
    // write this as part of Lab 13
    TimerA1Task = task;
    TIMER_A1->CTL = 0x280; //SMCLK, Input/4, Timer Halt,
    TIMER_A1->CCTL[0] = 0x0010; //CapComp Interrupt Enable
    TIMER_A1->CCR[0] = (period - 1);
    TIMER_A1->EX0 = 0x0005; //CLK Div/6
    NVIC->IP[2] = (NVIC->IP[2] & 0xFF00FFFF) | 0x00040000;
    NVIC->ISER[0] = 0x0000400;
    TIMER_A1->CTL |= 0x0014; //Timer Up Mode, Clear Timer
  
}


// ------------TimerA1_Stop------------
// Deactivate the interrupt running a user task periodically.
// Input: none
// Output: none
void TimerA1_Stop(void){
    // write this as part of Lab 13
    TIMER_A1->CTL &= ~(BIT1); //TAIE interrupt enable clear
 
}


void TA1_0_IRQHandler(void){
    // write this as part of Lab 13
    TIMER_A1->CCTL[0] &= ~0x0001;
    (*TimerA1Task)();
}
