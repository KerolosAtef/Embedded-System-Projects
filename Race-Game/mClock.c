#include "mClock.h"
#include "../tm4c123gh6pm.h"

void portF_initialization(void){ volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000020;     // 1) F clock
  delay = SYSCTL_RCGC2_R;           // delay
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock PortF PF0
  GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0
  GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTF_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL
  GPIO_PORTF_DIR_R = 0x0E;          // 5) PF4,PF0 input, PF3,PF2,PF1 output
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) no alternate function
  GPIO_PORTF_PUR_R = 0x11;          // enable pullup resistors on PF4,PF0
  GPIO_PORTF_DEN_R = 0x1F;          // 7) enable digital pins PF4-PF0
// interrupt
	GPIO_PORTF_IM_R |= ((1<<4) | (1<<0)) ;  // un mask PF0 , PF4
	GPIO_PORTF_IS_R &=~((1<<4)| (1<<0));		// edage not level
	GPIO_PORTF_IBE_R &= ~((1<<4)| (1<<0));	// no both edages
	GPIO_PORTF_IEV_R |=((1<<4)| (1<<0));   // riasing edage
	NVIC_EN0_R |=(1<<30);
	NVIC_PRI17_R |= (5<<21) ; 							// priority 5
}

void timer_initialization (){
	volatile unsigned long delay;
	SYSCTL_RCGCTIMER_R |= 0x08;   // Enable Clock to timer3
	delay = 0;									// Allaw Delay
	TIMER3_CTL_R &= ~ 0x00000001; // Disable the Timer durning Configuration
	TIMER3_CFG_R = 0x00000000;    // 32bit Mood
	TIMER3_TAMR_R = 0x00000002;   // Periodic Mood
	TIMER3_TAMR_R |= 0x00000010;  // Up Count Mood
	TIMER3_TAILR_R = 0x04C4B400;   // Value for 80000000 in Hex Assumming 80 MHz
	TIMER3_CTL_R |= 0x00000001;   // Enable Timer
	//config interrupt
	TIMER3_IMR_R |= (1<<0);       //Enable timer A timeOut interrupt Mask
	NVIC_EN1_R = (1<<3);          // enable interrupt
}

