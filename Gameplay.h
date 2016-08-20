//
//  Gameplay.hpp
//  Chess 2.0
//
//  Created by Jacob Barr on 2/29/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#ifndef Gameplay_h
#define Gameplay_h

#include <string>
#include <stdio.h>
#include "BoardUtilities.h"
#include "LeaderboardUtilities.h"
#include "PieceClass.h"
#include "PlayerClass.h"

using namespace std;

const int ASCII_NUM = 48;
const int ASCII_CHAR = 96;

void newGame();
void boardMenu();
void getBoardMenuChoice(int& row1, int& col1, int& row2, int& col2,
                        int& escape, char board[][BOARD_X],
                        piece pieceBoard[][BOARD_SIZE_X]
                        , player& nextPlayer);

bool checkBoardMenuChoice(string& choice, int& row1, int& col1,
                          int& row2, int& col2, int& escape
                          , piece pieceBoard[][BOARD_SIZE_X]
                          , player& nextPlayer
                          , bool& turn
                          , bool& move);

bool checkBoardMove(const int row1, const int col1, const int row2,
                    const int& col2, int& colc
                    ,piece pieceBoard[][BOARD_SIZE_X]);
bool checkObstruct(piece pieceBoard[][BOARD_SIZE_X], int row1, int row2,
                   int col1, int col2, bool& castle);

bool checkTurn(piece pieceBoard[][BOARD_SIZE_X], int row1, int col1
               ,player& nextPlayer);

bool escWarning();
bool menuWarning();
bool kingIsDead(piece piece, int& side);

void getPlayerNames(player& player1, player& player2
                    , player playerList[LEADERS_SIZE]);
void victorySpeech(player winner, player loser);
void castlePiece(piece pieceBoard[][BOARD_SIZE_X], int row1, int col1, int col2
                 ,int& colc);
void clearInput(string& coord, int& row1, int& col1, int& row2, int& col2);

bool checkPawn(piece pieceBoard[][BOARD_SIZE_X], player curPlayer);
void pieceMenu();
char newPiece();
#endif /* Gameplay_h */
