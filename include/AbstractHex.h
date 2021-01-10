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
        AbstractHex();
        AbstractHex(int);

        // Print Function 
        virtual void print() const = 0;

        // Read from file
        virtual void readFromFile(std::string) = 0;
        
        // Write to file
        virtual void writeToFile(std::string) = 0;

        // Resets board from the beginning.
        virtual void reset() = 0;

        // set Size and Reset
        virtual void setSize(int) = 0;

        // play with CPU
        virtual void play() = 0; 
        // play PVP
        virtual void play(Cell) = 0; 

        // // Returns true if game is ended.
        // virtual bool isEnd() const = 0;

        // // return true if both board equal.
        // virtual bool operator==(AbstractHex&) const = 0;

        // // return Cell of given indexes
        // virtual Cell operator()(int,int) const = 0;

        // // Returns last move, If there is not than throws an exception.
        // virtual Cell lastMove() const = 0;

        // returns number of move made so far
        inline int numberOfMoves() const         {return this->totalMove;}

        // Following functions are not part of Homework Instructions
        void Welcome();
        void allCommands() const;
        bool saveOrLoad(std::string);

        // Oneline setters and getters implemented.
        inline int getSize() const              {return size;}
        inline void setGameType(int gameType)   {this->gameType = gameType;}
        inline int getGameType() const          {return gameType;}
        inline void setTurn(char turn)          {this->turn = turn;}
        inline char getType() const             {return turn;}
        inline void setGameState(int gameState) {this->gameState = gameState;}
        inline int getGameState() const         {return gameState;}
        inline void setTotalMove(int totalMove) {this->totalMove = totalMove;}
        
        
        // Params that every derived class will had. So it is protected. 
        protected:
            int size; // represents hex board size. 
            int totalMove = 0; // track number of moves. 
            int gameType = 0; // keep game type
            char turn = player1; // keep player type
            int gameState = active; // keep game status
    };

} // Namespace


#endif // ABSTRACTHEX_H