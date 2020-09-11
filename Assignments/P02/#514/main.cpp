//////////////////////////////////////////////////////////////////////////////////
//
// Author:           Dulan Dunusinghe
// Email:            dulandunusinghe@gmail.com
// Course:           CMPS 4883 Fall 2020
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    vector <int> V; //Vector to represent train
    int I; //int to represent the index of the vector
    int n; //int to represent the number of cases
    int c; //int to represent number of cases
    stack <int> S; //stack
    bool YES;
    
    cin>>n;

    while(n!=0){
        cin>>c;
        while(c!=0){
          V.push_back(c);
        
            while(!S.empty())
            S.pop();
            I =1;
            YES = true;

            for(int x = 1; x<n;x++){
            cin>> c;
            V.push_back(c);}
          
            for(int y=0;y<n;y++){
                if(V[y]>I){ 
                    while(V[y]!=I){
                        S.push(I);
                        I++;}
                    I++;
                  }
                else if(V[y]<I){
                    if(S.size()>0){
                        if(S.top()==V[y]){
                            S.pop();
                        }
                    }
                    YES =false;
                    break;
                }  
                else
                    I++;    
            }
            if(YES){
                cout << "Yes\n";} 
            else{
                cout << "No\n";}

            cin>>c;
            }
        cout << endl;
        V.clear();
        cin>>n;
    }
}
