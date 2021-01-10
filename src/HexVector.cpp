#include "../include/HexVector.h"
#include <iostream>

using namespace std;
using namespace HexOguz;

HexVector::HexVector(): AbstractHex(0)
{
    createTable();
}

HexVector::HexVector(int size): AbstractHex(size)
{
    createTable();
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
        for (int j = 0; j < size; j++)
            hexCells[i][j].setState(dot);
}

void HexVector::createTable()
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
    createTable();
    reset();
}

void HexVector::readFromFile(string filename)
{
    // rading mode
	ifstream fp(filename);
	if(fp.is_open() == false)
    {
		cerr << "Couldn't open file.\n";  return;
	}

    // keep old gameType 
    int tempType = gameType;

    // read variables from file
	fp >> gameType >> size  >> turn;

    // resize table
    hexCells.resize(size);
    keepUppercase.resize(size);
    for (int i = 0; i < size; i++)
    {   
        keepUppercase[i].resize(size);
        hexCells[i].resize(size);
    }
 
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            char temp;
            fp >> temp;
            hexCells[i][j].setState(temp);
        }
    }
	
    fp.close();

    
    if (gameType == 2)
        turn = player1;
    cout << "Game Loaded from -> " + filename << endl;

    if (tempType != gameType)
            cout << "Game Type is changed" << endl;
        cout << "There is new table" << endl;

}

void HexVector::writeToFile(string filename)
{
    // writing mode
	ofstream fp(filename);
	if(fp.is_open() == false)
    {
		cerr << "Could not open the file\n";  return;
	}

    // write those to file
	fp << gameType << endl << size << endl << turn << endl;

    // write table as type of char
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            fp << hexCells[i][j].getState();
        fp << endl;
    }

	cout << "Game saved as -> " + filename << endl;
	fp.close();  return;
}

void HexVector::playGame()
{
    Welcome();
    createTable();
}