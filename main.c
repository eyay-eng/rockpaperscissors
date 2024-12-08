#include <stdio.h>
#include "tictactoe.h"

#define COMPUTER_WIN    0
#define PLAYER_WIN      1

int main(){
    int userChoice;
    int comSelect;

    getUserName();
    for(;;){
        outputSelectOpt();
        userChoice = getUserSelect();
        printf("user selection was: %d\n", userChoice);

        comSelect = generateVirtualSelect();
        printf("Computer chose: %d\n",comSelect);
        

        //reset user input
        comSelect = 0;
        userChoice = 0;
    }
    return 0;
}