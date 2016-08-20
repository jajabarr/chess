//
//  BoardUtilities.cpp
//  Chess 2.0
//
//  Created by Jacob Barr on 2/24/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#include "BoardUtilities.h"
#include "PieceClass.h"
#include <iostream>
#include <cmath>
using namespace std;

void makeDefaultBoard(char board[BOARD_Y][BOARD_X]) {
    
    char xCoord[BOARD_X];
    char yCoord[BOARD_Y];
    char topLine[BOARD_X];
    char midLineAllPlus[BOARD_X];
    char midLine2Plus[BOARD_X];
    char midLineAllPlusB[BOARD_X];
    char midLine2PlusB[BOARD_X];
    
    char formBoard[BOARD_Y][BOARD_X];

    int i = 0;
    int j = 0;
    
    char space = ' ';
    char dash = '-';
    char plus = '+';
    char cut = '|';
    
    char num = '8';
    char alpha = 'a';
    
    
    for (i = 0; i < BOARD_Y; i++) {
        
        yCoord[i] = space;
        
        if (i == 2) {
            
            yCoord[i] = num;
            
            num--;
            
        } else if ((i - 2) % 4 == 0) {
            
            yCoord[i] = num;
            
            num--;
        }
        
        if (i > BOARD_Y - Y_SPACE + 1) {
            
            yCoord[i] = space;
        }
    }
    
    for (i = 0; i < BOARD_X; i++) {
        
        xCoord[i] = space;
        
        if (i == X_SPACE) {
            
            xCoord[i] = alpha;
            
            alpha++;
            
        } else if ((i - X_SPACE) % 9 == 0) {
            
            xCoord[i] = alpha;
            
            alpha++;
        }
    }
    
    
    
    for (i = 0; i < BOARD_X; i++) {
        
        while (i <= 2) {
            
            topLine[i] = space;
            midLineAllPlus[i] = space;
            midLine2Plus[i] = space;
            midLineAllPlusB[i] = space;
            midLine2PlusB[i] = space;
            
            i++;
            
            if (i == 2) {
                
                topLine[i] = plus;
                midLineAllPlus[i] = cut;
                midLine2Plus[i] = cut;
                midLineAllPlusB[i] = cut;
                midLine2PlusB[i] = cut;
                
                i++;
            }
        }
        
        topLine[i] = dash;
        midLineAllPlus[i] = space;
        midLine2Plus[i] = space;
        midLineAllPlusB[i] = space;
        midLine2PlusB[i] = space;

        
        if ((i - 2) % 9 == 0) {
            
            topLine[i] = plus;
            midLineAllPlus[i] = cut;
            midLine2Plus[i] = cut;
            midLineAllPlusB[i] = cut;
            midLine2PlusB[i] = cut;

        }
        
        if (((i - 12) % 18 == 0) ||
            ((i - 13) % 18 == 0) ||
            ((i - 18) % 18 == 0) ||
            ((i - 19) % 18 == 0)) {
            
            midLineAllPlusB[i] = plus;
        }
        
        if (((i - 12) % 18 == 0) || ((i - 19) % 18 == 0)) {
            
            midLine2PlusB[i] = plus;
        }
        
       
        if (((i - 10) % 18 == 0) ||
            ((i - 9) % 18 == 0) ||
            ((i - 4) % 18 == 0) ||
            ((i - 3) % 18 == 0)) {
            
            midLineAllPlus[i] = plus;
        }
        
        if (((i - 3) % 18 == 0) || ((i - 10) % 18 == 0)) {
            
            midLine2Plus[i] = plus;
        }
    }
    
    for (i = 0; i < BOARD_Y; i++) {
            
        switch (i) {
            case 0:
            case 4:
            case 8:
            case 12:
            case 16:
            case 20:
            case 24:
            case 28:
            case 32:
                    
                for (j = 0; j < BOARD_X; j++) {
                    
                    formBoard[i][j] = topLine[j];
                }
                
                break;
                
            case 1:
            case 3:
            case 9:
            case 11:
            case 17:
            case 19:
            case 25:
            case 27:
                
                for (j = 0; j < BOARD_X; j++) {
                    
                    formBoard[i][j] = midLineAllPlus[j];
                }
                
                break;
                
            case 2:
            case 10:
            case 18:
            case 26:
                
                for (j = 0; j < BOARD_X; j++) {
                    
                    formBoard[i][j] = midLine2Plus[j];
                }
                
                break;
                
            case 5:
            case 7:
            case 13:
            case 15:
            case 21:
            case 23:
            case 29:
            case 31:
                
                for (j = 0; j < BOARD_X; j++) {
                    
                    formBoard[i][j] = midLineAllPlusB[j];
                }
                
                break;
                
            case 6:
            case 14:
            case 22:
            case 30:
                
                for (j = 0; j < BOARD_X; j++) {
                    
                    formBoard[i][j] = midLine2PlusB[j];
                }
                
                break;

            case 33:
            case 34:
            default:
                break;
        }
    }

    for (i = 0; i < BOARD_X; i++) {
        
        formBoard[33][i] = space;
        formBoard[34][i] = space;
    }
    
    
    
    for (i = 0; i < BOARD_Y; i++) {
        
        for (j = 0; j < BOARD_X; j++) {
            
            formBoard[33][j] = xCoord[j];
        }
        
        formBoard[i][0] = yCoord[i];
    }
    
    
    copyBoard(formBoard, board);
    
    
    
    return;
    
}

void copyBoard(const char originalBoard[][BOARD_X], char newBoard[][BOARD_X]) {
    
    for (int i = 0; i < BOARD_Y; i++) {
        
        for (int j = 0; j < BOARD_X; j++) {
            
            newBoard[i][j] = originalBoard[i][j];
        }
    }
    
}

void getPieceBoard(piece pieceBoard[BOARD_SIZE][BOARD_SIZE_X]) {
    
    int i = 0;
    int j = 0;
    
    piece pawn1;
    piece pawn2;
    piece pawn3;
    piece pawn4;
    piece pawn5;
    piece pawn6;
    piece pawn7;
    piece pawn8;
    piece pawn1b;
    piece pawn2b;
    piece pawn3b;
    piece pawn4b;
    piece pawn5b;
    piece pawn6b;
    piece pawn7b;
    piece pawn8b;
    
    piece rook;
    piece rookb;
    
    piece bishop;
    piece bishopb;
    
    piece knight;
    piece knightb;
    
    piece queen;
    piece queenb;
    
    piece king;
    piece kingb;
    
    piece space;
    piece hashWhite;
    piece hash;
    
    space.setType(' ');
    space.setSide(2);
    
    hashWhite.setType(' ');
    hashWhite.setSide(1);
    
    hash.setType('#');
    hash.setSide(0);
    
    pawn1.setType('P');
    pawn2.setType('P');
    pawn3.setType('P');
    pawn4.setType('P');
    pawn5.setType('P');
    pawn6.setType('P');
    pawn7.setType('P');
    pawn8.setType('P');
    pawn1b.setType('P');
    pawn2b.setType('P');
    pawn3b.setType('P');
    pawn4b.setType('P');
    pawn5b.setType('P');
    pawn6b.setType('P');
    pawn7b.setType('P');
    pawn8b.setType('P');
    pawn1.setSide(1);
    pawn2.setSide(1);
    pawn3.setSide(1);
    pawn4.setSide(1);
    pawn5.setSide(1);
    pawn6.setSide(1);
    pawn7.setSide(1);
    pawn8.setSide(1);
    pawn1b.setSide(0);
    pawn2b.setSide(0);
    pawn3b.setSide(0);
    pawn4b.setSide(0);
    pawn5b.setSide(0);
    pawn6b.setSide(0);
    pawn7b.setSide(0);
    pawn8b.setSide(0);
    pawn1.setMove(false);
    pawn2.setMove(false);
    pawn3.setMove(false);
    pawn4.setMove(false);
    pawn5.setMove(false);
    pawn6.setMove(false);
    pawn7.setMove(false);
    pawn8.setMove(false);
    pawn1b.setMove(false);
    pawn2b.setMove(false);
    pawn3b.setMove(false);
    pawn4b.setMove(false);
    pawn5b.setMove(false);
    pawn6b.setMove(false);
    pawn7b.setMove(false);
    pawn8b.setMove(false);

    
    rook.setType('R');
    rookb.setType('R');
    rook.setSide(1);
    rookb.setSide(0);
    
    bishop.setType('B');
    bishopb.setType('B');
    bishop.setSide(1);
    bishopb.setSide(0);
    
    knight.setType('N');
    knightb.setType('N');
    knight.setSide(1);
    knightb.setSide(0);
    
    queen.setType('Q');
    queenb.setType('Q');
    queen.setSide(1);
    queenb.setSide(0);
    
    king.setType('K');
    kingb.setType('K');
    king.setSide(1);
    kingb.setSide(0);
    
    for (i = 0; i < BOARD_SIZE; i++) {
        
        for (j = 0; j < BOARD_SIZE_X; j++) {
            
            pieceBoard[i][j] = space;
        }
    }
    
    pieceBoard[0][1] = rookb;
    pieceBoard[0][3] = knightb;
    pieceBoard[0][5] = bishopb;
    pieceBoard[0][7] = queenb;
    pieceBoard[0][9] = kingb;
    pieceBoard[0][11] = bishopb;
    pieceBoard[0][13] = knightb;
    pieceBoard[0][15] = rookb;

    pieceBoard[1][1] = pawn1b;
    pieceBoard[1][3] = pawn2b;
    pieceBoard[1][5] = pawn3b;
    pieceBoard[1][7] = pawn4b;
    pieceBoard[1][9] = pawn5b;
    pieceBoard[1][11] = pawn6b;
    pieceBoard[1][13] = pawn7b;
    pieceBoard[1][15] = pawn8b;
    
    pieceBoard[7][1] = rook;
    pieceBoard[7][3] = knight;
    pieceBoard[7][5] = bishop;
    pieceBoard[7][7] = queen;
    pieceBoard[7][9] = king;
    pieceBoard[7][11] = bishop;
    pieceBoard[7][13] = knight;
    pieceBoard[7][15] = rook;
    
    pieceBoard[6][1] = pawn1;
    pieceBoard[6][3] = pawn2;
    pieceBoard[6][5] = pawn3;
    pieceBoard[6][7] = pawn4;
    pieceBoard[6][9] = pawn5;
    pieceBoard[6][11] = pawn6;
    pieceBoard[6][13] = pawn7;
    pieceBoard[6][15] = pawn8;
    
    for (i = 0; i < BOARD_SIZE; i++) {
        
        for (j = 1; j < BOARD_SIZE_X; j += 2) {
            
            if (pieceBoard[i][j].getSide() == 0) {
                
                pieceBoard[i][j - 1] = hash;
                
            } else {
                
                pieceBoard[i][j - 1] = hashWhite;
            }
        }
    }
    
     return;
}

void insertDefaultPositions(piece pieceBoard[][BOARD_SIZE_X], char board[][BOARD_X]) {
    
    int i = 0;
    int j = 0;
    int xCount = 1;
    int yCount = 0;
    char insertChar = '-';
    
    getPieceBoard(pieceBoard);
    
    makeDefaultBoard(board);
    
    
    for (i = BOARD_START_Y; i < BOARD_Y; i += BOARD_DIFF_Y) {
        
        for (j = BOARD_START_X; j < BOARD_X; j+= BOARD_DIFF_X) {
            
            insertChar = pieceBoard[yCount][xCount].getType();
            
            board[i][j] = insertChar;
            
            insertChar = pieceBoard[yCount][xCount - 1].getType();
            
            board[i][j - 1] = insertChar;
            
            xCount += 2;
            
        }
        
        xCount = 1;
        
        yCount++;

    }
    
    
    
    return;
    
}

void printBoard(char board[BOARD_Y][BOARD_X]) {
    
    int i = 0;
    int j = 0;
    
    for (i = 0; i < BOARD_Y; i++) {
        
        for (j = 0; j < BOARD_X; j++) {
            
            cout << board[i][j];
        }
        
        cout << endl;
    }
    
    cout << endl;
    
    return;
}

void convertPieceBoard(int& col1, int& row1, int& col2, int& row2) {
    
    col1 = ((col1 * 2) - 1);
    col2 = ((col2 * 2) - 1);
    row1--;
    row2--;
    
    row1 = fabs(row1 - 7);
    row2 = fabs(row2 - 7);

}

void updateBoard(char board[][BOARD_X], piece pieceBoard[][BOARD_SIZE_X],
                 int row1, int col1, int row2, int col2, piece& lastPiece) {
    
    int i = 0;
    int j = 0;
    int xCount = 1;
    int yCount = 0;
    char insertChar = '-';
    
    int rowA = row1;
    int rowB = row2;
    int colA = col1;
    int colB = col2;
    
    piece space;
    piece hash;
    piece hashWhite;
    
    space.setType(' ');
    space.setSide(2);
    
    hash.setType('#');
    hash.setSide(0);
    
    hashWhite.setType(' ');
    hashWhite.setSide(1);
    
    
    if ((row1 == 0) && (row2 == 0) && (col1 == 0) && (col2 == 0)) {
        
    } else {
        
        convertPieceBoard(colA, rowA, colB, rowB);
    
        lastPiece = pieceBoard[rowB][colB];
    
        pieceBoard[rowB][colB] = pieceBoard[rowA][colA];
    
        pieceBoard[rowA][colA] = space;
    }
    
    
    for (i = 0; i < BOARD_SIZE; i++) {
        
        for (j = 1; j < BOARD_SIZE_X; j += 2) {
            
            if (pieceBoard[i][j].getSide() == 0) {
                
                pieceBoard[i][j - 1] = hash;
                
            } else if (pieceBoard[i][j].getSide() == 1) {
                
                pieceBoard[i][j - 1] = hashWhite;
                
            } else {
                
                pieceBoard[i][j - 1] = space;
            }
        }
    }


    
    for (i = BOARD_START_Y; i < BOARD_Y; i += BOARD_DIFF_Y) {
        
        for (j = BOARD_START_X; j < BOARD_X; j+= BOARD_DIFF_X) {
            
            insertChar = pieceBoard[yCount][xCount].getType();
            
            board[i][j] = insertChar;
            
            insertChar = pieceBoard[yCount][xCount - 1].getType();
            
            board[i][j - 1] = insertChar;
            
            xCount += 2;
            
        }
        
        xCount = 1;
        
        yCount++;
        
    }
    
    
    
    
    return;
    
}

int oppositePiece(piece pieceSide) {
    
    int side = 2;
    
    if (pieceSide.getSide() == 0) {
        
        side = 1;
        
    } else if (pieceSide.getSide() == 1) {
        
        side = 0;
    }
    
    return side;
}

void clearStream() {
    
    string trash;
    cin.clear();
    getline(cin, trash);
}




