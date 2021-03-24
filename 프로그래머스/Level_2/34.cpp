#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for(int i = 1; i <= n / 2; i++)
    {
        int sum = 0;
        for(int j = i; j <= n; j++)
        {
            if (sum > n)
            {
                sum = 0;
                break;
            }
            else if (sum == n)
            {
                answer++;
                break;
            }
            else if (sum < n)
            {
                sum += j;
            }
        }
    }
    
    answer++;
    
    return answer;
}