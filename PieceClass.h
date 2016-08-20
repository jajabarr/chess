//
//  PieceClass.h
//  Chess 2.0
//
//  Created by Jacob Barr on 2/24/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#ifndef PieceClass_h
#define PieceClass_h

#include <stdio.h>



class piece {
public:
    piece();
    void setType(char type);
    void setSide(int side);
    void setMove(bool hasMoved);
    bool checkMove(int rowVal, int colVal, bool attacking = false, bool otherTeam = true, bool obstruct = false);
    char getType() const;
    int getSide() const;
    bool getHasMoved() const;

private:
    char pieceType;
    bool pieceMove;
    int pieceSide;
};


#endif /* PieceClass_h */
