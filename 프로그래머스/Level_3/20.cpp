#include <vector>

using namespace std;

int MOD = 20170805;
#define down first
#define right second

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    
    // {아래쪽 바라볼 때 경로의 수, 오른쪽 바라볼 때 경로의 수} pair 를 원소로하는 2차원 dp 테이블
    vector<vector<pair<int, int>>> dp(m, vector<pair<int, int>>(n, { 0, 0 })); 
    for (int i = 1; i < m; ++i){
        if (city_map[i][0] == 1)
            break;
        dp[i][0].down = 1; 
    }
        
    for (int i = 1; i < n; ++i){
        if (city_map[0][i] == 1) 
            break;
        dp[0][i].right = 1; 
    }
        
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            // down 아래쪽을 바라볼 때 (= 즉, 위쪽에서 왔을 때)
            if (city_map[i - 1][j] == 0) 
                dp[i][j].down = (dp[i - 1][j].down + dp[i - 1][j].right) % MOD; 
            if (city_map[i - 1][j] == 1) 
                dp[i][j].down = 0; 
            if (city_map[i - 1][j] == 2) 
                dp[i][j].down = dp[i - 1][j].down;

            // right 오른쪽을 바라볼 때 (= 즉, 왼쪽에서 왔을 때)
            if (city_map[i][j - 1] == 0) 
                dp[i][j].right = (dp[i][j - 1].down + dp[i][j - 1].right) % MOD;
            if (city_map[i][j - 1] == 1) 
                dp[i][j].right = 0;
            if (city_map[i][j - 1] == 2) 
                dp[i][j].right = dp[i][j - 1].right;
        }
    }
    
    if (m == 1 && n == 1) 
        answer = 1;
    else
        answer = (dp[m - 1][n - 1].down + dp[m - 1][n - 1].right) % MOD;
    
    return answer;
}