#include <iostream>
#include "include/HexVector.h"

using namespace HexOguz;

int main(void)
{
   HexVector foo(5);
   foo.Welcome();
   foo.reset();
   foo.print();
   foo.setSize(15);
   foo.print();
}