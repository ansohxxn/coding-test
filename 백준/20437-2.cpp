#include <bits/stdc++.h>

using namespace std;

#define INF 10000

int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        string str; 
        int K;
        cin >> str;
        cin >> K;

        vector<int> alpha_pos[26];
        int answer3 = INF; int answer4 = -1;
         

        for (int j = 0; j < str.length(); j++) {
            alpha_pos[str[j] - 'a'].push_back(j);
        }
        for (int j = 0; j < 26; j++) {
            if (alpha_pos[j].size() >= K) {
                int l = 0; 
                int r = K - 1;

                int temp3 = alpha_pos[j][r] - alpha_pos[j][l] + 1; 
                int temp4 = alpha_pos[j][r] - alpha_pos[j][l] + 1;
                while (r < alpha_pos[j].size() - 1) {
                    r++; 
                    l++;
                    temp3 = min(alpha_pos[j][r] - alpha_pos[j][l] + 1, temp3);
                    temp4 = max(alpha_pos[j][r] - alpha_pos[j][l] + 1, temp4);
                }
                answer3 = min(temp3, answer3);
                answer4 = max(temp4, answer4);
            }
        }
        if (answer3 == INF) 
            cout << -1 << "\n";
        else 
            cout << answer3 << " " << answer4 << "\n";
        
    }
}
