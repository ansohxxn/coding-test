#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    sort(works.begin(), works.end());

    while (n > 0 && works[0] != 0) {
        // 최대값 개수 찾기
        int count = 1;
        int delta = 0;
        int index = 0;
        for (int i = works.size() - 1; ; i--) {
            if (i > 0 && works[i - 1] == works[i])
                count++;
            else {
                delta = works[i] - works[i - 1];
                index = i;
                break;
            }
        }

        // 최대값들 빼주기
        if (n / count >= delta) {
            for (int i = 0; i < count; i++)
                works[index + i] -= delta;
            n -= count * delta;
        }
        else {
            for (int i = 0; i < count; i++)
                works[index + i] -= n / count;
            for (int i = 0; i < n % count; i++)
                --works[index + i];
            n = 0;
        }
    }

    for (int i = 0; i < works.size(); ++i)
        answer += (long long)works[i] * works[i];
    return answer;
}