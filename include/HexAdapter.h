/*
* Author: Muhammed Oguz

* This header represents a derived class from AbstractHex Class.

*/

#ifndef HEXADAPTER_H
#define HEXADAPTER_H
#include "AbstractHex.h"
#include "Cell.h"



namespace HexOguz
{
    template <typename T>
    class HexAdapter
    {
    public:
        HexAdapter();
        HexAdapter(int);

        void print() const;
        void reset();
        void createTable();

    private:
        T<T<Cell>> hexCells;

    };
    
    

} // namespace HexOguz



#endif // HEXADAPTER_H