#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> arr(2);
    arr[0] = 1;
    arr[1] = 1;
    
    for(int i = 2; i <= n; ++i)
        arr.push_back((arr[i - 1] + arr[i - 2]) % 1000000007);
    answer = arr[n];
    
    return answer;
}