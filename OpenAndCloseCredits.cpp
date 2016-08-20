//
//  OpenAndCloseCredits.cpp
//  Chess 2.0
//
//  Created by Jacob Barr on 2/25/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#include "OpenAndCloseCredits.h"
#include "BoardUtilities.h"
#include "Menu.h"
#include <string>
#include <iostream>

using namespace std;

void pauseGame() {
    
    string i = "thisshouldbeempty";
    cin.get();
    getline(cin, i);
    
    
}


void adjustScreen() {
    
    for (int i = 0; i < BOARD_X; i++) {
        
        cout << "*";
    }
    cout << endl;
    
    for (int i = 0; i < BOARD_Y + 10; i++) {
        
        cout << "*";
        
        for (int j = 1; j < BOARD_X - 1; j++) {
            
            cout << " ";
        }
        
        cout << "*";
        
        cout << endl;

    }
    
    for (int i = 0; i < BOARD_X; i++) {
        
        cout << "*";
    }
    
    cout << endl;
    
    cout << "                ";
    
    cout << "PLEASE ADJUST YOUR SCREEN TO DIMENSION ABOVE";
    
    cout << endl;
    
    cout << "                          ";
    
    cout << "PRESS ENTER TO CONINTUE";
    
    cout << endl;

    
    pauseGame();
    clearScreen();
    
}

void smallClear() {
    
    for (int i = 0; i < 10; i++) {
        
        cout << endl;
    }
}

void clearScreen() {
    
    for (int i = 0; i < 100; i++) {
        
        cout << endl;
    }
}

void welcomeBanner() {
    
    
    cout << "                      ";
    cout << "*******************************" << endl;
    cout << "                      ";
    cout << "*         WELCOME TO:         *" << endl;
    cout << "                      ";
    cout << "*    CHESS BY: JACOB BARR     *" << endl;
    cout << "                      ";
    cout << "*******************************" << endl;
    
    cout << endl;

}

int intro() {
    
    int choice = 0;
    
    welcomeBanner();
    choice = menuChoice();
    
    return choice;
}

void goodbyeBanner() {
    
    clearScreen();
    cout << "                           ";
    cout << "**********************" << endl;
    cout << "                           ";

    cout << "*      GOODBYE       *" << endl;
    cout << "                           ";

    cout << "*     THANK YOU      *" << endl;
    cout << "                           ";

    cout << "*    FOR PLAYING!    *" << endl;
    cout << "                           ";

    cout << "**********************" << endl;
    cout << endl << endl << endl << endl;
    

}

void enterToContinue() {
    
    cout << endl;
    cout << "                         ";
    cout << "Press Enter To Continue  ";
    cout << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl;
}





