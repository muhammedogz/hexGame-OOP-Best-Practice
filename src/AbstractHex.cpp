#include "../include/AbstractHex.h"
#include <iostream>

using namespace std;
namespace HexOguz
{

    AbstractHex::AbstractHex()
    {
        cout << "Created" << endl;
    }

    void AbstractHex::reset()
    {
        cout << "sa" << endl;
    }
}

int main(void)
{
    HexOguz::AbstractHex a;
    a.reset();
    return 0;
}