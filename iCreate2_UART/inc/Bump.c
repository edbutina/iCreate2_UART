/*
// Bump.c
// Runs on MSP432
// Provide low-level functions that interface bump switches the robot.
*/

// Negative logic bump sensors
// P4.7 Bump5, left side of robot
// P4.6 Bump4
// P4.5 Bump3
// P4.3 Bump2
// P4.2 Bump1
// P4.0 Bump0, right side of robot

#include <stdint.h>
#include "msp.h"
// Initialize Bump sensors
// Make six Port 4 pins inputs
// Activate interface pullup
// pins 7,6,5,3,2,0
void Bump_Init(void){
    // write this as part of Lab 10
    P4->DIR &= ~(BIT7 | BIT6 | BIT5 | BIT3 | BIT2 | BIT0);
    P4->REN = (BIT7 | BIT6 | BIT5 | BIT3 | BIT2 | BIT0);
    P4->OUT = (BIT7 | BIT6 | BIT5 | BIT3 | BIT2 | BIT0);
  
}
// Read current state of 6 switches
// Returns a 6-bit positive logic result (0 to 63)
// bit 5 Bump5
// bit 4 Bump4
// bit 3 Bump3
// bit 2 Bump2
// bit 1 Bump1
// bit 0 Bump0
uint8_t Bump_Read(void){
    // write this as part of Lab 10
    uint8_t temp;
    temp = ~( (P4->IN) ) & 0xED;

    return temp; // replace this line
}

