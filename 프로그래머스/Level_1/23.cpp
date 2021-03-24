#include <string>
#include <vector>
#include<ctype.h>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    answer.resize(s.size());
    
    for(int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            if (s[i] + n > 'Z')
                answer[i] = s[i] + n - 26;
            else
                answer[i] = s[i] + n;
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            if (s[i] + n > 'z')
                answer[i] = s[i] + n - 26;
            else
                answer[i] = s[i] + n;
        }
        else
            answer[i] = s[i];
    }
    
    return answer;
}