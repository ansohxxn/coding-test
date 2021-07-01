#include <vector>

using namespace std;

int DP[300001][2];
vector<vector<int>> Tree;
vector<int> Sales;
#define MAX 10000

void dfs(int now) {
    if (Tree[now].empty()) {
        DP[now][0] = 0;
        DP[now][1] = Sales[now - 1];
        return;
    }

    int sum = 0;
    int min_diff = MAX;
    bool forced_to_attend = true;
    for (int i = 0; i < Tree[now].size(); ++i) {
        int next = Tree[now][i];
        dfs(next);

        sum += min(DP[next][0], DP[next][1]);
        if (DP[next][0] >= DP[next][1])
            forced_to_attend = false;
        else
            min_diff = min(min_diff, DP[next][1] - DP[next][0]);
    }

    if (forced_to_attend) 
        DP[now][0] = sum + min_diff;
    else 
        DP[now][0] = sum;
    
    DP[now][1] = sum + Sales[now - 1];
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;

    Sales = sales;
    Tree.resize(sales.size() + 1);
    for (int i = 0; i < links.size(); ++i) {
        int parent = links[i][0];
        int child = links[i][1];
        Tree[parent].push_back(child);
    }

    dfs(1);
    answer = min(DP[1][0], DP[1][1]);
    return answer;
}