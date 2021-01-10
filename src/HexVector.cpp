#include "../include/HexVector.h"
#include <iostream>
#include <random>

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

void HexVector::play()
{
    // CPU plays random
    setTurn(player2);
    random_device randomCreator;
    mt19937 rand(randomCreator());
    uniform_int_distribution<mt19937::result_type> randRange(0, size -1);
    int row = randRange(randomCreator);
    int column = randRange(randomCreator);
    while (hexCells[row][column].getState() != dot)
    {
        row = randRange(randomCreator);
        column = randRange(randomCreator);
    }
    char column_c = column + 'A';
    cout << "Your Turn " << turn << endl;
    cout << "Computer Entered: " << column_c << row + 1 << endl;
    hexCells[row][column].setState(turn);
    print();
}

void HexVector  ::play(Cell position)
{
    turn = position.getState();
    hexCells[position.getColumn()][position.getRow()].setState(position.getState());
    print();
}

void HexVector::playGame()
{
    Welcome();
    createTable();

    string coordinate;
    Cell tempCell;
    while(true)
    {

        tempCell.setState(player1);
        while(checkTurn(coordinate, tempCell)); 
        // If gamestate turns to passive, then retrun to main
        if (gameState == passive) return;
        play(tempCell);
        // if there is a winner, break
        // ? if (checkWinner()) break;

        // if gametype is PvCPU
        if (gameType == PvCPU)
            play();
        else
        {
            tempCell.setState(player2);
            while(checkTurn(coordinate, tempCell));
            if (gameState == passive) return;
            // if gameType has changed
            if (gameType == PvCPU){ print(); continue; }
            play(tempCell);
        }
        // ? if (checkWinner()) break;
    }
    
    // it means there is a winner
    if (gameState == winner)
        return;//coppyToUpper();
}

bool HexVector::checkTurn(string coordinate, Cell& tempCell)
{
    cout << endl << "Your Turn " << tempCell.getState() << endl;
    cout << "Type H for all Commands" << endl << "Command: ";
    cin >> ws;
    getline(cin, coordinate);

    if (coordinate[0] == 'H' && coordinate.length() == 1)
    {
        allCommands();
        return checkTurn(coordinate, tempCell);
    }
    else if (coordinate[0] == 'Q' && coordinate.length() == 1)
    {
        cout << "Quiting... " << endl;

        gameState = passive;
        cout << "This game will be active in background" << endl;
        return false;

    }
    else if (coordinate[0] == 'P' && coordinate.length() == 1)
    {
        print();
        return checkTurn(coordinate, tempCell);
    }
    if (saveOrLoad(coordinate))
        return true;

    // in load circumstance, this func should return false.
    else if(coordinate.compare(0, 4, "LOAD", 0 ,4) == 0 && coordinate.size() > 5) 
        return false;
    else
    {
        int row = coordinate[0] - 'A';
        int column = coordinate[1] - '1';
        if (coordinate.length() == 3)
            column = (coordinate[1] - '0') * 10 + (coordinate[2] - '1');
        if ((coordinate.length() != 2 && coordinate.length() != 3) || row > size - 1 || row < 0 || column < 0 || column > size - 1)
        {
            cerr << "Your input is not correct. Be aware this game is case sensitive" << endl;
            return checkTurn(coordinate, tempCell);
        }
        if (hexCells[column][row].getState() != dot)
        {   
            cerr << "this filed is not empty" << endl;
            return checkTurn(coordinate, tempCell);
        }
        tempCell.setRow(row);
        tempCell.setColumn(column);
        return false;
    }
}