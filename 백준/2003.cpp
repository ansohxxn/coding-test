#include <iostream>
#include <vector>
using namespace std;

int answer = 0;
int main() {
    int N, M;

    cin >> N >> M;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    int start = 0;
    int end = 0;
    int sum = arr[0];
    while (end < N) {       
        if (sum < M) {
            end++;
            if (end < N)
                sum += arr[end];
        }
        else if (sum > M) {
            sum -= arr[start];
            start++;
        }
        else if (sum == M) {
            sum -= arr[start];
            start++;   
            end++;
            if (end < N)
                sum += arr[end];
            answer++;
        }
    }

    cout << answer;
}