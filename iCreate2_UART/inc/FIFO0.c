/*
// FIFO0.c
// Runs on any microcontroller
// Two first in first out queues
*/

#include <stdint.h>
#include "..\inc\FIFO0.h"

// Implementation of the transmit FIFO, TxFifo0
// can hold 0 to TXFIFOSIZE-1 elements
// you are allowed to restrict TXFIFOSIZE to a power of 2

// add static, volatile, global variables here this as part of Lab 18
uint8_t volatile *PutPt;
uint8_t volatile *GetPt;
uint8_t volatile *RxPutPt;
uint8_t volatile *RxGetPt;
uint8_t static Fifo[TX0FIFOSIZE];
uint8_t static RxFifo[TX0FIFOSIZE];
// uint32_t *pBuffer = &Buffer;

uint32_t TxHistogram[TX0FIFOSIZE]; 
// probability mass function of the number of times TxFifo0 as this size
// as a function of FIFO size at the beginning of call to TxFifo0_Put
// initialize index TxFifo0
void TxFifo0_Init(void){int i;
// write this as part of Lab 18

  for(i=0;i<TX0FIFOSIZE;i++){
      TxHistogram[i] = 0;
  }
  PutPt = GetPt = &Fifo[0];
}
// add element to end of index TxFifo0
// return TXFIFOSUCCESS if successful
int TxFifo0_Put(char data){
  TxHistogram[TxFifo0_Size()]++;  // probability mass function
  uint8_t volatile *nextPutPt;
  nextPutPt = PutPt+1;

  if(nextPutPt == &Fifo[TX0FIFOSIZE])
  {
      nextPutPt = &Fifo[0]; //wrap
  }

  if(nextPutPt == GetPt)
  {
      return(FIFOFAIL);
  }

  else
  {
      *(PutPt) = data;
      PutPt = nextPutPt;
      return(FIFOSUCCESS);
  }

}
// remove element from front of TxFifo0
// return TXFIFOSUCCESS if successful
int TxFifo0_Get(char *datapt){
    if(PutPt == GetPt)
    {
        return(FIFOFAIL);  // Empty if PutPt=GetPt
    }

    *datapt = *(GetPt++);

    if(GetPt == &Fifo[TX0FIFOSIZE])
    {
        GetPt = &Fifo[0];  // wrap
    }
    return(FIFOSUCCESS);

// write this as part of Lab 18

}
// number of elements in TxFifo0
// 0 to TXFIFOSIZE-1
uint16_t TxFifo0_Size(void){

// write this as part of Lab 18

 return 0; // replace this line
}

// Implementation of the receive FIFO, RxFifo0
// can hold 0 to RXFIFOSIZE-1 elements
// you are allowed to restrict RXFIFOSIZE to a power of 2

// add static, volatile, global variables here this as part of Lab 18

// initialize RxFifo0
void RxFifo0_Init(void){

// write this as part of Lab 18
    RxPutPt = RxGetPt = &RxFifo[0];
}
// add element to end of RxFifo0
// return FIFOSUCCESS if successful
int RxFifo0_Put(char data){

  // write this as part of Lab 18

    uint8_t volatile *nextPutPt;
    nextPutPt = RxPutPt+1;

    if(nextPutPt == &RxFifo[TX0FIFOSIZE])
    {
        nextPutPt = &RxFifo[0]; //wrap
    }

    if(nextPutPt == RxGetPt)
    {
        return(FIFOFAIL);
    }

    else
    {
        *(RxPutPt) = data;
        RxPutPt = nextPutPt;
        return(FIFOSUCCESS);
    }

}
// remove element from front of RxFifo0
// return FIFOSUCCESS if successful
int RxFifo0_Get(char *datapt){

  // write this as part of Lab 18

    if(RxPutPt == RxGetPt)
    {
        return(FIFOFAIL);  // Empty if PutPt=GetPt
    }

    *datapt = *(RxGetPt++);

    if(RxGetPt == &RxFifo[TX0FIFOSIZE])
    {
        RxGetPt = &RxFifo[0];  // wrap
    }

  return(FIFOSUCCESS);
}
// number of elements in RxFifo0
// 0 to RXFIFOSIZE-1
uint16_t RxFifo0_Size(void){
// write this as part of Lab 18

 return 0; // replace this line
}


