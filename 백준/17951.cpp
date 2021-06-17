#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;
    
    vector<int> papers(N);
    for (int i = 0; i < N; ++i)
        cin >> papers[i];

    int start = 0;
    int end = 0;
    for (int i = 0; i < N; ++i)
        end += papers[i];

    int answer = 0;
    while (start <= end) {
        
        int mid = (start + end) / 2;

        int group_count = 0;
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += papers[i];
            if (sum >= mid) { 
                sum = 0;
                ++group_count; 
            }
        }

        if (group_count >= K) {
            start = mid + 1;  
            answer = mid;
        }
        else
            end = mid - 1;  
    }

    cout << answer;
}