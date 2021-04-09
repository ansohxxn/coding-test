#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2000000000
using namespace std;

vector<int> answer(2);
int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    int start = 0;
    int end = N - 1;
    int min = INF;
    while (start < end) {
        int sum = arr[start] + arr[end];

        if (min > abs(sum)) {
            min = abs(sum);
            answer[0] = arr[start];
            answer[1] = arr[end]; 

            if (sum == 0)
                break;
        }

        if (sum < 0) 
            start++;
        else 
            end--;
    }

    cout << answer[0] << " " << answer[1];
}