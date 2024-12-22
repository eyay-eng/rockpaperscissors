#include "statemachine.h"
#include "rockpaperscissors.h"
#include <stdio.h>
#include <stdlib.h>



void init_game(struct state *state)
{
    system("cls");
    getUserName(state->player1->name, NAME_BUFFER_SIZE);
    state->next = main_menu_state;
}

void main_menu_state(struct state *state)   
{
    int mainSelect = 0;

    printf("Hello, %s! Welcome!\n", state->player1->name);
    printf("Main Menu:\n");
    printf("[1] Play Game\n");
    printf("[2] Exit\n");

    getUserSelect(&mainSelect,1,2);
    if(mainSelect == 1){state->next = play_game_state;}
    if(mainSelect == 2){ state->next = 0;}
}

void play_game_state(struct state *state)
{
    mainGameplayProc(state->player1);
    state->next = main_menu_state;
}