#include "..//tm4c123gh6pm.h"
#include "var.h"
#include "Nokia5110.h"
#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "timer.h"

void welcomeScreen(void);
void raceGameScreen(void);
void drawHLine(void);
void printScore(void);
void gameOver(void);
void drawCar(int pos);
void drawImage(void);
void getNewCars(void);
int detectLoss(void);
void flashLoss(void);
