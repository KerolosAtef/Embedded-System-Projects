#include "timer.h"
#include "game.h"

void Timer3A(void)
{
	//Setting Up Timer
	SYSCTL_RCGCTIMER_R |= (1<<3); //enable timer #3
	TIMER3_CTL_R &= ~(1<<0); //Disable it before changes
	TIMER3_CFG_R = 0x00000000;
	TIMER3_TAMR_R = ((0x2) << 0);	 //1st and 2nd bits only depending on mode
	TIMER3_TAMR_R = (1 << 4);	 //bit 4 hold the counting direction (1 = UP, 0 = DOWN)
	TIMER3_TAILR_R = 6000000; //Holds the number to count up to or down from 8Million which is the frequency (1msec)
	TIMER3_IMR_R |= (1<<0); //Enable Interrupt on the timer
	TIMER3_CTL_R |= (1<<0); //Now enable timer after initiallization
	
	//Setting up interrupt
	NVIC_PRI5_R =  (NVIC_PRI5_R&0xFFFF00FF)|0x0000A000; // set priority 
	NVIC_EN1_R = (1<<3);

}

void Timer3A_Handler(void){
	
	TIMER3_ICR_R  |= (1<<0); // reset RIS_R
			// pink     R-B    0x06 // 0000 0110
	if(!loaded) return;
	//GPIO_PORTF_DATA_R ^= ( (1<<1) | (1<<2) );
	drawImage();
}

void Delay(void){unsigned long volatile time;
	int t = 10;
  while(t--)
	{
		time = 727240*200/91;  // 0.1sec
		while(time){
		time--;
		}
	}
}

void disableTimer(void)
{
	TIMER3_CTL_R &= ~(1<<0);
}
