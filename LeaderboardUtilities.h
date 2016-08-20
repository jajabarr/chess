//
//  LeaderboardUtilities.h
//  Chess 2.0
//
//  Created by Jacob Barr on 2/24/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#ifndef LeaderboardUtilities_h
#define LeaderboardUtilities_h

#include <stdio.h>
#include "PlayerClass.h"
#include "BoardUtilities.h"

const int LEADERS_SIZE = 99;

void GetLeaderBoard(player playersList[LEADERS_SIZE]);
void GetTopTen();
void insertLeaderBoard(player playerList[LEADERS_SIZE]);
void orderLeaderBoard(player leaderBoard[LEADERS_SIZE]);
bool checkReusedName(string p1, player players[LEADERS_SIZE]);





#endif /* LeaderboardUtilities_h */
