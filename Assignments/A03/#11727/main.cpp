//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Dulan Dunusinghe
// Email:            dulandunusinghe@gmail.com
// Course:           CMPS 4883 Fall 2020
//
// Description:      The job of this program is to read 3 values from an input filr 
//                   and find the median value of the three. 
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
  int S[3];

  Cin >> T;

  for(int i = 0; i < T; i++){
    Cin >> S[0];
    Cin >> S[1];
    Cin >> S[2];
    for(int j = 0; j < 2; j++)
    {
      for(int k = 0; k < 2 - j; k++)
      {
        if(S[k] > S[k+1])
        {
          int temp = S[k];
          S[k] = S[k+1];
          S[k+1] = temp;
        }
      }
    }
    cout << "Case " << i+1 << ": " << S[1] << "\n";
  }
}
