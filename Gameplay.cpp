//
//  Gameplay.cpp
//  Chess 2.0
//
//  Created by Jacob Barr on 2/29/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#include "Gameplay.h"
#include "PieceClass.h"
#include "BoardUtilities.h"
#include "OpenAndCloseCredits.h"
#include "PlayerClass.h"
#include <cctype>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

void newGame() {
    
    char chessBoard[BOARD_Y][BOARD_X];
    piece pieceBoard[BOARD_SIZE][BOARD_SIZE_X];
    player playersList[LEADERS_SIZE];
    
    GetLeaderBoard(playersList);
    
    player player1;
    player player2;
    player nextPlayer;
    
    nextPlayer.setSide(1);
    
    
    int row1 = 0;
    int row2 = 0;
    int esc = 0;
    int col1 = 0;
    int col2 = 0;
    
    piece lastPiece;
    
    lastPiece.setType(' ');
    
    int kingSide = 0;
    bool kingDead = false;
    bool mainMenu = false;
    
    
    getPlayerNames(player1, player2, playersList);

    clearScreen();
    
    
    insertDefaultPositions(pieceBoard, chessBoard);
    printBoard(chessBoard);
    
    kingDead = kingIsDead(lastPiece, kingSide);
    
    while (!kingDead && !mainMenu) {
        
        getBoardMenuChoice(row1, col1, row2, col2, esc, chessBoard, pieceBoard
                           , nextPlayer);
        
        if (esc == 1) {
            
            insertDefaultPositions(pieceBoard, chessBoard);
            nextPlayer.setSide(1);
            cin.get();
            cin.clear();
            clearScreen();
            printBoard(chessBoard);
            
            
        } else if (esc == 2) {
            
            mainMenu = true;
            nextPlayer.setSide(1);
            
        } else {
            
            updateBoard(chessBoard, pieceBoard, row1, col1, row2, col2
                        , lastPiece);
        
            if (checkPawn(pieceBoard, nextPlayer)) {
                
                updateBoard(chessBoard, pieceBoard, 0, 0, 0, 0
                            , lastPiece);

            }
        
            clearScreen();
            printBoard(chessBoard);
            
            if (nextPlayer.getSide() == 1) {
                
                nextPlayer.setSide(0);
                
            } else {
                
                nextPlayer.setSide(1);
            }

        
            kingDead = kingIsDead(lastPiece, kingSide);
            
            if (kingDead) {
                
                if (kingSide == player1.getSide()) {
                    
                    player2.incrementPosition();
                    orderLeaderBoard(playersList);
                    victorySpeech(player2, player1);
                    
                
                    
                
                } else {
                    
                    player1.incrementPosition();
                    orderLeaderBoard(playersList);
                    victorySpeech(player1, player2);
                    
                }
                
            }
            
        }

    }
    
    insertLeaderBoard(playersList);
    
    return;
}

void boardMenu() {
    
    cout << "Enter Coordinate Move (a1b1) or Menu Choice" << endl;
    cout << "[1] New Board     [2] Main Menu" << endl;
    cout << "Enter Choice: ";
    
    return;

}

void getBoardMenuChoice(int& row1, int& col1, int& row2, int& col2,
                        int& escape, char board[][BOARD_X],
                        piece pieceBoard[][BOARD_SIZE_X],
                        player& nextPlayer) {
    
    
    int rowA = 0;
    int rowB = 0;
    int esc = 0;
    int colA = 0;
    int colB = 0;
    
    bool correctTurn = false;
    bool correctMove = false;
    
    string entry;
   
    boardMenu();
    
    getline(cin, entry);
    
    while (!checkBoardMenuChoice(entry, rowA, colA, rowB, colB, esc,
                                 pieceBoard, nextPlayer, correctTurn
                                 ,correctMove)) {
        
        clearInput(entry, rowA, colA, rowB, colB);
        clearScreen();
        printBoard(board);
        
        cout << "          ";
        cout << "** Please enter an appropriate coordinate or menu option **";
        
        if (!correctTurn) {
            
            cout << endl;
            cout << "                         ";
            cout << "It's not your turn!";

            
        } else if (!correctMove) {
            
            cout << endl;
            cout << "                         ";
            cout << "Must enter a valid piece move";
        }

            
        cout << endl << endl;
        
        boardMenu();
        getline(cin, entry);
    }
    
    row1 = rowA;
    row2 = rowB;
    col1 = colA;
    col2 = colB;
    escape = esc;
    
    return;
}

bool checkBoardMenuChoice(string& choice, int& row1, int& col1,
                          int& row2, int& col2, int& escape
                          , piece pieceBoard[][BOARD_SIZE_X]
                          , player& nextPlayer
                          , bool& turn
                          , bool& move) {
    
    bool first = false;
    bool second = false;
    bool third = false;
    bool fourth = false;
    bool esc = false;
    
    int castleColumn = 0;
    
    if ((tolower(choice[0]) >= 'a') && (choice[0] <= 'h')) {

        first = true;
        
    }
    
    if ((choice[1] >= '1') && (choice[1] <= '8')) {
        
        second = true;
        
    }
    
    if ((tolower(choice[2]) >= 'a') && (choice[2] <= 'h')) {
        
        third = true;
    
    }
    
    if ((choice[3] >= '1') && (choice[3] <= '8')) {
        
        fourth = true;
    }
    
    if ((choice[0] == '1') && !second && !third && !fourth) {
        
        if (escWarning()) {
            
            escape = 1;
            esc = true;
            first = true;
            second = true;
            third = true;
            fourth = true;
            move = true;
            turn = true;
            
        }
        
        
    } else if ((choice[0] == '2') && !second && !third && !fourth) {
        
        if (menuWarning()) {
            
            escape = 2;
            esc = true;
            first = true;
            second = true;
            third = true;
            fourth = true;
            move = true;
            turn = true;
            
        }
        
    }
    
    if ( !esc && first && second && third && fourth) {
        
        col1 = (int)choice[0] - ASCII_CHAR;
        row1 = (int)choice[1] - ASCII_NUM;
        col2 = (int)choice[2] - ASCII_CHAR;
        row2 = (int)choice[3] - ASCII_NUM;
        
        castleColumn = col2;
        
        if (checkTurn(pieceBoard, row1, col1, nextPlayer)) {
            
            turn = true;
            
            if (checkBoardMove(row1, col1, row2, col2, castleColumn,
                               pieceBoard)) {
                
                if (col2 != castleColumn) {
                    
                    col2 = castleColumn;
                }
                
                move = true;
                
            }
            
        }

    }
    
    
    
    return (first && second && third && fourth && turn && move);
}

bool escWarning() {

    int choice = 0;
    
    clearScreen();
    cout << "ARE YOU SURE YOU WANT A NEW BOARD?" << endl;
    cout << "      [1] YES     [2] NO" << endl;
    cout << "CHOICE: ";
    
    cin >> choice;
    
    
    while ((choice < 1) || (choice > 2)) {
        
        clearScreen();
        cout << "         ";
        cout << "INVALID CHOICE" << endl << endl;
        
        cout << "ARE YOU SURE YOU WANT A NEW BOARD?" << endl;
        cout << "      [1] YES     [2] NO" << endl;
        cout << "CHOICE: ";

        cin >> choice;
        
    }
    
    if (choice == 1) {
        
        return true;
        
    } else {
        
        return false;
    }
    
    
}
bool menuWarning() {
    
    int choice = 0;
    
    clearScreen();
    cout << "ARE YOU SURE YOU WANT THE MAIN MENU?" << endl;
    cout << "      [1] YES     [2] NO" << endl;
    cout << "CHOICE: ";
    
    cin >> choice;
    
    
    while ((choice < 1) || (choice > 2)) {
        
        clearScreen();
        cout << "         ";
        cout << "INVALID CHOICE" << endl << endl;
        
        cout << "ARE YOU SURE YOU WANT THE MAIN MENU?" << endl;
        cout << "       [1] YES     [2] NO" << endl;
        cout << "CHOICE: ";
        
        cin >> choice;
        
    }
    
    if (choice == 1) {
        
    
        return true;
        
    } else {
        
        return false;
    }
    
    
}

bool checkBoardMove(const int row1, const int col1, const int row2,
                    const int& col2, int& colc
                    ,piece pieceBoard[][BOARD_SIZE_X]) {
    
    bool validMove = false;
    bool attacking = false;
    bool oppositeTeam = false;
    bool obstruct = false;
    bool castle = false;
    
    int rowVal = row2 - row1;
    int colVal = col2 - col1;
    
    int rowA = row1;
    int rowB = row2;
    int colA = col1;
    int colB = col2;
    
    colc = colB;
   
    
    convertPieceBoard(colA, rowA, colB, rowB);
    
    if (pieceBoard[rowA][colA].getSide() == 0) {
        
        rowVal = row1 - row2;
    }
    
    if ((pieceBoard[rowA][colA].getSide() != pieceBoard[rowB][colB].getSide())
        && (pieceBoard[rowB][colB].getType() != ' ')) {
        
        attacking = true;
        oppositeTeam = true;
    }
    
    if (pieceBoard[rowB][colB].getType() == ' ') {
        
        attacking = false;
        oppositeTeam = true;
    }
    
    obstruct = checkObstruct(pieceBoard, rowA, rowB, colA, colB, castle);
    
    if (!castle) {
        
        validMove = pieceBoard[rowA][colA].checkMove(rowVal, colVal, attacking
                                                 , oppositeTeam, obstruct);
    } else {
        
        castlePiece(pieceBoard, rowA, colA, colB, colc);
        
        validMove = true;
    }
    
    if (validMove) {
        
        pieceBoard[rowA][colA].setMove(true);
    }
    
    return validMove;
}

bool kingIsDead(piece piece, int& side) {
    
    if (piece.getType() == 'K') {
        
        side = piece.getSide();
        return true;
    }
    
    return false;
}

bool checkObstruct(piece pieceBoard[][BOARD_SIZE_X], int row1, int row2,
                   int col1, int col2, bool& castle) {
    

    bool obstruct = false;
    
    
    if ((pieceBoard[row1][col1].getType() == 'P')) {
        
        if (row1 > row2) {
            
            if (pieceBoard[row1 - 1][col1].getSide() != 2) {
                
                obstruct = true;
            }
            
        } else if (row1 < row2) {
            
            if (pieceBoard[row1 + 1][col1].getSide() != 2) {
                
                obstruct = true;
            }
        }
    }

    
    if ((pieceBoard[row1][col1].getType() == 'B') ||
        (pieceBoard[row1][col1].getType() == 'Q')) {
        
        if ((row1 > row2) && (col1 > col2)) {
            
            while (!((row1 == row2) || (col1 == col2)) && !obstruct) {
                
                row1--;
                col1 -= 2;
                
        
                if ((pieceBoard[row1][col1].getType() != ' ') &&
                    !((row1 == row2) && (col1 == col2))) {
                    
                    obstruct = true;
                }
            
            }
            
        } else if ((row1 > row2) && (col1 < col2)) {
            
            while (!((row1 == row2) || (col1 == col2)) && !obstruct) {
                
                row1--;
                col1 += 2;
                
                if ((pieceBoard[row1][col1].getType() != ' ') &&
                    !((row1 == row2) && (col1 == col2))) {
                    
                    obstruct = true;
                }
                
                
            }
            
        } else if ((row1 < row2) && (col1 > col2)) {
            
            while (!((row1 == row2) || (col1 == col2)) && !obstruct) {
                
                row1++;
                col1 -= 2;
                
                if ((pieceBoard[row1][col1].getType() != ' ') &&
                    !((row1 == row2) && (col1 == col2))) {
                    
                    obstruct = true;
                }
                
                
            }
            
        } else if ((row1 < row2) && (col1 < col2)) {
            
            while (!((row1 == row2) || (col1 == col2)) && !obstruct) {
                
                row1++;
                col1 += 2;
                
                if ((pieceBoard[row1][col1].getType() != ' ') &&
                    !((row1 == row2) && (col1 == col2))) {
                    
                    obstruct = true;
                }
                
                
            }
        }

    }
    
    if ((pieceBoard[row1][col1].getType() == 'R') ||
               (pieceBoard[row1][col1].getType() == 'Q')) {
        
        if ((row1 > row2) && (col1 == col2)) {
            
            while ((row1 != row2) && !obstruct) {
                
                row1--;
                
                if ((pieceBoard[row1][col1].getType() != ' ') &&
                    !((row1 == row2) && (col1 == col2))) {
                    
                    obstruct = true;
                }
                
                
            }
            
        } else if ((row1 < row2) && (col1 == col2)) {
            
            while ((row1 != row2) && !obstruct) {
                
                row1++;
                
                if ((pieceBoard[row1][col1].getType() != ' ') &&
                    !((row1 == row2) && (col1 == col2))) {
                    
                    obstruct = true;
                }
                
                
            }
            
        } else if ((row1 == row2) && (col1 > col2)) {
            
            while ((col1 != col2) && !obstruct) {
                
                col1 -= 2;
                
                if ((pieceBoard[row1][col1].getType() != ' ') &&
                    !((row1 == row2) && (col1 == col2))) {
                    
                    obstruct = true;
                }
                
                
            }
            
        } else if ((row1 == row2) && (col1 < col2)) {
            
            while ((col1 != col2) && !obstruct) {
                
                col1 += 2;
                
                if ((pieceBoard[row1][col1].getType() != ' ') &&
                    !((row1 == row2) && (col1 == col2))) {
                    
                    obstruct = true;
                }
            }
        }
    }
    
    if ((pieceBoard[row1][col1].getType() == 'K') &&
        (pieceBoard[row1][col1].getHasMoved() == false) &&
        (pieceBoard[row2][col2].getType() == 'R') &&
        (pieceBoard[row2][col2].getHasMoved() == false) &&
        (pieceBoard[row1][col1].getSide() == pieceBoard[row2][col2].getSide())) {
        
        if (col1 < col2) {
            
            while (col1 != col2 - 2) {
                
                col1 += 2;
                
                if ((pieceBoard[row1][col1].getType() != ' ')) {
                    
                    obstruct = true;
                }
                
            }
            
            if ((col1 == col2 - 2) && !obstruct) {
                
                castle = true;
                
            }
            
        } else if (col1 > col2) {
            
            while (col1 != col2 + 2) {
                
                col1 -= 2;
                
                if ((pieceBoard[row1][col1].getType() != ' ')) {
                    
                    obstruct = true;
                }
                
            }
            
            if ((col1 == col2 + 2) && !obstruct) {
                
                castle = true;
                
            }
        }

        
    }
    
    return obstruct;
}

void castlePiece(piece pieceBoard[][BOARD_SIZE_X], int row1, int col1, int col2
                 , int& colc) {
    
    piece space;
    
    space.setType(' ');
    space.setSide(1);
    
    if (col1 > col2) {
        
        pieceBoard[row1][col2].setMove(true);
        pieceBoard[row1][col1 - 2] = pieceBoard[row1][col2];
        pieceBoard[row1][col2] = space;
        
        colc += 2;
        
        
    } else if (col1 < col2) {
        
        pieceBoard[row1][col2].setMove(true);
        pieceBoard[row1][col1 + 2] = pieceBoard[row1][col2];
        pieceBoard[row1][col2] = space;
       
        colc--;
    }
    
    
    
}

bool checkTurn(piece pieceBoard[][BOARD_SIZE_X], int row1, int col1
               ,player& nextPlayer) {
    
    bool isTurn = false;
    int rowA = row1;
    int colA = col1;
    int junk = 0;
    
    convertPieceBoard(colA, rowA, junk, junk);
    
    if (pieceBoard[rowA][colA].getSide() == nextPlayer.getSide()) {
        
        isTurn = true;
    }
    
    return isTurn;
}




void getPlayerNames(player& player1, player& player2
                    , player playerlist[LEADERS_SIZE]) {
    
    
    string p1;
    string p2;
    int choice = 1;
    
    cout << "                          ";
    cout << "Enter player 1 name: ";
    getline (cin, p1);
    
    while (checkReusedName(p1, playerlist)) {
        
        cin.get();
        clearScreen();
        cout << "                       ";
        cout << "That name has already been taken!" << endl;
        cout << "                           ";
        cout << "Please select a new name" << endl << endl;
        cout << "                              ";
        cout << "Enter player 1 name: ";
        getline (cin, p1);
        
        
    }
    
    
    
    clearScreen();
    cout << "                          ";
    cout << "Enter player 2 name: ";
    getline (cin, p2);
    
    while (checkReusedName(p2, playerlist)) {
        
        cin.get();
        clearScreen();
        cout << "                       ";
        cout << "That name has already been taken!" << endl;
        cout << "                           ";
        cout << "Please select a new name" << endl << endl;
        cout << "                              ";
        cout << "Enter player 2 name: ";
        getline (cin, p2);
        
       
        
    }

    
    player1.setName(p1);
    player2.setName(p2);
    

    
    clearScreen();
    
    cout << "                          ";
    cout << "Is " << player1.getName() << " Black or White?" << endl;
    cout << "                          ";
    cout << "[1]Black     [2]White" << endl;
    cout << endl;
    cout << "                               ";
    cout << "Choice: ";
    
    cin >> choice;
    
    while ((choice < 1) || (choice > 2)) {
        
        if (cin.fail()) {
            
            clearStream();
            
            clearScreen();
            cout << "                          ";
            cout << "Please enter 1 or 2" << endl << endl;
            cout << "                          ";
            cout << "Is " << player1.getName() << " Black or White?" << endl;
            cout << "                          ";
            cout << "[1]Black     [2]White" << endl;
            cout << endl;
            cout << "                               ";
            cout << "Choice: ";
            
            cin >> choice;
            
        } else {
            
            clearScreen();
            string trash;
            getline(cin, trash);
            
            clearScreen();
            cout << "                          ";
            cout << "Please enter 1 or 2" << endl << endl;
            cout << "                          ";
            cout << "Is " << player1.getName() << " Black or White?" << endl;
            cout << endl;
            cout << "                          ";
            cout << "[1]Black     [2]White" << endl;
            cout << "                               ";
            cout << "Choice: ";
            
            cin >> choice;

        }
    }
    
    if (choice == 1) {
            
        player1.setSide(0);
        player2.setSide(1);
            
    } else if (choice == 2) {
            
        player1.setSide(1);
        player2.setSide(0);
            
    }
    
    player1.addLeader(player1, playerlist);
    player1.addLeader(player2, playerlist);
    
    cin.get();
    
    return;
}

void victorySpeech(player winner, player loser) {
    
    clearScreen();
    cout << "                            ";
    cout << winner.getName() << " is victorious!" << endl;
    cout << endl;
    cout << "                            ";
    cout << "Try harder next time, " << loser.getName() << "!" << endl;
    cout << endl;
    cout << "                            ";
    cout << "Press Enter Twice To Contiue";
    smallClear();
    
    
    pauseGame();
    

}

void clearInput(string& coord, int& row1, int& col1, int& row2, int& col2) {
    
    coord = "    ";
    row1 = 0;
    col1 = 0;
    row2 = 0;
    col2 = 0;
    
}

bool checkPawn(piece pieceBoard[][BOARD_SIZE_X], player curPlayer) {
    
    bool pawn = false;
    
    clearScreen();
    
    if (curPlayer.getSide() == 1) {
        
        for (int i = 0; i < BOARD_SIZE_X; i++) {
            
            if ((pieceBoard[BLACK_SIDE][i].getSide() == 1) &&
                (pieceBoard[BLACK_SIDE][i + 1].getType() == 'P')) {
                
                pieceBoard[BLACK_SIDE][i + 1].setType(newPiece());
                pieceBoard[BLACK_SIDE][i + 1].setMove(false);
                
                pawn = true;
                
                i = BOARD_SIZE_X;
                
            }
        }
        
    } else if (curPlayer.getSide() == 0) {
        
        for (int i = 0; i < BOARD_SIZE_X; i++) {
            
            if ((pieceBoard[WHITE_SIDE][i].getSide() == 0) &&
                (pieceBoard[WHITE_SIDE][i + 1].getType() == 'P')) {
                
                pieceBoard[WHITE_SIDE][i + 1].setType(newPiece());
                pieceBoard[WHITE_SIDE][i + 1].setMove(false);
                
                pawn = true;
                
                i = BOARD_SIZE_X;
                
            }
        }
    }
    
    if (pawn) {
        string trash;
        getline(cin, trash);
    }
    
    
    return pawn;
}

void pieceMenu() {
    
    
    cout << "                 ";
    cout << "******************************************" << endl;
    cout << "                 ";
    cout << "*     CONGRATULATIONS FEARLESS PAWN      *" << endl;
    cout << "                 ";
    cout << "*   CHOOSE YOUR NEW PIECE WITH WISDOM    *" << endl;
    cout << "                 ";
    cout << "*                                        *" << endl;
    cout << "                 ";
    cout << "*      [P]   [R]   [N]   [B]   [Q]       *" << endl;
    cout << "                 ";
    cout << "*      [1]   [2]   [3]   [4]   [5]       *" << endl;
    cout << "                 ";
    cout << "*                                        *" << endl;
    cout << "                 ";
    cout << "******************************************" << endl;
    cout << endl;
    cout << "                 ";
    cout << "                CHOICE: ";
    
    
    return;
}

char newPiece() {
    
    int choice = 0;
    char newChar = ' ';
    
    pieceMenu();
    cin >> choice;
    
    while (cin.fail() || ((choice < 1) || (choice > 5))) {
       
        if (cin.fail()) {
            
            clearStream();
            
            clearScreen();
            cout << "Please enter a correct menu choice!" << endl;
            pieceMenu();
            
            cin >> choice;
            
        } else {
            
            clearScreen();
            cout << "Please enter a correct menu choice!" << endl;
            pieceMenu();
            
            cin >> choice;
            
        }
        
        
    }
    
    switch (choice) {
        case 1:
            newChar = 'P';
            break;
        case 2:
            newChar = 'R';
            break;
        case 3:
            newChar = 'N';
            break;
        case 4:
            newChar = 'B';
            break;
        case 5:
            newChar = 'Q';
            break;
        default:
            break;
    }
        

    return newChar;
    
}




                          
                          
                          
                          
                          
                          
                          
                          
                          
                          
