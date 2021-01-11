#include "../include/HexAdapter.h"
#include <iostream>

using namespace HexOguz;
using namespace std;


template <typename T>
HexAdapter<T>::HexAdapter()
{
    createTable();
}

template <typename T>
HexAdapter<T>::HexAdapter(int size)  //AbstractHex(size)
{
    createTable();
}


template <typename T>
void HexAdapter<T>::print() const
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

template <typename T>
void HexAdapter<T>::reset()
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            hexCells[i][j].setState(dot);
}

template <typename T>
void HexAdapter<T>::createTable()
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