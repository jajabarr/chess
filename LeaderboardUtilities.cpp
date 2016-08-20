//
//  LeaderboardUtilities.cpp
//  Chess 2.0
//
//  Created by Jacob Barr on 2/24/16.
//  Copyright © 2016 Jacob Barr. All rights reserved.
//

#include <fstream>
#include "LeaderboardUtilities.h"
#include "OpenAndCloseCredits.h"
#include "PlayerClass.h"
#include <iostream>
using namespace std;




void GetLeaderBoard(player playersList[LEADERS_SIZE]) {
    
    ifstream currentLeaderboard;
    
    
    string playerName;
    int playerCount = 0;
    int place = 0;
    
    currentLeaderboard.open("/Users/jacobjbarr/All/UMICH SPRING 2016/EECS 183/Chess 2.0/Chess 2.0/LeaderBoard.txt");
    
    if (!currentLeaderboard.is_open()) {
        
        cout << "ERROR NOT OPENING";
    }
    
    while ((currentLeaderboard >> place) && (playerCount < 99)) {
        
        getline(currentLeaderboard, playerName);
        
        playersList[playerCount].setName(playerName);
        playersList[playerCount].setPosition(place);
        
        playerCount++;
        
    }
    
    
    
    
    currentLeaderboard.close();
    
    return;

}

void GetTopTen() {
    
    ifstream currentLeaderboard;
    
    
    string topTen;
    int tenCount = 0;
    int place = 0;
    
    currentLeaderboard.open("/Users/jacobjbarr/All/UMICH SPRING 2016/EECS 183/Chess 2.0/Chess 2.0/LeaderBoard.txt");
    
    if (!currentLeaderboard.is_open()) {
        
        cout << "ERROR NOT OPENING";
    }
    
    while ((currentLeaderboard >> place) && (tenCount < 10)) {
        
        getline(currentLeaderboard, topTen);
        
        
        cout << "                               ";
        
        cout << "#" << place << " " << topTen << endl;
        
        tenCount++;
        
    }
    
    
    currentLeaderboard.close();
    
    return;
}

void insertLeaderBoard(player playerList[LEADERS_SIZE]) {
    
    ofstream leaders;
    int i = 0;
    
    leaders.open("/Users/jacobjbarr/All/UMICH SPRING 2016/EECS 183/Chess 2.0/Chess 2.0/LeaderBoard.txt");
    
    if (!leaders.is_open()) {
        
        cout << "ERROR NOT OPENING";
    }
    
    while (playerList[i].getSide() != 2) {
        
        leaders << i + 1;
        leaders << playerList[i].getName();
        
        leaders << endl;
        
        i++;
        
        
        
        
    }
    
    leaders.close();
    
    
    
}

void orderLeaderBoard(player leaderBoard[LEADERS_SIZE]) {
    
    for (int i = 0; i < LEADERS_SIZE - 1; i++) {
        
        player temp;
        
        if (leaderBoard[i].getPosition() < leaderBoard[i + 1].getPosition()) {
            
            temp = leaderBoard[i];
            
            leaderBoard[i] = leaderBoard[i + 1];
            leaderBoard[i + 1] = temp;
            
        }
        
        
        
    }
    
    
    
}

bool checkReusedName(string p1, player players[LEADERS_SIZE]) {
    
    bool alreadyUsed = false;
    int playerElement = 0;
    int choice = 0;
    
    
    for (int i = 0; i < LEADERS_SIZE; i++) {
        
        if (players[i].getName() == p1) {
            
            alreadyUsed = true;
            
            playerElement = i;
            i = LEADERS_SIZE;
            
        }
        
        
    }
    
    if (alreadyUsed) {
        
        clearScreen();
        cout << "                  ";
        cout << "Are you the same " << players[playerElement].getName();
        cout << " that played before?" << endl;
        cout << "                            ";
        cout << "[1] Yes     [2] No" << endl << endl;
        cout << "                                 ";
        cout << "Choice: ";
        
        cin >> choice;
        
        while (cin.fail() || (choice < 1) || (choice > 2)) {
            
            if (cin.fail()) {
               
                clearStream();
                
            }
            
            clearScreen();
            cout << "                          ";
            cout << "Pleaser enter 1 or 2";
            cout << endl << endl;
            cout << "                  ";
            cout << "Are you the same " << players[playerElement].getName();
            cout << " that played before?" << endl;
            cout << "                            ";
            cout << "[1] Yes     [2] No" << endl << endl;
            cout << "                                 ";
            cout << "Choice: ";
            
            cin >> choice;

        }
        
        if (choice == 1) {
            
            alreadyUsed = false;
            cin.get();
    
        }
    
    }
    
    
    
    
    
    return alreadyUsed;
}





