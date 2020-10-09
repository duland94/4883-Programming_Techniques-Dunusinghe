//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Dulan Dunusinghe
// Email:            dulandunusinghe@gmail.com
// Course:           CMPS 4883 Fall 2020
//
// Description:      The job of this program is to check the dimensions of a rectangular  
//                   box and check if it fits a suitcase.
//                  
//       
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ifstream Cin;
  Cin.open("input.txt");

  int T;
  int ln;
  int wd;
  int ht;

  Cin >> T;

  for(int i = 0; i < T; i++){
    Cin >> ln;
    Cin >> wd;
    Cin >> ht;

    if((ln>20) || (wd>20) || (ht>20)){
      cout << "Case " << i+1 << ": bad\n";
    }
    
    else{
      cout << "Case " << i+1 << ": good\n";
    }
  }
}
