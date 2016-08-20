//
//  main.cpp
//  Chess 2.0
//
//  Created by Jacob Barr on 2/24/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#include "LeaderboardUtilities.h"
#include "BoardUtilities.h"
#include "PlayerClass.h"
#include "PieceClass.h"
#include "SideClass.h"
#include "OpenAndCloseCredits.h"
#include "Menu.h"
#include "Gameplay.h"
#include <string>
#include <cmath>
#include <cctype>
#include <fstream>
#include <iostream>

using namespace std;


int main() {
   
    int startVal = 0;
    startVal = intro();
    clearScreen();
    
    while (startVal != 3) {
        
        switch (startVal) {
            case 1:
                cin.get();
                newGame();
                clearScreen();
                startVal = menuChoice();
                break;
            case 2:
                clearScreen();
                GetTopTen();
                enterToContinue();
                pauseGame();
                clearScreen();
                startVal = menuChoice();
                break;
            default:
                clearScreen();
                cout << "                         ";
                cout << "Is it easter already?" << endl << endl;
                startVal = menuChoice();
                break;
                
        }
    }
    
    
    goodbyeBanner();
    
    
    return 0;
}














