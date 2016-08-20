//
//  SideClass.cpp
//  Chess 2.0
//
//  Created by Jacob Barr on 2/24/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#include "SideClass.h"
#include "PlayerClass.h"
using namespace std;

void side::setSide(player player, int side) {
    
    playerSide = side;
}

int side::getSide() const {
    
    return playerSide;
}