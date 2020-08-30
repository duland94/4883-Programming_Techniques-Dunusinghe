//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Dulan Dunusinghe
// Email:            dulandunusinghe@gmail.com
// Course:           CMPS 4883 Fall 2020
//
// Description:      The job of this program is to determine if a city is located 
//                   Northeast. Northwest,Southeast,Southwest to a given division point.
//                  
//       
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ifstream Cin;
  Cin.open("input.txt");

  int K,X,y, divX,divY;

  Cin>>K;
  while(K!=0){
    Cin>> divX >> divY;

    for(int i=0;i<K;i++){
        Cin>> X >> y;

        if(X > divX)
      {
        if(y > divY)
          cout << "NE" << endl;
        else if(y < divY)
          cout << "SE" << endl;
        else 
          cout << "divisa" << endl;
      }
      else if(X < divX)
      {
        if(y > divY)
          cout << "NO" << endl;
        else if(y < divY)
          cout << "SO" << endl;
        else 
          cout << "divisa" << endl;
      }
      else
        cout << "divisa" << endl;
    }
    Cin>>K;
  }
}
