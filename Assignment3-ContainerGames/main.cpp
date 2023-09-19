#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <vector>
#include <cmath>

#include "TowerOfHanoi.h"


using namespace std;
int menuOption();
void playTowerOfHanoi();

int main()
{
    playTowerOfHanoi();
    /*

    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 1: //quadraticExpressionMenu(); break;
        case 2: playTowerOfHanoi(); break;
        case 3: //rationalNumMenu(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
*/
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
    // int option = inputInteger("Option : ", 0, 3);
    return 2; //option;
}

