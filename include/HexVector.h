/*
* Author: Muhammed Oguz

* This header represents a derived class from AbstractHex Class.

*/

#ifndef HEXVECTOR_H
#define HEXVECTOR_H

#include "AbstractHex.h"
#include <vector>
#include <iostream>

using std::vector;
using std::string;

namespace HexOguz
{

    class HexVector : public AbstractHex
    {
        public:
        HexVector();
        HexVector(int);


        void createTable();
        void playGame();
        bool checkTurn(string, Cell&);

        void print() const override;
        void readFromFile(string) override;
        void writeToFile(string) override;
        void reset() override;
        void setSize(int) override;
        // bool isEnd() override const;
        void play() override; 
        void play(Cell) override; 
        // bool operator==(AbstractHex&) const override;
        // Cell operator()(int,int) const override;
        // Cell lastMove() const override;


        private:
        vector<vector<Cell>> hexCells;
        vector<vector<Cell>> keepUppercase;

    };

} // Namespace


#endif // HEXVECTOR_H