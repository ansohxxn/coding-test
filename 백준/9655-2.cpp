#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    // 완벽하게 게임하다 -> 이길 수 있는 최선의 방향으로 늘 선택함.

    vector<bool> dp(N + 1); // dp[i] = true : 돌이 i 개일 때 상근이 이김.  dp[i] = false : 돌이 i 개일 때 창영이 이김.
    dp[1] = true;
    dp[2] = false;
    dp[3] = true;
    for (int i = 4; i <= N; ++i) {
        // i-1 개일 때 상근이 이긴다면 그 이후 1개는 창영이 가져가므로 i 개일 땐 창영이 이긴다.
        // i-3 개일 때 상근이 이긴다면 그 이후 3개는 창영이 가져가므로 i 개일 땐 창영이 이긴다.
        if (dp[i - 1] || dp[i - 3]) dp[i] = false;
        // i-1 개일 때 창영이 이긴다면 그 이후 1개는 상근이 가져가므로 i 개일 땐 상근이 이긴다.
        // i-3 개일 때 창영이 이긴다면 그 이후 3개는 상근이 가져가므로 i 개일 땐 상근이 이긴다.
        else if (!dp[i - 1] || !dp[i - 3]) dp[i] = true;
    }

    if (dp[N]) cout << "SK";
    else cout << "CY";
}