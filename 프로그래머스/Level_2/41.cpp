#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = s;
    
    bool newWord = true;
    for(int i = 0; i < answer.length(); i++)
    {
        if (answer[i] == ' ')
            newWord = true;
        else if (newWord)
        {
            newWord = false;
            if (answer[i] >= 'a' && answer[i] <= 'z')
                answer[i] -= 32;

        }
        else
        {
            if (answer[i] >= 'A' && answer[i] <= 'Z')
                answer[i] += 32;
        }
    }
    
    return answer;
}