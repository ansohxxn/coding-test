#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    if (n % 2 != 0) // 홀
    {
        answer = "수";
        for(int i = 1; i <= (n - 1)/2; i++)
            answer += "박수";
    }
    else            // 짝
    {
        for (int i = 1; i <= n/2; i++)
            answer += "수박";
    }
    
    return answer;
}