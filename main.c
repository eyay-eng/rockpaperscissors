#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "rockpaperscissors.h"
#include "statemachine.h"
#include "leaderboard.h"


int main(){

   //Init Game Data
    userStats_t player1;
    player1.totalLoss = 0;
    player1.totalWins = 0;
    player1.totalTies = 0;
    player1.gamesPlayed = 0;

    //IniEt leaderBoardFile leaderBoardFile information
    //FILE *leaderBoardFile;
    //const char* fileName = "leaderBoardFile.txt";
    //const char accessMode[] = "a+";
    /*
    leaderBoardFile = fopen(fileName, accessMode);
    if(!leaderBoardFile){
        printf("Unable to open leaderBoardFile file\n");
        exit(1);
    }
    */

    //Initialize State Machine
    struct state state = {init_game, &player1};
    while (state.next) state.next(&state);

    //Update leaderboard file

    updateFileLeaderBoard(player1);

    printf("Updating Leaderboard!\n");

    getTopScore();
    
    printf("Thanks for playing!\n");

    return 0;
}