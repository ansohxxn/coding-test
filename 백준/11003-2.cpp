#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

struct A {
    int data;
    int pos;
};

struct cmp { 
    bool operator()(const A& a, const A& b) {
        return a.data > b.data;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    priority_queue<A, vector<A>, cmp> pq;
    for (int i = 0; i < N; ++i) {
        pq.push({ arr[i], i });
        int pos = pq.top().pos;
        while (pos < i - L + 1) {
            pq.pop();
            pos = pq.top().pos;
        }
        cout << pq.top().data << ' ';
    }
    return 0;
}