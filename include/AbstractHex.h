/*
* Author: Muhammed Oguz

* This header represents a base class Hex class.

*/

#ifndef ABSTRACTHEX_H
#define ABSTRACTHEX_H

#include <ostream> // for friend functions
#include <fstream>

namespace HexOguz
{
    enum playerFlags {player1 = 'x', player2 = 'o', dot = '.'};
    enum gameFlags {PvP =1, PvCPU, CPUvCPU};
    enum gameStatus {active, passive, winner};

    class AbstractHex
    {
        public:

        class Cell;

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
        friend std::ostream& operator<<(std::ostream&, const AbstractHex&);
        // Read from file
        friend std::ofstream& operator<<(std::ofstream&, const AbstractHex&);
        // Write to file
        friend std::ifstream& operator>>(std::ifstream&, AbstractHex&);

        // return true if both board equal.
        bool operator==(AbstractHex&);

        // return Cell of given indexes
        Cell operator()(int,int);


        // returns number of move made so far
        int numberOfMoves(){return this->totalMoves;}

        // Oneline setters and getters implemented.
        void setSize(int size){this->size = size;}
        int getSize(){return size;}
        
        protected:
            int size; // represents hex board size. 
            int totalMoves = 0; // track number of moves. 
            int gameType = 0; // keep game type
            char turn = player1; // keep player type
            int gameState = active; // keep game status

    };

    class AbstractHex::Cell
    {
        public:
        Cell();

        // implemented as inline. 
        void setRow(int setRow);
        void setColumn(int setColumn);
        void setState(char setState);
        int getColumn() const; 
        int getRow() const;
        char getState() const;
        private:
        int row = 0, column = 0;
        char state = dot;
    };

    inline void AbstractHex::Cell::setRow(int row) {this->row = row;}
    inline void AbstractHex::Cell::setColumn(int column) {this->column = column;}
    inline void AbstractHex::Cell::setState(char state) {this->state = state;}
    inline int AbstractHex::Cell::getRow() const {return row;}
    inline int AbstractHex::Cell::getColumn() const {return column;}
    inline char AbstractHex::Cell::getState() const {return state;}

} // Namespace


#endif // ABSTRACTHEX_H