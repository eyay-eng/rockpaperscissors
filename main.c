#include <stdio.h>
#include <stdlib.h>
#include "rockpaperscissors.h"

#define COMPUTER_WIN      0
#define USER_WIN          1
#define TIE               3
#define EXIT              4





int main(){

    //Gameplay inputs
    int userChoice, comSelect, matchWinner, totalWins, totalLosses, totalTies;

    struct userStats_t player1;

    userChoice = 0;
    comSelect = 0;
    matchWinner = 0;
    totalWins = 0;
    totalLosses = 0;
    totalTies = 0;

    int nameBuffer = NAME_BUFFER_SIZE;
    //char name[NAME_BUFFER_SIZE];

    //Leaderboard information
    FILE* leaderBoard;
    const char fileName[] = "leaderboard.txt";
    const char accessMode[] = "a+";
    leaderBoard = fopen(fileName, accessMode);
    if(!leaderBoard){
        printf("Unable to open leaderboard file\n");
        exit(1);
    }


    getUserName(player1.name, &nameBuffer);
    printf("Hello, %s! Welcome!\n", player1.name);
    //Main gameplay loop
    for(;;){
        outputSelectOpt();
        getUserSelect(&userChoice);
        //Exit choice selection:
        if (userChoice == EXIT)
        {
            break;
        }
        generateVirtualSelect(&comSelect);
        
        
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
    }
    printf("Updating Leaderboard!\n");
    //TODO update leaderboard with game statistics

    printf("Thanks for playing!");

    return 0;
}