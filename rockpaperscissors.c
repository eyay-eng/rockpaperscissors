#include "rockpaperscissors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH   1000
#define COMPUTER_WIN      0
#define USER_WIN          1
#define TIE               3

//print options for selection
void outputSelectOpt(){
    printf("Select from options:\n"
    "[1] Rock\n"
    "[2] Paper\n"
    "[3] Scissors\n");
}

int getUserSelect(){
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
        if(userSel == 1 || userSel == 2 || userSel == 3){
            return(userSel);
        }
        else{
            printf("invalid input: Entry must be 1,2 or 3");
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
int generateVirtualSelect(){
/* random int between 1 and 3 */
    int comSelect= (rand() % 2)+1;
    return(comSelect);
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
                return(TIE);
            else if(comInput == 2)
                return(COMPUTER_WIN);
            else
                return(USER_WIN);
        case 3:
            if (comInput == 1)
                return(TIE);
            else if(comInput == 2)
                return(COMPUTER_WIN);
            else
                return(USER_WIN);
            
                
    }
    return(0);
}