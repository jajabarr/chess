//
//  BoardUtilities.h
//  Chess 2.0
//
//  Created by Jacob Barr on 2/24/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#ifndef BoardUtilities_h
#define BoardUtilities_h

#include <stdio.h>
#include <cctype>
#include "PieceClass.h"
#include "PlayerClass.h"


const int BOARD_SIZE = 8;
const int BOARD_SIZE_X = 16;
const int BOARD_X = 75;
const int BOARD_Y = 34;
const int Y_SPACE = 5;
const int X_SPACE = 7;

const int BOARD_DIFF_X = 9;
const int BOARD_DIFF_Y = 4;

const int BOARD_START_X = 7;
const int BOARD_START_Y = 2;

const int BLACK_SIDE = 0;
const int WHITE_SIDE = 7;



void makeDefaultBoard(char board[][BOARD_X]);
void printBoard(char board[][BOARD_X]);
void copyBoard(const char originalBoard[][BOARD_X], char newBoard[][BOARD_X]);
void insertDefaultPositions(piece pieceBoard[][BOARD_SIZE_X], char board[][BOARD_X]);
void getPieceBoard(piece pieceBoard[BOARD_SIZE][BOARD_SIZE_X]);
void convertPieceBoard(int& col1, int& row1, int& col2, int& row2);
void updateBoard(char board[][BOARD_X], piece pieceBoard[][BOARD_SIZE_X],
                 int row1, int col1, int row2, int col2, piece& piece);
int oppositePiece(piece pieceSide);
void clearStream();



#endif /* BoardUtilities_h */
