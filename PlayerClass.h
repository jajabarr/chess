//
//  PlayerClass.h
//  Chess 2.0
//
//  Created by Jacob Barr on 2/24/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#ifndef PlayerClass_h
#define PlayerClass_h

#include <stdio.h>
#include <string>
using namespace std;

const int MAX_SIZE = 99;
const string DELETE_ALL = "uuddlrlrba";



class player {
public:
    player();
    int getPosition() const;
    void setPosition(int position);
    int getSide() const;
    void setSide(int side);
    string getName() const;
    void setName(string name);
    void addLeader(player newPlayer, player leaderBoard[MAX_SIZE]);
    void incrementPosition();

    
private:
    int playerPosition;
    int playerSide;
    string playerName;
};


#endif /* PlayerClass_h */
