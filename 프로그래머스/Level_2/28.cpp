#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<int> st;
    int openCount = 0;
    int closeCount = 0;
    
    for(int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
            openCount++;
        }
        
        if (s[i] == ')')
        {
            closeCount++;
            
            if (!st.empty())
                st.pop();
        }
    }
    
    if (st.empty() && openCount == closeCount && openCount > 0 && closeCount > 0)
        return true;
    else
        return false;
}