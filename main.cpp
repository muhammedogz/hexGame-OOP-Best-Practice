#include <iostream>
#include "include/HexVector.h"

using namespace HexOguz;

int main(void)
{
   HexVector foo(5);
   foo.playGame();
   foo.readFromFile("test/test0.txt");
   foo.print();
   foo.playGame();
   foo.setSize(10);
   foo.print();
  
}