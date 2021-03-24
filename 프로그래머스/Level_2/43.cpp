#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> check;
    
    check.push(s[0]);
    for(int i = 1; i < s.length(); i++){
        if (!check.empty() && s[i] == check.top())
            check.pop();
        else
            check.push(s[i]);
    }
    
    if (check.empty()) return 1;
    else return 0;
}