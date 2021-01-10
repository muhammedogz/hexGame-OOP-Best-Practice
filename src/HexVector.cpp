#include "../include/HexVector.h"
#include <iostream>

using namespace std;
using namespace HexOguz;

HexVector::HexVector(): AbstractHex(0)
{
    reset();
}

HexVector::HexVector(int size): AbstractHex(size)
{
    reset();
}

void HexVector::print() const
{
    // these things just showing a beautiful table. 
    cout << "  ";
    for (int i = 0; i < size; i++) cout << static_cast<char> ('a' + i)  << " ";
    cout << endl; 
    for (int i = 0; i < size; i++)
    {
        if (i < 9)
            cout << i+1 << " ";
        else
            cout << i+1;
        for (int k = 0; k < i; k++) cout << " ";
        for (int j = 0; j < size; j++)
        {
            cout << " " << hexCells[i][j].getState();
        }
        cout << endl;
    }
}

void HexVector::reset()
{
    for (int i = 0; i < size; i++)
    {
        hexCells.push_back(vector<Cell>());
        keepUppercase.push_back(vector<Cell>());
        for (int j = 0; j < size; j++)
        {
            hexCells[i].push_back(Cell());
            keepUppercase[i].push_back(Cell());
        }
    }
}

void HexVector::setSize(int size)
{
    this->size = size;
    reset();
}
