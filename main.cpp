#include <iostream>
#include <deque>
#include "include/HexArray1D.h"
#include "include/HexVector.h"
#include "include/HexAdapter.h"
#include "src/HexAdapter.cpp" // for template adaptation, weird but necessary

using namespace std;


int AbstractHex::activeGames = 0;
int AbstractHex::allGames = 0;


using namespace HexOguz;


namespace HexOguz
{
   // expected global function.
   // check for all invalid circumstances
   // if size is bigger than 6 then return false
   // if this board contains invalid character than return false
   // otherwise return true.
   bool checkValidHex(AbstractHex** AbstractArr, int count)
   {
      for (int i = 0; i < count; i++)
         if (AbstractArr[i]->getSize() < 6)
            return false;
      else
      {
         for (int i = 0; i < count; i++)
         {
            for (int j = 0; j < AbstractArr[i]->getSize(); j++)
               for (int k = 0; k < AbstractArr[i]->getSize(); k++)
                  if (AbstractArr[i]->operator()(j,k).getState() != 'o' &&
                      AbstractArr[i]->operator()(j,k).getState() != 'x' &&
                      AbstractArr[i]->operator()(j,k).getState() != '.')
                      return false;
         }
      }
      return true;   
   }
} // namespace HexOguz




int main(void)
{
   vector<AbstractHex*> Games;
   int gameCount = 0; // keeps game count for global checkValidHex function
//   Games.push_back(new HexAdapter<vector>);
//   Games.push_back(new HexAdapter<deque>);
   Games.push_back(new HexArray1D);
   Games.push_back(new HexVector);

   bool a = (*Games[0] == *Games[1]); 
   Games[0]->print();
   Games[1]->print();
   cout << a << endl;

   

}


// int main2(void)
// {

//    HexAdapter<vector> foo;
//    foo.print();
//    return 0;
// }



// int main1(void)
// {
//    HexVector foo(6);
//    HexVector foo2(6);
//    cout << foo.isEnd() << endl;
//    foo.playGame();
//    foo2.playGame();
//    cout << (foo == foo2) << endl;
//    foo.print();
//    cout << HexVector::getAlLGames() << endl;
   
//    cout << foo.isEnd() << endl;
//    cout << "moveCount " << foo.numberOfMoves() << endl;
  
//    return 0;
// }