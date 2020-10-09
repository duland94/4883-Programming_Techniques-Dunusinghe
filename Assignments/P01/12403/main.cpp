//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Dulan Dunusinghe
// Email:            dulandunusinghe@gmail.com
// Course:           CMPS 4883 Fall 2020
//
// Description:      The job of this program perform 2 operations which are donate   
//                   money to a fund and to report the total funds.
//                  
//       
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int main(){
  int T;
  int money;
  int donation;
  string operation;
  
  cin >> T;
  money = 0;

  for(int i = 0; i < T; i++){
    cin >> operation;

    if(operation == "donate"){
      cin >> donation;
      money += donation;
    }
    
    else {
      cout << money <<endl;
    }
  }
}
