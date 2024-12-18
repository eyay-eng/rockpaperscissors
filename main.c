#include <stdio.h>
#include <stdlib.h>
#include "rockpaperscissors.h"



int main(){

    //Gameplay inputs
    int userChoice, comSelect, matchWinner, totalWins, totalLosses, totalTies;

    struct userStats_t player1;
    player1.totalLoss = 0;
    player1.totalWins = 0;
    player1.totalTies = 0;

    //Leaderboard information
    FILE* leaderBoard;
    const char fileName[] = "leaderboard.txt";
    const char accessMode[] = "a+";
    leaderBoard = fopen(fileName, accessMode);
    if(!leaderBoard){
        printf("Unable to open leaderboard file\n");
        exit(1);
    }


    getUserName(player1.name, NAME_BUFFER_SIZE);
    printf("Hello, %s! Welcome!\n", player1.name);
    //Main gameplay loop
    mainGameplayProc(&player1);

    //Update leaderboard file
    fprintf(leaderBoard,"{USER: %s"
    ", WINS:   %lu"
    ", LOSSES: %lu"
    ", TIES:   %lu}\n", 
    player1.name, player1.totalWins, player1.totalLoss, player1.totalTies);


    printf("Updating Leaderboard!\n");
    //TODO update leaderboard with game statistics

    printf("Thanks for playing!");

    return 0;
}