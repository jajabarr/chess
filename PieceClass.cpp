//
//  PieceClass.cpp
//  Chess 2.0
//
//  Created by Jacob Barr on 2/24/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#include "PieceClass.h"
#include "BoardUtilities.h"
#include <cctype>
#include <cmath>

using namespace std;

piece::piece() {
    
    pieceType = ' ';
    pieceMove = false;
    pieceSide = 2;
}

void piece::setType(char type) {
    
    pieceType = toupper(type);
}

void piece::setSide(int side) {
    
    pieceSide = side;
}

void piece::setMove(bool hasMoved) {
    
    pieceMove = hasMoved;
}

int piece::getSide() const {
    
    return pieceSide;
}

char piece::getType() const {
    
    return pieceType;
}

bool piece::getHasMoved() const {
    
    return pieceMove;
    
}

bool piece::checkMove(int rowVal, int colVal, bool attacking, bool otherTeam,
                      bool obstruct) {
    
    bool validMove = false;
    int absRow = fabs(rowVal);
    colVal = fabs(colVal);
    
    
    if (pieceType == 'P') {
        
        if (!pieceMove && !attacking && !obstruct) {
            
            if ((rowVal <= 2) && (rowVal > 0) &&
                (colVal == 0)) {
                
                validMove = true;
                
            }
            
        } else if (pieceMove && !attacking && !obstruct) {
            
            if ((rowVal <= 1) && (rowVal > 0) &&
                (colVal == 0)) {
                
                validMove = true;
            }
            
        } else if (attacking) {
            
            if ((rowVal <=1) && (rowVal > 0) &&
                (colVal == 1)) {
                
                validMove = true;
            }
        }
        
    } else if (pieceType == 'N') {
        
        if ((absRow == 2) && (colVal == 1)) {
            
            validMove = true;
            
        } else if ((absRow == 1) && (colVal == 2)) {
            
            validMove = true;
        }
        
    } else if (pieceType == 'B') {
        
        if ((absRow <= BOARD_SIZE) && (absRow > 0) && (colVal == absRow) && !obstruct) {
            
            validMove = true;
        }
        
    } else if (pieceType == 'R') {
        
        if ((absRow <= 8) && (absRow > 0) && (colVal == 0) &&
            !obstruct) {
            
            validMove = true;
            
        } else if ((absRow == 0) && (colVal <= 8) && (colVal > 0) &&
                   !obstruct) {
            
            validMove = true;
        }
    } else if (pieceType == 'Q') {
        
        if ((absRow <= 8) && (absRow > 0) && (colVal == absRow) &&
            !obstruct) {
            
            validMove = true;
            
        } else if((absRow <= 8) && (absRow > 0) && (colVal == 0) &&
                  !obstruct) {
            
            validMove = true;
            
        } else if ((absRow == 0) && (colVal <= 8) && (colVal > 0) &&
                   !obstruct) {
            
            validMove = true;
        }

    } else if (pieceType == 'K') {
        
        if ((absRow <= 1) && (absRow >= 0) &&
            (colVal <= 1) && (colVal > 0)) {
            
            validMove = true;
            
        } else if ((absRow <= 1) && (absRow > 0) &&
                   (colVal <= 1) && (colVal >= 0)) {
            
            validMove = true;
        }
    }
    
    validMove = (validMove && otherTeam);

    
    return validMove;
}

