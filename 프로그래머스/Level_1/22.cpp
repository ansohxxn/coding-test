#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    if (s[0] == '+')
        answer = stoi(s.substr(1));
    else if (s[0] == '-')
        answer = (-1) * stoi(s.substr(1));
    else
        answer = stoi(s);
    
    return answer;
}