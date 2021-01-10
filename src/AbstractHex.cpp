#include "../include/AbstractHex.h"
#include <iostream>

using namespace std;
using namespace HexOguz;

AbstractHex::AbstractHex(): size(0), totalMove(0), gameType(0), turn(player1), gameState(active)
{}

AbstractHex::AbstractHex(int a): size(a), totalMove(0), gameType(0), turn(player1), gameState(active)
{}

void AbstractHex::Welcome()
{
    cout << endl << endl
    << "First Select the game type you want from following." << endl
    << "1- P vs P \n2- P vs CPU"  << endl
    << "Enter your choice:";

    if (gameType == 0)
        cin >> gameType;
    else
        cout << gameType << " (entered from constructor)" << endl;

    // prevent false size or entering a char.
    while(gameType != PvP && gameType != PvCPU)
    {
        cerr << "Your input is invalid" << endl << "Enter Again:";
        cin.clear();
        cin.ignore(100,'\n');
        cin >> gameType;
    }

    if (size < 6)
    {
        while(size < 6)
        {
            cout << "\nNow select table size. min 6 allowed." << endl
            << "Select (for 6x6 table, type 6):";
            cin >> size; if (size > 5) break;
            cerr << "Your input is invalid" << endl << "Enter Again:";
            cin.clear();
            cin.ignore(100,'\n');
        }
    }
}