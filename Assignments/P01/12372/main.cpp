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

using namespace std;

int main(){
  int T;
  int ln;
  int wd;
  int ht;

  cin >> T;

  for(int i = 0; i < T; i++){
    cin >> ln;
    cin >> wd;
    cin >> ht;

    if((ln>20) || (wd>20) || (ht>20)){
      cout << "Case " << i+1 << ": bad\n";
    }
    
    else{
      cout << "Case " << i+1 << ": good\n";
    }
  }
}
