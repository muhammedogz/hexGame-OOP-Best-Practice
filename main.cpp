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
            for (int j = 0; j < AbstractArr[i]->getSize(); j++)
                for (int k = 0; k < AbstractArr[i]->getSize(); k++)
                {
                    if (AbstractArr[i]->operator()(j,k).getState() != 'o')
                    {
                        if(AbstractArr[i]->operator()(j,k).getState() != 'x')
                        {
                            if(AbstractArr[i]->operator()(j,k).getState() != '.')
                            return false;
                        }
                    }  
                }
            }
        return true;   
    }
} // namespace HexOguz

// Those functions helps menu in Main.
void main_helper(vector<AbstractHex*> Games, bool select);
int setSelect(vector<AbstractHex*> Games);
void checkCinForFail();
void game_helper(vector<AbstractHex*> Games);
void TestClassFunctions(AbstractHex *testMe);
void TestGlobalFunction();

int main(void)
{
   vector<AbstractHex*> Games;
    
    cout << "Welcome To The Most Excited Game In The World" << endl
    << "-------->>>>>>>>> HEX <<<<<<<<<--------\n" << endl;
    
    
    bool trash;
    HexAdapter<vector> adapterVector(trash); HexAdapter<deque> adapterDeque(trash);
    HexArray1D Array1D(trash); HexVector Vector(trash);
    int command;
    string file;

    while(true)
    {
        cout << endl << "Menu: " << endl
        << "1- Start a new game with selecting class type" << endl
        << "2- Test All functions of HexVector Class" << endl
        << "3- Test All functions of HexArray1D Class" << endl
        << "4- Test All functions of HexAdapter<vector> Class" << endl
        << "5- Test All functions of HexAdapter<deque> Class" << endl
        << "6- Test Global function with 5 different Game Array" << endl
        << "7- Test File Opening Exception" << endl
        << "8- Test Operator() Exception" << endl
        << "11- Quit" << endl
        << endl << "Enter Command: ";
                                                    
        cin >> command;
        checkCinForFail();

        if (command == 1)
            game_helper(Games);
        else if (command == 2)
            TestClassFunctions(new HexVector(trash));
        else if (command == 3)
            TestClassFunctions(new HexArray1D(trash));
        else if (command == 4)
            TestClassFunctions(new HexAdapter<vector>(trash));
        else if (command == 5)
            TestClassFunctions(new HexAdapter<deque>(trash));
        else if (command == 6)
            TestGlobalFunction();
        else if (command == 7)
        {
            try
            {
                Vector.readFromFile("GarbageFile.xml");
            }
            catch (const HexErrorHandler& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        else if (command == 8)
        {
            try
            {
                Array1D.operator()(-15,2);
            }
            catch(const HexErrorHandler& e)
            {
                std::cerr << e.what() << '\n';
            }   
        }
        else if (command == 9)
        {
            cout << "Goodbye My friend <3<3 " << endl; break;
        }
    }

}

void TestClassFunctions(AbstractHex *testMe)
{
    checkCinForFail();
    try
    {
    cin.ignore();
    cout << "Press enter to continue after each step" << endl;                                      cin.ignore();
    cout << "readFromFile(test/test0.txt) ->"; testMe->readFromFile("test/test0.txt");              cin.ignore();
    cout << "print() ->"<< endl; testMe->print();                                                   cin.ignore();
    cout << "ısEnd() ->"; cout << testMe->isEnd() << endl;                                          cin.ignore();
    cout << "lastMove() ->"; cout << "State: " << testMe->lastMove().getState() << endl;            cin.ignore();
    cout << "numberOvMoves() ->"; cout << testMe->numberOfMoves() << endl;                          cin.ignore();
    cout << "Operator(1,5) ->"; cout << "State: " << testMe->operator()(1,5).getState() << endl;    cin.ignore();
    cout << "setSize(10)   ->" << endl; testMe->setSize(10); testMe->print();                       cin.ignore();
    cout << "writeToFile(ignoreMe.txt) ->"; testMe->writeToFile("ignoreMe.txt");                    cin.ignore();
    }
    catch(const HexErrorHandler& e)
    {
        cerr << e.what() << '\n';
    }
    

    cout << "Test Finished, I hope everything is OK :)" << endl;
}

void TestGlobalFunction()
{
    bool trash;
    HexAdapter<vector> adapterVector(trash); HexAdapter<deque> adapterDeque(trash);
    HexArray1D Array1D(trash); HexVector Vector(trash);
    cout << "Test 1 Running -> All games created from scratch and had size 6" << endl;
    AbstractHex* Games1[3] = {new HexAdapter<vector>(trash), new HexVector(trash), new HexArray1D(trash)};
    cout << "Result: " << checkValidHex(Games1, 3) << endl;
    cout << "Test 2 Running -> Sended a invalid file which contains boardSize = 5." << endl;
    adapterVector.readFromFile("test/invalid0.txt");
    AbstractHex* Games2[1]= {&adapterVector};
    cout << "Result: " << checkValidHex(Games2, 1) << endl;
    cout << "Test 3 Running -> Sended a invalid file which contains invalid char on HexBoard." << endl;
    Vector.readFromFile("test/invalid1.txt");
    AbstractHex* Games3[1]= {&Vector};
    cout << "Result: " << checkValidHex(Games3, 1) << endl;
    cout << "Test 4 Running -> Sended those 2 invalid and one object from created scratch" << endl;
    AbstractHex* Games4[3]= {&Vector,&adapterVector, new HexArray1D(trash)};
    cout << "Result: " << checkValidHex(Games4, 3) << endl;
    cout << "Test 4 Running -> Sended a valid file and one object from created scratch" << endl;
    Array1D.readFromFile("test/test0.txt");
    AbstractHex* Games5[2]= {&Array1D, new HexVector(trash)};
    cout << "Result: " << checkValidHex(Games5, 2) << endl;

    cout << endl << "Test Over! I hope everthing went well! <3 " << endl;
}

void main_helper(vector<AbstractHex*> Games, bool select)
{
    cout << "There are " << AbstractHex::getActiveGames() << " active games." << endl << "All Games are:" << endl;
    for (int i = 0; i < AbstractHex::getAllGames(); i++)
    {
        if (Games[i]->getGameState() == winner)
            cout << "game[" << i << "]" << " ->>> ENDED with a winner" << endl; 
        else
            cout << "game[" << i << "]" << " -> Still Active" << endl; 
    }
    if (select)
        cout << "Select a game with number: ";
}

void game_helper(vector<AbstractHex*> Games)
{
    cout << "Which type of game do you want?" << endl;
   cout << "1- HexVector Class" << endl
        << "2- HexArray1D Class" << endl
        << "3- HexAdapter<vector> Class" << endl
        << "4- HexAdapter<deque> Class" << endl;
    int select;
    cin >> select;
    checkCinForFail();
    if (select == 1) Games.push_back(new HexVector);
    else if (select == 2) Games.push_back(new HexArray1D);
    else if (select == 3) Games.push_back(new HexAdapter<vector>);
    else if (select == 4) Games.push_back(new HexAdapter<deque>);
    else cout << "Invalid" << endl;
}

int setSelect(vector<AbstractHex*> Games)
{
    if (AbstractHex::getActiveGames() == 0)
    {
        cout << "There are no active games" << endl; 
        return -1;
    }
    int select;
    cin >> select;
    checkCinForFail();
    if (select >= AbstractHex::getAllGames() || select < 0) 
    {
        cout << "invalid" << endl;
        return -1;
    }
    else if (Games[select]->getGameState() == winner)
    {
        cout << "This game has ended. " << endl;
        return -1;
    }
    
    return select;
}

void checkCinForFail()
{
    if(cin.fail())
    {
        cerr << "Your input is invalid" << endl;
        cin.clear();
        cin.ignore(100,'\n');
    }
}
