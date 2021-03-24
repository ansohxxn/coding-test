#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer(2);
    
    // 최대공약수 answer[0]
    for(int i = 1; i <= min(n, m); ++i)
        if (n  % i == 0 && m % i == 0)
            answer[0] = i;
    
    // 최소공배수 answer[1]
    answer[1] = answer[0] * (n / answer[0]) * (m / answer[0]);

    return answer;
}