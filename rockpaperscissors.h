
#ifndef ROCKPAPERSCISSORS_H
#define ROCKPAPERSCISSORS_H

#include <stdint.h>

#define NAME_BUFFER_SIZE    64
#define COMPUTER_WIN      0
#define USER_WIN          1
#define TIE               3
#define EXIT              4

//Structure Definition
struct userStats_t{
    uint32_t totalWins;
    uint32_t totalLoss;
    uint32_t totalTies;
    char name[NAME_BUFFER_SIZE];
};


//Prototype Definitions
void outputSelectOpt(void);

void getUserName(char* name, int bufSize);

void getUserSelect(int* userChoice);

void generateVirtualSelect(int* comChoice);

int findWinner(int* userChoice, int* comSelect);

static int isInRange(int lowerLimit, int upperLimit, int no);

void mainGameplayProc(void* args);

#endif /*ROCKPAPERSCISSORS_H*/