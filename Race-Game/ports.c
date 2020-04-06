#include "ports.h"

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
}

void GPIOPortF_Handler ()
{
	if(loaded)
	{
		if (GPIO_PORTF_RIS_R & (1<<0)) //Sw2 right
		{ 			
			if (posY[0] == 15 || posY[0] == 29){
				posY[0] += 14;
				/*Nokia5110_ClearBuffer();
				drawHLine();
				Nokia5110_PrintBMP(0, posY[0], carTwo, 0);
				Nokia5110_DisplayBuffer();*/
			}
			GPIO_PORTF_DATA_R = (1<<1);
			GPIO_PORTF_ICR_R |= (1<<0);
		}
		else if (GPIO_PORTF_RIS_R & (1<<4)) //Sw1 left
		{
			if(start) 
			{
				if (posY[0] == 43 || posY[0] == 29){
					posY[0] -= 14;	
					
					/*Nokia5110_ClearBuffer();
					drawHLine();
					Nokia5110_PrintBMP(0, posY[0], carTwo, 0);
					Nokia5110_DisplayBuffer();*/
				}
				//GPIO_PORTF_DATA_R = (1<<2);
			} 
			else
			{
					/*Nokia5110_ClearBuffer();
					drawHLine();
					Nokia5110_PrintBMP(0, posY[0], carTwo, 0);
					Nokia5110_DisplayBuffer();*/
					start++;
					//GPIO_PORTF_DATA_R = (1<<3);
					Timer3A();
			}
			GPIO_PORTF_ICR_R |= (1<<4);
		}
	}
}


void portE_initialization(void){ volatile unsigned long delay;
	
  SYSCTL_RCGC2_R |= (1 << 4);     	// 1) F clock
  delay = SYSCTL_RCGC2_R;           // delay          
  GPIO_PORTE_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTE_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTE_DIR_R = 0x00;   				// 5) PE2 & PE3 input
  GPIO_PORTE_AFSEL_R = 0x00;        // 6) no alternate function    
  GPIO_PORTE_DEN_R = 0x0C;     			// 7) enable digital pins PF4-PF0  
	
// interrupt 	
	GPIO_PORTE_IM_R |= ((1<<2) | (1<<3)) ;  // un mask PE2 , PE3
	GPIO_PORTE_IS_R &= ~((1<<2)| (1<<3));		// edge not level 
	GPIO_PORTE_IBE_R &= ~((1<<2)| (1<<3));	// not both edges 
	GPIO_PORTE_IEV_R |=((1<<2)| (1<<3));   // rising edge
	
	NVIC_EN0_R |= (1<<4);
	NVIC_PRI1_R |= (5<<5) ; // priority 5	
}


void GPIOPortE_Handler ()
{
	if(loaded)
	{
		if (GPIO_PORTE_RIS_R & (1<<2)) //PE2 right
		{ 			
			if (posY[0] == 15 || posY[0] == 29){
				posY[0] += 14;
				/*Nokia5110_ClearBuffer();
				drawHLine();
				Nokia5110_PrintBMP(0, posY[0], carTwo, 0);
				Nokia5110_DisplayBuffer();*/
			}
			//GPIO_PORTF_DATA_R = (1<<1);
			for(i = 0; i < 200000*sFactor; i++);
			GPIO_PORTE_ICR_R |= (1<<2);
		}
		else if (GPIO_PORTE_RIS_R & (1<<3)) //PE3 left
		{
			if(start) 
			{
				if (posY[0] == 43 || posY[0] == 29){
					posY[0] -= 14;	
					
					/*Nokia5110_ClearBuffer();
					drawHLine();
					Nokia5110_PrintBMP(0, posY[0], carTwo, 0);
					Nokia5110_DisplayBuffer();*/
				}
				//GPIO_PORTF_DATA_R = (1<<2);
			} 
			else
			{
					/*Nokia5110_ClearBuffer();
					drawHLine();
					Nokia5110_PrintBMP(0, posY[0], carTwo, 0);
					Nokia5110_DisplayBuffer();*/
					start++;
					//GPIO_PORTF_DATA_R = (1<<3);
					TIMER3_CTL_R |= (1<<0);
			}
			for(i = 0; i < 200000*sFactor; i++);
			GPIO_PORTE_ICR_R |= (1<<3);
		}
	}
	else
	{
		GPIO_PORTE_ICR_R |= (1<<2);
		GPIO_PORTE_ICR_R |= (1<<3);
	}
}
