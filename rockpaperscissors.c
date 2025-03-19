#include "rockpaperscissors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define MAX_LINE_LENGTH   1000

#ifdef __linux__
#define clear() printf("\033[H\033[J")
#endif

#ifdef _WIN32
#define clear() system("cls") 
#endif

//print options for selection
void outputSelectOpt(){
    printf("Select from options:\n"
    "[1] Rock\n"
    "[2] Paper\n"
    "[3] Scissors\n"
    "[4] End\n");
}

int isInRange(int lowerLimit, int upperLimit, int no)
{
    return (lowerLimit <= no && no <= upperLimit);
}


void getUserSelect(int* userSelInp,int rangeLow,int rangeHigh){
    char userSelStr[MAX_LINE_LENGTH];
    int userSel = 0;
    for(;;)
    {
        printf("Enter selection Number: ");
        fgets(userSelStr, sizeof userSelStr, stdin);
        fflush(stdin);

        userSelStr[strcspn(userSelStr, "\n")] = 0;
        //reset user input
        userSel = atoi(userSelStr);
        memset(userSelStr, 0, sizeof userSelStr);
        //Check if input is valid
        if(isInRange(rangeLow,rangeHigh,userSel)){
            *userSelInp = userSel;
            clear();
            break;
        }
        else{
            printf("invalid input\n");
        }
    }
}

void getUserName(char* name, int bufSize){
    //char name[50];
    printf("Enter your name: ");
    //safe user input with bufer
    fgets(name, bufSize, stdin);
    //remove newline char and replace with null
    name[strcspn(name,"\n")] = 0;
}


//randomly select from 3 options
void generateVirtualSelect(int* comSelect){
    /* random int between 1 and 3  and output selection*/
    *comSelect = 1+(rand()%(3));

    switch(*comSelect){
            case 1:
                printf("computer chose: ROCK\n\n");
                break;
            case 2:
                printf("computer chose: PAPER\n\n");
                break;
            case 3:
                printf("computer chose: SCISSORS\n\n");
                break;
    }
}

//compare user selection to generated option
int findWinner(int* userChoice, int* comSelect){

    int userInput = *userChoice;
    int comInput = *comSelect;
    switch(userInput){
        case 1:
            if (comInput == 1)
                return(TIE);
            else if(comInput == 2)
                return(COMPUTER_WIN);
            else
                return(USER_WIN);
        case 2:
            if (comInput == 1)
                return(USER_WIN);
            else if(comInput == 2)
                return(TIE);
            else
                return(COMPUTER_WIN);
        case 3:
            if (comInput == 1)
                return(COMPUTER_WIN);
            else if(comInput == 2)
                return(USER_WIN);
            else
                return(TIE);
    }
    return(0);
}

void mainGameplayProc(void* args){
    userStats_t* player1 = (userStats_t*)args;

    int userChoice = 0;
    int comSelect = 0;
    int matchWinner = 0;

    for(;;){
        outputSelectOpt();
        getUserSelect(&userChoice,1,4);
        //Exit choice selection:
        if (userChoice == EXIT)
        {
            break;
        }
        generateVirtualSelect(&comSelect);
        
        
        matchWinner = findWinner(&userChoice, &comSelect);
        player1->gamesPlayed++;

        switch(matchWinner){
            case COMPUTER_WIN:
                printf("COMPUTER WINS!\n\n");
                player1->totalWins++;
                break;
            case USER_WIN:
                printf("USER WINS!\n\n");
                player1->totalLoss++;
                break;
            case TIE:
                printf("MATCH WAS TIE!\n\n");
                player1->totalTies++;
                break;
        }
    }
}
