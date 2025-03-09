#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
    const char* fileName = "leaderboard.txt";
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
    ", GAMESPLAYED: %u"
    ", WINS: %u"
    ", LOSSES: %u"
    ", TIES: %u}\n", 
    player1.name, player1.gamesPlayed, player1.totalWins, player1.totalLoss, player1.totalTies);
    fclose(leaderBoard);

    printf("Updating Leaderboard!\n");

    //TODO update leaderboard with game statistics

    const char* modeRead = "r";
    leaderBoard = fopen(fileName, modeRead);

    char fileBuffer[1024];
    char ch;
    int lineNum = 0;
    int charNum = 0;
    while ((ch = fgetc(leaderBoard)) != EOF) {
        if(ch == '\n'){
            lineNum++;
        }
        //printf("%c", ch);
        fileBuffer[charNum] = ch;
        charNum++;
        if (lineNum == 10)
        {
            break;
        }
    }

   
    enum leadBoardFlags{
        USERFLAG,
        GAMESPLAYEDFLAG,
        WINSFLAG,
        LOSSESFLAG,
        TIESFLAG
    };

    char numBuf[32];
    for(int i = 0; i < 32; i++)
    {
        numBuf[i] = 0;
    }
    int numBufIdx = 0;
    int inDataFlag = 0;
    int leaderFlag = 0;

    
    
    struct userStats_t topScore;
    topScore.gamesPlayed = 0;
    topScore.totalWins = 0;
    topScore.totalLoss = 0;
    topScore.totalTies = 0;
    struct userStats_t tempScore;
    tempScore.gamesPlayed = 0;
    tempScore.totalWins = 0;
    tempScore.totalLoss = 0;
    tempScore.totalTies = 0;
    

    for(int i = 0; i<(int)sizeof(fileBuffer);i++)
    {
        if(fileBuffer[i] == ':')
        {
            inDataFlag = 1;
            i+=2;
        }
        //Reset flags and local buffers
        if(fileBuffer[i] == ',')
        {
            inDataFlag = 0;
            leaderFlag++;
            numBufIdx = 0;
            for(int i = 0; i < 32; i++)
            {
                numBuf[i] = 0;
            }
            
            
        }
        //Once completed reading line compare temp and top score
        if(fileBuffer[i] == '\n')
        {
            if(tempScore.totalWins > topScore.totalWins)
            {
                topScore = tempScore;
            }
            tempScore.gamesPlayed = 0;
            tempScore.totalWins = 0;
            tempScore.totalLoss = 0;
            tempScore.totalTies = 0;
            for(int i = 0; i<NAME_BUFFER_SIZE; i++)
            {
                tempScore.name[i] = 0;
            }
            leaderFlag = 0;
            inDataFlag = 0;
            numBufIdx = 0;
        }

        //Compare Top Score to Temp Score at end of line
        if(inDataFlag)
        {
            //Read data into correct buffer depending on 
            if(leaderFlag == USERFLAG && inDataFlag)
            {
                tempScore.name[numBufIdx] = fileBuffer[i];
                numBufIdx++;       
            }
            //Build Char buffer and scan into correct address
            if(leaderFlag == GAMESPLAYEDFLAG && inDataFlag)
            {
                numBuf[numBufIdx] = fileBuffer[i];
                sscanf(numBuf, "%d", &tempScore.gamesPlayed);
                numBufIdx++;       
            }
            if(leaderFlag == WINSFLAG && inDataFlag)
            {
                numBuf[numBufIdx] = fileBuffer[i];
                sscanf(numBuf, "%d", &tempScore.totalWins);
                numBufIdx++;       
            }
            if(leaderFlag == LOSSESFLAG && inDataFlag)
            {
                numBuf[numBufIdx] = fileBuffer[i];
                sscanf(numBuf, "%d", &tempScore.totalLoss);
                numBufIdx++;       
            }
            if(leaderFlag == TIESFLAG && inDataFlag)
            {
                numBuf[numBufIdx] = fileBuffer[i];
                sscanf(numBuf, "%d", &tempScore.totalTies);
                numBufIdx++;       
            }
        }
        
    }

    fclose(leaderBoard);
    printf("Leader: %s\n", topScore.name);
    printf("Top Score: %d\n",topScore.totalWins);


    printf("Thanks for playing!\n");
    // printf("Number of entries in leaderboard: %u\n",count);

    return 0;
}