#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s)
{
    vector<int> answer;

    if (n > s) { // 만들 수 없는 경우
        answer.push_back(-1);
        return answer;
    }

    for(int i = 1; i <= n; i++)
        answer.push_back(s / n);
    
    for(int i = 1; i <= s % n; i++)
        answer[n - i]++;

    return answer;
}