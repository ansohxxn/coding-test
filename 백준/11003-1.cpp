#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

struct A {
    int data; 
    int pos; 
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

    deque<A> dq;
    for (int i = 0; i < N; ++i) {
        if (!dq.empty() && i == dq.front().pos + L) 
            dq.pop_front();
        while (!dq.empty() && dq.back().data > arr[i])
            dq.pop_back();
        dq.push_back({ arr[i], i }); 
        cout << dq.front().data << " "; 
    }
}