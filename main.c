#include <stdio.h>
#include <stdlib.h>
#include "rockpaperscissors.h"

struct state;
typedef void state_fn(struct state *);

struct state{
    state_fn *next;
    struct userStats_t *player1;
};

state_fn init_game, main_menu_state, play_game_state;

void init_game(struct state *state)
{
    getUserName(state->player1->name, NAME_BUFFER_SIZE);
    printf("Hello, %s! Welcome!\n", state->player1->name);
    state->next = main_menu_state;
}

void main_menu_state(struct state *state)
{
    printf("main menu state!");
    state->next = play_game_state;
}

void play_game_state(struct state *state)
{
    mainGameplayProc(state->player1);
    state->next = main_menu_state;
}


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

    mainGameplayProc(&player1);

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