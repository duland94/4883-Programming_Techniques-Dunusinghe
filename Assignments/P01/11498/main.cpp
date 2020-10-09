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

using namespace std;

int main(){

  int K,X,Y, divX,divY;

  cin>>K;
  while(K!=0){
    cin>> divX >> divY;

    for(int i=0;i<K;i++){
        cin>> X >> Y;

        if(X > divX)
      {
        if(Y > divY)
          cout << "NE" << endl;
        else if(Y < divY)
          cout << "SE" << endl;
        else 
          cout << "divisa" << endl;
      }
      else if(X < divX)
      {
        if(Y > divY)
          cout << "NO" << endl;
        else if(Y < divY)
          cout << "SO" << endl;
        else 
          cout << "divisa" << endl;
      }
      else
        cout << "divisa" << endl;
    }
    cin>>K;
  }
}
