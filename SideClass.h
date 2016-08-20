//
//  SideClass.h
//  Chess 2.0
//
//  Created by Jacob Barr on 2/24/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#ifndef SideClass_h
#define SideClass_h

#include <stdio.h>
#include "PlayerClass.h"
using namespace std;

class side {
public:
    void setSide(player player, int side);
    int getSide() const;
    
private:
    int playerSide;
};

#endif /* SideClass_h */
