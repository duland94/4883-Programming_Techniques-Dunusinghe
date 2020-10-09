//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Dulan Dunusinghe
// Email:            dulandunusinghe@gmail.com
// Course:           CMPS 4883 Fall 2020
//
// Description:      The job of this program is to read two numerical values from 
//                   an input file and output the relationship between them(The first
//                   greater than the second, less than the second or equal to the second)
//       
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream Cin;
  Cin.open("input.txt");

  int x;
  int y;
  int z;

  Cin>>x;

  for(int i = 0; i < x; i++)
  {
    Cin >> y;
    Cin >> z;
    if (y < z)
      cout << "<" <<endl;
    else if(y > z)
      cout << ">" << endl;
    else 
      cout << "=" << endl;
  }
  
}
