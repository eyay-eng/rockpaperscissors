
#ifndef ROCKPAPERSCISSORS_H
#define ROCKPAPERSCISSORS_H


void outputSelectOpt(void);

void getUserName(char* name, int* bufSize);

void getUserSelect(int* userChoice);

void generateVirtualSelect(int* comChoice);

int findWinner(int* userChoice, int* comSelect);

static int isInRange(int lowerLimit, int upperLimit, int no);

#endif /*ROCKPAPERSCISSORS_H*/