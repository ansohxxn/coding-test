#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    
    vector<int> dp(n + 1);

    dp[0] = 1;
    for(int i = 1; i <= n; i++)
        dp[i] = ((i % money[0] == 0) ? 1 : 0);
    
    for(int i = 1; i < money.size(); i++){
        for (int index = 0; index <= n; index++){
            if (index >= money[i])
                dp[index] = (dp[index] + dp[index - money[i]]) % 1000000007;
        }
    }
    
    answer = dp[n];
    return answer;
}