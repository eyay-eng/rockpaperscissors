#include "leaderboard.h"

FILE* leaderBoardFile;
const char* fileName = "leaderboard.txt";
char* accessMode = "a+";

void initLeaderboardFile()
{
    leaderBoardFile = fopen(fileName, accessMode);
    if(!leaderBoardFile){
        printf("Unable to open leaderboard file\n");
        exit(1);
    }
}

void deinitLeaderboardFile()
{
    fclose(leaderBoardFile);
}

void updateFileLeaderBoard(userStats_t player1)
{
    //Open File
    initLeaderboardFile();
    //add Player info
    fprintf(leaderBoardFile,"{USER: %s"
        ", GAMESPLAYED: %u"
        ", WINS: %u"
        ", LOSSES: %u"
        ", TIES: %u}\n", 
        player1.name, player1.gamesPlayed, player1.totalWins, player1.totalLoss, player1.totalTies);
    //close file
    deinitLeaderboardFile();
}

void getTopScore()
{
    const char* modeRead = "r";
    leaderBoardFile = fopen(fileName, modeRead);

    char fileBuffer[8192];
    char ch;
    int lineNum = 0;
    int charNum = 0;
    while ((ch = fgetc(leaderBoardFile)) != EOF) {
        if(ch == '\n'){
            lineNum++;
        }
        //printf("%c", ch);
        fileBuffer[charNum] = ch;
        charNum++;
    }

    char numBuf[32];
    for(int i = 0; i < 32; i++)
    {
        numBuf[i] = 0;
    }
    int numBufIdx = 0;
    int inDataFlag = 0;
    int leaderFlag = 0;
    
    userStats_t topScore;
    topScore.gamesPlayed = 0;
    topScore.totalWins = 0;
    topScore.totalLoss = 0;
    topScore.totalTies = 0;
    userStats_t tempScore;
    tempScore.gamesPlayed = 0;
    tempScore.totalWins = 0;
    tempScore.totalLoss = 0;
    tempScore.totalTies = 0;
    

    for(int i = 0; i<charNum;i++)
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

    fclose(leaderBoardFile);
    printf("Leader: %s\n", topScore.name);
    printf("Top Score: %d\n",topScore.totalWins);
}

