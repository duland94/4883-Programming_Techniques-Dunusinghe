#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

bool openingBracket(char c)
{
    if (c == '(' || c == '[')
    {
        return true;
    }
    return false;
}

bool closingBracket(char c)
{
    if (c == ')' || c == ']')
    {
        return true;
    }
    return false;
}

int main()
{
    int t;
    char s[200];
    scanf("%d", &t);
    gets(s);
    while (t--)
    {
        gets(s);
        stack<char> st;
        for (int i = 0; s[i]; i++)
        {
            if (openingBracket(s[i]))
            {
                st.push(s[i]);
            }
            else if (closingBracket(s[i]))
            {
                if (s[i] == ')')
                {
                    if (!st.empty() && st.top() == '(')
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(s[i]);
                    }
                }
                else if (s[i] == ']')
                {
                    if (!st.empty() && st.top() == '[')
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(s[i]);
                    }
                }
            }
        }
        if (st.empty())
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}