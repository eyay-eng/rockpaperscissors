#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <stdio.h>
#include <stdlib.h>
#include "rockpaperscissors.h"



enum leadBoardFlags{
    USERFLAG,
    GAMESPLAYEDFLAG,
    WINSFLAG,
    LOSSESFLAG,
    TIESFLAG
};

void initLeaderboardFile(char* accessMode);

void updateFileLeaderBoard(userStats_t player1);

void deinitLeaderboardFile(void);

void getTopScore(void);

#endif /*LEADBOARD_H*/