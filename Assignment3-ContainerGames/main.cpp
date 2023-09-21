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
    menuOption();
    cout << endl;
    playTowerOfHanoi();

    return EXIT_SUCCESS;
}

//Precondition: None
//Postcondition: Returns 0
int menuOption()
{
    system("cls");
    cout << "Tower Of Hanoi by Saul Merino and John Kim" << endl;
    return 0; //option;
}

