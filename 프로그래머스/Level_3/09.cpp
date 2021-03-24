#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    vector<vector<int>> dp(triangle.size());
    
    // 초기값
    for(int i = 0; i < triangle.size(); i++)
        dp.back().push_back(triangle.back()[i]);
    
    // DP
    for(int i = triangle.size() - 2; i >= 0; i--)
    {
        for(int j = 0; j <= i; j++)
            dp[i].push_back(max(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j]);
    }
        
    answer = dp[0][0];
    return answer;
}