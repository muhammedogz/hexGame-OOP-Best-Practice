/*
* Author: Muhammed Oguz

* This header represents a base class Hex class.

*/

#ifndef ABSTRACTHEX_H
#define ABSTRACTHEX_H

#include <ostream> // for friend functions
#include <fstream>
#include "Cell.h"

namespace HexOguz
{

    class AbstractHex
    {
        public:
        // Default constructor
        AbstractHex(); 

        // Resets board from the beginning.
        void reset();

        // Returns true if game is ended.
        bool isEnd();

        // Returns last move, If there is not than throws an exception.
        Cell lastMove();

        // play with CPU
        Cell play(); 
        // play PVP
        Cell play(Cell); 

        // Print Function 
        void print();
        // Read from file
        void readFromFile();
        // Write to file
        void writeToFile();

        // return true if both board equal.
        bool operator==(AbstractHex&);

        // return Cell of given indexes
        Cell operator()(int,int);

        // returns number of move made so far
        int numberOfMoves(){return this->totalMoves;}

        // Oneline setters and getters implemented.
        void setSize(int size){this->size = size;}
        int getSize(){return size;}
        
        // Params that every derived class will had. So it is protected. 
        protected:
            int size; // represents hex board size. 
            int totalMoves = 0; // track number of moves. 
            int gameType = 0; // keep game type
            char turn = player1; // keep player type
            int gameState = active; // keep game status

    };

} // Namespace


#endif // ABSTRACTHEX_H