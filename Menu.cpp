//
//  Menu.cpp
//  Chess 2.0
//
//  Created by Jacob Barr on 2/28/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#include "Menu.h"
#include "OpenAndCloseCredits.h"
#include <iostream>

using namespace std;

void printMenu() {
    
    cout << "                            ";
    cout << "-- Main Menu --" << endl;
    cout << "                            ";
    cout << "1: New Game" << endl;
    cout << "                            ";
    cout << "2: View Leaderboard" << endl;
    cout << "                            ";
    cout << "3: Quit Game" << endl;
    cout << "                            ";
    cout << "Enter Choice: ";

}

int menuChoice() {
    
    int choice = 0;
    
    printMenu();
    cin >> choice;
    
    while ((choice < 1) || (choice > 3)) {
        
        if (!(cin.good())) {
            
            clearStream();
        }
        
        clearScreen();
        cout << "                      ";
        cout << "Please enter a number 1 - 3" << endl;
        cout << endl;
        printMenu();
        cin >> choice;
        clearScreen();
        
    }
    
    clearScreen();
    
    
    return choice;
    
}
