/*
 Saul Merino
 9/16/23
 CPMR 131 - Professor Q

 Credit:
 Part 1: Tic Tac Toe by Joe Bryant & Erik Santana
 Part 2: Tower Of Hanoi by Saul Merino & John Kim: Tower Of Hanoi
 Part 3: n-Queens by Otoniel Torres Bernal & Thanh Tran: n-Queens
 */

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <vector>
#include <cmath>
#include "GameTimer.h"
#include "TicTacToe.h"
#include "N_Queens.h"


using namespace std;
int menuOption();
void playTowerOfHanoi();

int main()
{
    TicTacToe ticTacToeObject;
    N_Queens nQueensObject;

    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 1: ticTacToeObject.ticTacToe(); break;
        case 2: playTowerOfHanoi(); break;
        case 3: nQueensObject.N_queens(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}

int menuOption()
{
    system("cls");
    cout << "CMPR131 Chapter 3: Games using Containers by Saul Merino" << endl;
    cout << string(100, char(205)) << endl;

    cout << "1. Tic-Tac-Toe" << endl;
    cout << string(100, char(196)) << endl;

    cout << "2. Tower of Hanoi" << endl;
    cout << string(100, char(196)) << endl;

    cout << "3. n-Queens" << endl;
    cout << string(100, char(196)) << endl;

    cout << "0. Quit" << endl;
    cout << string(100, char(205)) << endl;
    int option = inputInteger("Option : ", 0, 3);
    return option;
}

