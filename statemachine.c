#include "statemachine.h"
#include "rockpaperscissors.h"
#include <stdio.h>

void init_game(struct state *state)
{
    getUserName(state->player1->name, NAME_BUFFER_SIZE);
    printf("Hello, %s! Welcome!\n", state->player1->name);
    state->next = main_menu_state;
}

void main_menu_state(struct state *state)
{
    printf("main menu state!\n");
    state->next = play_game_state;
}

void play_game_state(struct state *state)
{
    mainGameplayProc(state->player1);
    state->next = main_menu_state;
}