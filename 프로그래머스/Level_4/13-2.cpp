#include <vector>

using namespace std;

int DP[300001][2];
vector<vector<int>> Tree;
vector<int> Sales;
#define MAX 10000

int dfs(int now, bool state) {

    if (DP[now][state] >= 0)
        return DP[now][state];

    if (state == false) {
        if (Tree[now].empty()) 
            return DP[now][0] = 0;

        int sum = 0;
        int min_diff = MAX;
        bool forced_to_attend = true;
        for (int i = 0; i < Tree[now].size(); ++i) {
            int next = Tree[now][i];
            sum += min(dfs(next, true), dfs(next, false));
            if (DP[next][0] >= DP[next][1])
                forced_to_attend = false;
            else
                min_diff = min(min_diff, DP[next][1] - DP[next][0]);
        }
        if (forced_to_attend)
            DP[now][0] = sum + min_diff;
        else
            DP[now][0] = sum;
    }

    else if (state == true) {
        if (Tree[now].empty())
            return DP[now][1] = Sales[now - 1];

        int sum = 0;
        for (int i = 0; i < Tree[now].size(); ++i) {
            int next = Tree[now][i];
            sum += min(dfs(next, true), dfs(next, false));
        }
        DP[now][1] = Sales[now - 1] + sum;
    }

    return DP[now][state];
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    int N = sales.size();

    Sales = sales;
    Tree.resize(N + 1);
    for (int i = 0; i < links.size(); ++i) {
        int parent = links[i][0];
        int child = links[i][1];
        Tree[parent].push_back(child);
    }

    for (int i = 1; i <= N; ++i) {
        DP[i][0] = -1;
        DP[i][1] = -1;
    }

    answer = min(dfs(1, 0), dfs(1, 1));
    return answer;
}