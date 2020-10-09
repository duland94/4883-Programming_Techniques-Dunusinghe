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

using namespace std;

int main() {
  int x;
  int y;
  int z;

  cin>>x;

  for(int i = 0; i < x; i++)
  {
    cin >> y;
    cin >> z;
    if (y < z)
      cout << "<" <<endl;
    else if(y > z)
      cout << ">" << endl;
    else 
      cout << "=" << endl;
  }
  
}
