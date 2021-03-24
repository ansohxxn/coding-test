#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    answer = s;
    
    const int gap = 'a' - 'A';
    int count = 1;
    
    for(int i = 0; i < answer.length(); i++)
    {
        if (answer[i] == ' ') 
            count = 0;
        else if (count % 2 == 0 && answer[i] >= 'A' && answer[i] <= 'Z')
            answer[i] += gap;
        else if (count % 2 == 1 && answer[i] >= 'a' && answer[i] <= 'z')
            answer[i] -= gap;

        count++;
    }
    
    return answer;
}