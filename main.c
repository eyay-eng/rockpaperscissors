#include <stdio.h>
#include <stdlib.h>

#include "rockpaperscissors.h"
#include "statemachine.h"


int main(){

   //Init Game Data
    struct userStats_t player1;
    player1.totalLoss = 0;
    player1.totalWins = 0;
    player1.totalTies = 0;
    player1.gamesPlayed = 0;

    //Init Leaderboard Leaderboard information
    FILE* leaderBoard;
    const char fileName[] = "leaderboard.txt";
    const char accessMode[] = "a+";
    leaderBoard = fopen(fileName, accessMode);
    if(!leaderBoard){
        printf("Unable to open leaderboard file\n");
        exit(1);
    }

    //Initialize State Machine
    struct state state = {init_game, &player1};
    while (state.next) state.next(&state);


    // getUserName(player1.name, NAME_BUFFER_SIZE);
    // printf("Hello, %s! Welcome!\n", player1.name);

    //Update leaderboard file
    fprintf(leaderBoard,"{USER: %s"
    ", GAMESPLAYED: %ld"
    ", WINS:   %lu"
    ", LOSSES: %lu"
    ", TIES:   %lu}\n", 
    player1.name, player1.gamesPlayed, player1.totalWins, player1.totalLoss, player1.totalTies);


    printf("Updating Leaderboard!\n");
    //TODO update leaderboard with game statistics

    printf("Thanks for playing!");

    return 0;
}