#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        cin >> n;
        vector<string> arr(n);
        for (int j = 0; j < n; ++j)
            cin >> arr[j];
        
        sort(arr.begin(), arr.end());
        unordered_set<string> hash_set;
        bool flag = false;
        for (int j = 0; j < n; ++j) {
            string str = "";
            for (int k = 0; k < arr[j].length() - 1; ++k) {
                str += arr[j][k];
                if (hash_set.find(str) != hash_set.end()) {
                    flag = true;
                    cout << "NO" << '\n';
                    break;
                }
            }
            if (flag) break;
            hash_set.insert(arr[j]);
        }
        if (!flag) cout << "YES" << '\n';
    }
}