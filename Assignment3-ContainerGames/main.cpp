#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <vector>
#include <cmath>
#include "GameTimer.h"

using namespace std;
int menuOption();
void playTowerOfHanoi();

int main()
{
    playTowerOfHanoi();

    return EXIT_SUCCESS;
}

int menuOption()
{
    system("cls");
    cout << "CMPR131 Chapter 3: Games using Containers by Saul Merino and John Kim" << endl;
    cout << string(100, char(205)) << endl;

    cout << "1. Tic-Tac-Toe" << endl;
    cout << string(100, char(196)) << endl;

    cout << "2. Tower of Hanoi" << endl;
    cout << string(100, char(196)) << endl;

    cout << "3. n-Queens" << endl;
    cout << string(100, char(196)) << endl;

    cout << "0. Quit" << endl;
    cout << string(100, char(205)) << endl;
    // int option = inputInteger("Option : ", 0, 3);
    return 2; //option;
}

