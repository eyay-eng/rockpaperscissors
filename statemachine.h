#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "rockpaperscissors.h"

struct state;
typedef void state_fn(struct state *);

struct state{
    state_fn *next;
    userStats_t *player1;
};

state_fn init_game, main_menu_state, play_game_state;

void init_game(struct state *state);

void main_menu_state(struct state *state);

void play_game_state(struct state *state);

#endif /*ROCKPAPERSCISSORS_H*/