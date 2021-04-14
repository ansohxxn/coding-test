#include <iostream>
#include <stdio.h>
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
    int n, m;
    cin >> n;
    cin >> m;
    vector<string> s(n);
    vector<string> arr(m);
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < m; ++i) cin >> arr[i];

    unordered_set<string> hash_set;
    for (int i = 0; i < n; ++i)
        hash_set.insert(s[i]);

    int count = 0;
    for (int i = 0; i < m; ++i)
        if (hash_set.find(arr[i]) != hash_set.end())
            ++count;

    cout << count;
}