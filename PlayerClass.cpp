//
//  PlayerClass.cpp
//  Chess 2.0
//
//  Created by Jacob Barr on 2/24/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#include "PlayerClass.h"
using namespace std;

player::player() {
    
    playerPosition = 0;
    playerSide = 2;
    playerName = " ";
}

void player::setPosition(int position) {
    
    playerPosition = position;
}

void player::setName(string name) {
    
    playerName = name;
}

void player::setSide(int side) {
    
    playerSide = side;
}


int player::getPosition() const {
    
    return playerPosition;
}

int player::getSide() const {
    
    return playerSide;
}

string player::getName() const {
    
    return playerName;
}

void player::incrementPosition() {
    
    playerPosition++;
    
    return;
}

void player::addLeader(player newPlayer, player leaderBoard[MAX_SIZE]) {
    
    bool alreadyIn = false;
    
    player defaultPlayer;
    
    for (int i = 0; i < MAX_SIZE; i++) {
        
        if (leaderBoard[i].getName() == newPlayer.getName()) {
            
            alreadyIn = true;
            
            i = MAX_SIZE;
        }
    }
    
    if (!alreadyIn) {
        
        for (int i = 0; i < MAX_SIZE; i++) {
            
            if (leaderBoard[i].getSide() == 2) {
                
                leaderBoard[i] = newPlayer;
                
                i = MAX_SIZE;
            }
        }

        
    }
    
    if (newPlayer.getName() == DELETE_ALL) {
            
        for (int j = 0; j < MAX_SIZE; j++) {
                
            leaderBoard[j] = defaultPlayer;
        }
        
    }
    
    
    
    return;
}