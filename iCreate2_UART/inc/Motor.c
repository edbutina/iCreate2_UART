/*
// Motor.c
// Runs on MSP432
// Provide mid-level functions that initialize ports and
*/

// Left motor direction connected to P5.4 (J3.29)
// Left motor PWM connected to P2.7/TA0CCP4 (J4.40)
// Left motor enable connected to P3.7 (J4.31)
// Right motor direction connected to P5.5 (J3.30)
// Right motor PWM connected to P2.6/TA0CCP3 (J4.39)
// Right motor enable connected to P3.6 (J2.11)

#include <stdint.h>
#include "msp.h"
#include "../inc/CortexM.h"
#include "../inc/PWM.h"

// *******Lab 13 solution*******

// ------------Motor_Init------------
// Initialize GPIO pins for output, which will be
// used to control the direction of the motors and
// to enable or disable the drivers.
// The motors are initially stopped, the drivers
// are initially powered down, and the PWM speed
// control is uninitialized.
// Input: none
// Output: none
void Motor_Init(void){
  // write this as part of Lab 13
  P3->DIR |= ( BIT7 | BIT6 );  //sleep pins
  P3->OUT &= ~ ( BIT7 | BIT6 );
  P5->DIR |= ( BIT5 | BIT4 );  //direction (phase) pins
  P5->OUT &= ~ ( BIT5 | BIT4 );
  

}

// ------------Motor_Stop------------
// Stop the motors, power down the drivers, and
// set the PWM speed control to 0% duty cycle.
// Input: none
// Output: none
void Motor_Stop(void){
  // write this as part of Lab 13
    P3->OUT &= ~ ( BIT7 | BIT6 );
    PWM_Init34(0, 0, 0);
  
}

// ------------Motor_Forward------------
// Drive the robot forward by running left and
// right wheels forward with the given duty
// cycles.
// Input: leftDuty  duty cycle of left wheel (0 to 14,998)
//        rightDuty duty cycle of right wheel (0 to 14,998)
// Output: none
// Assumes: Motor_Init() has been called
void Motor_Forward(uint16_t leftDuty, uint16_t rightDuty){ 
  // write this as part of Lab 13
    PWM_Init34(15000, rightDuty, leftDuty);
    P5->OUT &= ~ ( BIT5 | BIT4 ); //direction
    P3->OUT |= ( BIT7 | BIT6 );  //sleep
    PWM_Duty3(rightDuty);
    PWM_Duty4(leftDuty);
  
}

// ------------Motor_Right------------
// Turn the robot to the right by running the
// left wheel forward and the right wheel
// backward with the given duty cycles.
// Input: leftDuty  duty cycle of left wheel (0 to 14,998)
//        rightDuty duty cycle of right wheel (0 to 14,998)
// Output: none
// Assumes: Motor_Init() has been called
void Motor_Right(uint16_t leftDuty, uint16_t rightDuty){ 
  // write this as part of Lab 13
    P5->OUT |= BIT5; //direction
    P5->OUT &= ~(BIT4); //direction
    P3->OUT |= ( BIT7 | BIT6 );  //sleep
    PWM_Duty3(rightDuty);
    PWM_Duty4(leftDuty);

}

// ------------Motor_Left------------
// Turn the robot to the left by running the
// left wheel backward and the right wheel
// forward with the given duty cycles.
// Input: leftDuty  duty cycle of left wheel (0 to 14,998)
//        rightDuty duty cycle of right wheel (0 to 14,998)
// Output: none
// Assumes: Motor_Init() has been called
void Motor_Left(uint16_t leftDuty, uint16_t rightDuty){ 
  // write this as part of Lab 13
    P5->OUT |=  BIT4; //direction
    P5->OUT &=  ~(BIT5); //direction
    P3->OUT |= ( BIT7 | BIT6 );  //sleep
    PWM_Duty3(rightDuty);
    PWM_Duty4(leftDuty);

}

// ------------Motor_Backward------------
// Drive the robot backward by running left and
// right wheels backward with the given duty
// cycles.
// Input: leftDuty  duty cycle of left wheel (0 to 14,998)
//        rightDuty duty cycle of right wheel (0 to 14,998)
// Output: none
// Assumes: Motor_Init() has been called
void Motor_Backward(uint16_t leftDuty, uint16_t rightDuty){ 
  // write this as part of Lab 13
    PWM_Init34(15000, rightDuty, leftDuty);
    P5->OUT |= ( BIT5 | BIT4 );  // direction
    P3->OUT |= ( BIT7 | BIT6 );  // sleep
    PWM_Duty3(rightDuty);
    PWM_Duty4(leftDuty);

}
