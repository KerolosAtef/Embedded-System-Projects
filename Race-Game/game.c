#include "game.h"

// *************************** Images ***************************

const unsigned char carTwo[] ={
 0x42, 0x4D, 0x06, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x76, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80,
 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF,
 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x0F, 0xFF, 0xF7, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xF0, 0x00,
 0x00, 0x00, 0x0F, 0xFF, 0xF7, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF,
 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xF7, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xF7, 0x00, 0x00, 0x00,
 0x7F, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0xFF,

};


const unsigned char line[] ={
 0x42, 0x4D, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x76, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80,
 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF,
 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF,

};

// *************************** Capture image dimensions out of BMP**********
#define myCarW			((unsigned char)carTwo[18])
#define myCarH			((unsigned char)carTwo[22])
	
void flashLoss(void)
{
	for(r = 0; r < 3; r++)
	{
		Nokia5110_ClearBuffer();
		Nokia5110_DisplayBuffer();
		for(a = 0; a <= 1000000; a++);
		drawHLine();
		for(i = 0; i < 5; i++)
		{
			if(posX[i] == -1) continue;
			Nokia5110_PrintBMP(posX[i],posY[i],carTwo,0);
		}
		Nokia5110_DisplayBuffer();
		for(a = 0; a <= 1000000; a++);
	}
}

void drawHLine(void)
{
	for(i = 0; i < 7; i++)
	{
		Nokia5110_PrintBMP(i * 12, 1, line, 0); //
		Nokia5110_PrintBMP(12 * i, 47, line, 0); //
	}
	Nokia5110_DisplayBuffer(); 
}


void welcomeScreen(void)
{
	
	drawHLine();
	msg = "WELCOME";
	Nokia5110_SetCursor(3, 3);
	Nokia5110_OutString(msg);
	Delay();
	Nokia5110_Clear();
	raceGameScreen();
}

void gameOver(void)
{
	flashLoss();
	Nokia5110_ClearBuffer();
	loaded = 0;
	drawHLine();
	msg = "GAME OVER";
	Nokia5110_SetCursor(2, 3);
	Nokia5110_OutString(msg);
	Delay();
	Nokia5110_Clear();
	printScore();
}


void raceGameScreen(void)
{
	//Initialize
	loaded = 0;
	for(i = 0; i < 5; i++)
		posY[i] = posX[i] = -1;
	posY[0] = 29;
	posX[0] = 0;
	start = 0;
	score = 0;
	sFactor =1;
	TIMER3_TAILR_R = 6000000;
	temp = 0;
	drawHLine();
	msg = "CAR RACE";
	Nokia5110_SetCursor(2, 2);
	Nokia5110_OutString(msg);
	
	
	msg = "START?";
	Nokia5110_SetCursor(3, 4);
	Nokia5110_OutString(msg);
	
	loaded = 1;
	Delay();
	//gameOver();
}

void printScore()
{
	drawHLine();
	msg = "SCORE";
	Nokia5110_SetCursor(4, 2);
	Nokia5110_OutString(msg);
	
	Nokia5110_SetCursor(2, 4);
	Nokia5110_OutUDec(score);
	Delay();
	Nokia5110_Clear();
	raceGameScreen();
}








void drawImage(void)
{
	Nokia5110_ClearBuffer();
	drawHLine();
	mini = 100;
	for(i = 0; i < 5; i++)
	{
		if(posX[i] == -1) continue;
		Nokia5110_PrintBMP(posX[i],posY[i],carTwo,0);
		if(!i) continue;
		if(posX[i] < mini) mini = posX[i];
		--posX[i];
		if(!posX[i]) score ++;
	}
	if(mini == 21 || mini == 100)
	{
		getNewCars();
	}
	Nokia5110_DisplayBuffer();
	if(detectLoss() == 1)
	{
		TIMER3_CTL_R &= ~(1<<0);
		gameOver();
	}
	if(temp+4 <= score)
	{
		temp = score;
		sFactor*=0.75;
		TIMER3_TAILR_R *= sFactor;
	}
}

void getNewCars(void)
{
	
	r = rand() % 2 + 1;
	if(r == 1)
	{
		r = rand() % 3 + 1;
		for(i = 1; i < 5; i++)
		{
			if(posX[i] != -1) continue;
			posX[i] = 63;
			if(r == 1) posY[i] = 15;
			else if(r == 2) posY[i] = 29;
			else posY[i] = 43;
			break;
		}
	}
	else
	{
		r = rand() % 3 + 1;
		for(i = 1; i < 5; i++)
		{
			if(posX[i] != -1) continue;
			posX[i] = 63;
			if(r == 1) posY[i] = 15;
			else if(r == 2) posY[i] = 29;
			else posY[i] = 43;
			break;
		}
		a = r;
		while(r == a)
			r = rand() % 3+ 1;
		for(i = 1; i < 5; i++)
		{
			if(posX[i] != -1) continue;
			posX[i] = 63;
			if(r == 1) posY[i] = 15;
			else if(r == 2) posY[i] = 29;
			else posY[i] = 43;
			break;
		}
	}
}

int detectLoss(void)
{
	disableTimer();
	for(i = 1; i < 5; i++)
	{
		if(posX[i] == -1) continue;
		if(posY[i] != posY[0] ) continue;
		if(posX[0] + 18 >= posX[i]) return 1;
	}
	return 0;
}
