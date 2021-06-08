#include <bits/stdc++.h>

using namespace std;

#define MAX 10000

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--) {
        string str; 
        int K; 
        cin >> str;
        cin >> K;
        
        vector<int> count(26);
        for (int i = 0; i < str.length(); i++)
            ++count[str[i] - 'a'];
        
        int answer3 = MAX; 
        int answer4 = -1;
        for (int i = 0; i < str.length(); ++i) {
            if (count[str[i] - 'a'] < K)
                continue;

            int cnt = 0;
            for (int j = i; j < str.length(); ++j) {
                if (str[i] == str[j])
                    ++cnt;
                
                if (cnt == K) {
                    answer3 = min(answer3, j - i + 1);
                    answer4 = max(answer4, j - i + 1);
                    break;
                }
            }
        }
        
        if (answer3 == MAX || answer4 == -1) 
            cout << -1 << "\n";
        else 
            cout << answer3 << " " << answer4 << "\n";
    }
}
