//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Dulan Dunusinghe
// Email:            dulandunusinghe@gmail.com
// Course:           CMPS 4883 Fall 2020
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include<string>
#include <vector>
#include <queue>

using namespace std;

int main(){
    //Declare input operator and input file
    ifstream Cin;  
    Cin.open("input.txt");

    //VARIABLES-----------------------------------------
    int t_num;
    int t_size;
    int t_members;
    int Case;
    int mNum; 
    string operation;
    Case= 1;
    //--------------------------------------------------
    
    //read in the number of teams
    Cin>> t_num; 

    while(t_num != 0){

      //NECESSARY DATA STRUCTURES------------------------------
        //stores the team number in order
        queue<int> T; 
        //stores team members in order
        vector<queue<int>> Tmems(1000);
        //store member's team number 
        vector <int> teamNum(1000000); 
      //-----------------------------------------------------------
    
        for(int i = 0; i <t_num; i++){
            //read in the size of each team
            Cin >> t_size;  
            for(int j = 0; j <t_size;j++){
                Cin >> t_members;
                //storing the team number in the vector
                teamNum[t_members] = i;   
            }}

        cout << "Scinario#" << Case++ << endl;
        //Reads the operations
        Cin >> operation; 
        while (operation != "STOP"){
            if(operation == "ENQUEUE"){
                Cin >> mNum;
                if(Tmems[teamNum[mNum]].empty())
                    T.push(teamNum[mNum]);
                Tmems[teamNum[mNum]].push(mNum);
            }

           if(operation == "DEQUEUE"){
                cout<< Tmems[T.front()].front() << endl;
                Tmems[T.front()].pop();

                if(Tmems[T.front()].empty()){
                    T.pop();
                }
            }
            Cin >> operation;
        }
        cout << endl;
        Tmems.clear();
        teamNum.clear();
        Cin>> t_num;
    }
    return 0;
}
