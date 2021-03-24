#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;
    int tempMax = 0;
    int n = sticker.size();
    vector<int> dp(sticker.size());  
    
    if (sticker.size() == 1)
        return sticker[0];
    
    dp[0] = sticker[0];
    dp[1] = dp[0];
    for(int i = 2; i < n - 1; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
    dp[n - 1] = dp[n - 2];
    tempMax = *max_element(dp.begin(), dp.end());
    
    dp[0] = 0;
    for(int i = 1; i < n; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
    
    answer = max(tempMax, *max_element(dp.begin(), dp.end()));
    
    return answer;
}