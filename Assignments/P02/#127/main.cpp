//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Dulan Dunusinghe
// Email:            dulandunusinghe@gmail.com
// Course:           CMPS 4883 Fall 2020
// Description:      Deal cards one by one in a row from left to right, not overlapping.                  
//                   Whenever the card matches its immediate neighbour on the left, or  
//                   matches the third card to the left, it maybe moved onto that card. 
//                   Cards match if they are of the same suit or same rank. After
//                   making a move, look to see if it has made additional moves        
//                   possible. Only the top card of each pile may be moved at any given 
//                   time. Gaps between piles should be closed up as soon
//                   as they appear by moving all piles on the right of the gap one    
//                   position to the left. Deal out the whole pack, combining cards
//                   towards the left whenever possible. The game is won if
//                   the pack is reduced to a single pile.
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main(){
  ifstream Cin;
  Cin.open("input.txt");

  vector<stack<string>> dk(52);
  bool running = true;
  string C;

  while (running){                     
        for (int i = 0; i < dk.size(); i++){
          Cin >> C;
          if (C == "#"){
                i = 100;
                running = false;}
          else
                dk[i].push(C);
         }
    
  if (!running)
            break;

  for (int i = 1; i < dk.size(); i++){
            if (i >= 3 && 
            (dk[i].top().at(0) == dk[i - 3].top().at(0) 
            || dk[i].top().at(1) == dk[i - 3].top().at(1))){

                dk[i - 3].push(dk[i].top());
                dk[i].pop();

                if (dk[i].empty()){
                    dk.erase(dk.begin() + i, dk.begin()+(i + 1));
                }
                i -= 4;                                         
            }
            if (i >= 1 && 
            (dk[i].top().at(0) == dk[i - 1].top().at(0) 
            || dk[i].top().at(1) == dk[i - 1].top().at(1))){

                dk[i - 1].push(dk[i].top());
                dk[i].pop();

                if (dk[i].empty()){
                    dk.erase(dk.begin() + i, dk.begin()+(i + 1));                               }
                i -= 2;}
        }

        if(dk.size() == 1)
            cout << dk.size() << " pile remaining: ";
        else
            cout << dk.size() << " piles remaining: ";
        
        for (int i = 0; i < dk.size(); i++){
            cout << dk[i].size();

            if(i != dk.size() - 1)
                cout << ' ';  
        }
        cout << endl;
        
    }
}
