#include "tictactoe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

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

int generateVirtualSelect(){
/* random int between 1 and 3 */
    int comSelect= (rand() % 2)+1;
    return(comSelect);
}

//randomly select from 3 options

//compare user selection to generated option