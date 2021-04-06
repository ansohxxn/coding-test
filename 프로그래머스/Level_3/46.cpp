#include <vector>
#include <algorithm>

using namespace std;

#define INF 987654321

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log){
    int answer = 0;
    vector<vector<int>> road(n + 1);
    for (int i = 0; i < edge_list.size(); ++i) {
        road[edge_list[i][0]].push_back(edge_list[i][1]);
        road[edge_list[i][1]].push_back(edge_list[i][0]);
    }

    vector<vector<int>> dp(k, vector<int>(n + 1, INF));
    dp[0][gps_log[0]] = 0;
    for (int t = 1; t < k; ++t) {
        for (int pos = 1; pos <= n; ++pos) {

            int minValue = INF;
            for (int i = 0; i < road[pos].size(); ++i)
                minValue = min(dp[t - 1][road[pos][i]], minValue);
            
            if (gps_log[t] != pos) 
                dp[t][pos] = minValue + 1;
            else 
                dp[t][pos] = minValue;
        }
    }

    answer = dp[k - 1][gps_log[k - 1]];
    if (answer >= INF) answer = -1;
    return answer;
}