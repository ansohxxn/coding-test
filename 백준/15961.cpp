#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, D, K, C;
    cin >> N >> D >> K >> C;
    vector<int> sushi(N);
    for (int i = 0; i < N; ++i)
        cin >> sushi[i];


    int answer = 0;
    unordered_map<int, int> dishes;
    bool in_dishes = false;
    for (int i = 0; i < K; ++i) {
        if (sushi[i] == C)
            in_dishes = true;
        ++dishes[sushi[i]];
    }
    if (in_dishes) answer = dishes.size();
    else answer = dishes.size() + 1;

    
    for (int i = K; i < N + K - 1; ++i) {
        --dishes[sushi[i - K]];
        if (dishes[sushi[i - K]] == 0) {
            dishes.erase(sushi[i - K]);
            if (sushi[i - K] == C)
                in_dishes = false;
        }
        
        ++dishes[sushi[i % N]];
        if (sushi[i % N] == C)
            in_dishes = true;

        if (in_dishes) answer = max(answer, (int)dishes.size());
        else answer = max(answer, (int)dishes.size() + 1);
    }


    cout << answer;
}