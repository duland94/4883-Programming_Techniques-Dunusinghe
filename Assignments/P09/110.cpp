#include <iostream>

using namespace std;
const int MAXVARIABLES = 8; //allowed maximum number of numbers

char GetVarName(int var_index) { return "abcdefgh"[var_index]; }

//to pass the variable name as requested
void printVariables(int vars[], int numberOfvars)
{

    for (int i = 0; i < numberOfvars; i++)
    {
        if (i > 0)
            cout << ',';
        cout << GetVarName(vars[i]);
    }
}

void PrintIndent(int level)
{
    while (level--)
        cout << "  ";

}

void Generate(int depth, int num_vars, int vars[])
{
    if (depth == num_vars)
    {
        PrintIndent(depth);
        cout << "writeln(";
        printVariables(vars, num_vars);
        cout << ")" << endl;
        return;
    }

    int child_vars[MAXVARIABLES];
    copy(vars, vars + num_vars, child_vars);
    for (int i = depth - 1; i >= 0; i--)
    {
        PrintIndent(depth);
        if (i != depth - 1)
            cout << "else ";
        cout << "if " << GetVarName(child_vars[i])
             << " < " << GetVarName(child_vars[i + 1])
             << " then" << endl;
        Generate(depth + 1, num_vars, child_vars);
        swap(child_vars[i], child_vars[i + 1]);
    }

    PrintIndent(depth);
    cout << "else" << endl;
    Generate(depth + 1, num_vars, child_vars);
}



void drivingProgram(int numberOfVariables,int variables[])
{
for (int a = 0; a < numberOfVariables; a++)
        {
            variables[a] = a;
        }

        //print the first line
        cout << "program sort(input,output);" << endl
             << "var" << endl;

        //need to print the variables according to the user input
        printVariables(variables, numberOfVariables);

        cout << " : integer;" << endl
             << "begin" << endl
             << "  readln(";
        printVariables(variables, numberOfVariables);
        cout << ");" << endl;

        if (numberOfVariables == 1)
            cout << "  writeln(a)" << endl;
        else
            Generate(1, numberOfVariables, variables);
        cout << "end." << endl;
        if (numberOfVariables > 0)
            cout << endl;

}


int main()
{
    int numberOfPrograms;
    cin >> numberOfPrograms; //get the number of cases
    cout<<endl;
    int cases[numberOfPrograms];
    int numberOfVariables, variables[MAXVARIABLES];

   for(int a=0;a<numberOfPrograms;a++)
    {
        
        
        cin >> numberOfVariables; //get the number of variables
        cases[a]=numberOfVariables;
        cout << endl;
    
    }

    for(int b=0;b<numberOfPrograms;b++)
    {
        drivingProgram(cases[b],variables);
        
    }




    

    return 0;
}