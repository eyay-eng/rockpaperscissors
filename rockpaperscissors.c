#include "rockpaperscissors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LINE_LENGTH   1000
#define COMPUTER_WIN      0
#define USER_WIN          1
#define TIE               3
#define bool int

//print options for selection
void outputSelectOpt(){
    printf("Select from options:\n"
    "[1] Rock\n"
    "[2] Paper\n"
    "[3] Scissors\n"
    "[4] Exit\n");
}

bool isInRange(int lowerLimit, int upperLimit, int no)
{
    return (lowerLimit <= no && no <= upperLimit);
}


void getUserSelect(int* userSelInp){
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
        if(isInRange(1,4,userSel)){
            *userSelInp = userSel;
            break;
        }
        else{
            printf("invalid input: Entry must be 1-4\n");
        }
    }
}

void getUserName(){
    char name[50];
    printf("Enter your name: ");
    //safe user input with bufer
    fgets(name, sizeof name, stdin);
    //remove newline char and replace with null
    name[strcspn(name,"\n")] = 0;
    printf("Hello, %s! Welcome!\n", name);
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