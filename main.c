#include <stdio.h>
#include "rockpaperscissors.h"

#define COMPUTER_WIN      0
#define USER_WIN          1
#define TIE               3

int main(){
    int userChoice;
    int comSelect;
    int matchWinner;

    getUserName();
    for(;;){
        outputSelectOpt();
        userChoice = getUserSelect();
        printf("user selection was: %d\n", userChoice);

        comSelect = generateVirtualSelect();
        printf("Computer chose: %d\n",comSelect);
        
        matchWinner = findWinner(&userChoice, &comSelect);

        switch(matchWinner){
            case COMPUTER_WIN:
                printf("COMPUTER WINS!\n\n");
                break;
            case USER_WIN:
                printf("USER WINS!\n\n");
                break;
            case TIE:
                printf("MATCH WAS TIE!\n\n");
                break;
        }     
        
        //reset user input
        comSelect = 0;
        userChoice = 0;
    }
    return 0;
}