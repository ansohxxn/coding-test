#include <string>
#include <stack>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int count = 0;
    
    stack<char> stack;
    char pre = '(';
    
    for(int i = 0; i < arrangement.length(); i++)
    {
        if (arrangement[i] == '(')
        {
            stack.push(arrangement[i]);
        }
        else if (arrangement[i] == ')')
        {
            stack.pop();
            if (pre == '(')
                answer += stack.size();
            else if (pre == ')')
                count++;
        }
        pre = arrangement[i];
    }
    answer += count;
    
    return answer;
}