#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int tempMax = 0;
    vector<int> dp(money.size());  // 0 부터 차례대로 해당 원소까지 털었을 때의 돈의 최댓값
    
    // 1. 첫 번째 집을 털었을 때(마지막 집은 털지 못한다.)의 전체
    dp[0] = money[0];
    dp[1] = dp[0];
    for(int i = 2; i < money.size() - 1; i++)
        dp[i] = max(dp[i - 1], dp[i - 1] + money[i]);
    dp.back() = dp[dp.size() - 2];
    tempMax = *max_element(dp.begin(), dp.end());
    
    // 2. 첫 번째 집을 털지 않았을 때의 전체
    dp[0] = 0;
    dp[1] = money[1];
    for(int i = 2; i < money.size(); i++)
        dp[i] = max(dp[i - 1], dp[i - 1] + money[i]);
    
    // 1, 2 두 경우 중 Max
    answer = max(tempMax, *max_element(dp.begin(), dp.end()));
    
    return answer;
}