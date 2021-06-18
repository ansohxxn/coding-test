#include <bits/stdc++.h>

using namespace std;

#define INF 1'000'000

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF)); // INT_MAX 하면 오버플로우
    for (int i = 1; i <= N; ++i)
        dist[i][i] = 0;

    for (int i = 0; i < M; ++i) {
        int start, dest, time;
        cin >> start >> dest >> time;

        dist[start][dest] = time;
    }

    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int answer = 0;
    for (int i = 1; i <= N; ++i)
        answer = max(answer, dist[i][X] + dist[X][i]);

    cout << answer;
}