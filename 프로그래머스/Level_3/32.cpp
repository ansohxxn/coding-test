#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int start = 1;
    int end = *max_element(stones.begin(), stones.end());
    int mid = 0;

    while (start <= end) {
        mid = (start + end) / 2;

        int count = 0;
        int maxCount = 0;
        for (int i = 0; i < stones.size(); ++i) {
            if (stones[i] < mid)
                count++;
            else {
                maxCount = max(maxCount, count);
                count = 0;
            }
        }
        maxCount = max(maxCount, count);

        if (maxCount < k) {
            answer = mid;
            start = mid + 1;
        }
        else if (maxCount >= k)
            end = mid - 1;
    }
    
    return answer;
}