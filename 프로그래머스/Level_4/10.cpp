#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    int N = cookie.size();

    for (int m = 0; m < N - 1; ++m) {
        int left_idx = m;
        int right_idx = m + 1;
        int left_son = cookie[left_idx];
        int right_son = cookie[right_idx];

        while (left_idx >= 0 && right_idx < N) {
            if (left_son < right_son) {
                if (--left_idx >= 0) 
                    left_son += cookie[left_idx];
            }
            else if (left_son > right_son) {
                if (++right_idx < N)
                    right_son += cookie[right_idx];
            }
            else {
                if (answer < left_son)
                    answer = left_son;
                if (--left_idx >= 0)
                    left_son += cookie[left_idx];
                if (++right_idx < N)
                    right_son += cookie[right_idx];
            }
        }
    }
    return answer;
}