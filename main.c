#include <stdio.h>
#include "rockpaperscissors.h"

#define COMPUTER_WIN      0
#define USER_WIN          1
#define TIE               3

int main(){
    int userChoice, comSelect, matchWinner;

    int totalWins = 0;
    int totalLosses = 0;
    int totalTies = 0;

    getUserName();
    for(;;){
        outputSelectOpt();
        userChoice = getUserSelect();
        if (userChoice ==4)
        {
            break;
        }
        
        comSelect = generateVirtualSelect();
        switch(comSelect){
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
        
        matchWinner = findWinner(&userChoice, &comSelect);

        switch(matchWinner){
            case COMPUTER_WIN:
                printf("COMPUTER WINS!\n\n");
                totalLosses++;
                break;
            case USER_WIN:
                printf("USER WINS!\n\n");
                totalWins++;
                break;
            case TIE:
                printf("MATCH WAS TIE!\n\n");
                totalTies++;
                break;
        }
        printf("SCOREBOARD: \n"
            "WINS:   %d \n"
            "LOSSES: %d \n"
            "TIES:   %d \n", 
            totalWins, totalLosses, totalTies);
        
        //reset user input
        comSelect = 0;
        userChoice = 0;
    }
    printf("Thanks for playing!");

    return 0;
}