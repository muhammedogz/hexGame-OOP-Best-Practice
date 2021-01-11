#include <iostream>
#include "include/HexVector.h"


using namespace std;
using namespace HexOguz;

int AbstractHex::activeGames = 0;
int AbstractHex::allGames = 0;

int main(void)
{
   HexVector foo(6);
   HexVector foo2(6);
   cout << foo.isEnd() << endl;
   foo.playGame();
   foo2.playGame();
   cout << (foo == foo2) << endl;
   foo.print();
   cout << HexVector::getAlLGames() << endl;
   
   cout << foo.isEnd() << endl;
   cout << "moveCount " << foo.numberOfMoves() << endl;
  
}