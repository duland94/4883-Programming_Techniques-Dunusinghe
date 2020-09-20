//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Dulan Dunusinghe
// Email:            dulandunusinghe@gmail.com
// Course:           CMPS 4883 Fall 2020
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main(){
  ifstream Cin;  //Declare Cin
  Cin.open("input.txt");    //open input file
  
  //CREATE DATA STRUCTURES-------------------------
  string T; 
  stack<string> S; 
  queue<char> Q; 
  //------------------------------------------------

  while(getline(Cin,T)){
    //VARIABLES-------------------------------------
    string s ="i", t = ""; 
    //-----------------------------------------------
    
    //CLEAR STACK------------------------
    while(!S.empty()){ 
      S.pop(); 
    }
    //CLEAR QUEUE--------------------
    while(!Q.empty()){ 
      Q.pop();
    }
     
    for(int i = 0; i < T.length();i++){
        if(T.at(i)=='[')
            s = "H";  
       
        if(s == "H"){
            if(T.at(i)==']'){
                if(t !="")
                    S.push(t);
                t = "";
                s="i";
            }
           
            else{
                if(T.at(i) == '['){
                    if(t != "")
                      S.push(t);
                t= "";
                s= "H";
                }
                else 
                    t += T.at(i);
            }
        } 
        else{
            if(T.at(i)!= '[' && T.at(i) != ']')
                Q.push(T.at(i));
            }
    }
    if(s=="H")
        S.push(t);
    t = "";
    
    //PRINT PROPER TEXt--------------------
    while(!S.empty()){
        cout << S.top(); 
        S.pop();
    }
  
    while(!Q.empty()){
        cout << Q.front(); 
        Q.pop();
    }
    cout << endl;
    t= "";
}
  return 0;
}
