/*
* Author: Muhammed Oguz

* This header represents a derived class from AbstractHex Class.

*/

#ifndef HEXVECTOR_H
#define HEXVECTOR_H

#include "AbstractHex.h"
#include <vector>

using std::vector;

namespace HexOguz
{

    class HexVector : public AbstractHex
    {
        public:
        HexVector();
        HexVector(int);

        void print() const override;
        // void readFromFile() override;
        // void writeToFile() override;
        void reset() override;
        void setSize(int) override;
        // bool isEnd() override const;
        // Cell play() override; 
        // Cell play(Cell) override; 
        // bool operator==(AbstractHex&) const override;
        // Cell operator()(int,int) const override;
        // Cell lastMove() const override;


        private:
        vector<vector<Cell>> hexCells;
        vector<vector<Cell>> keepUppercase;

    };

} // Namespace


#endif // HEXVECTOR_H