#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int n = absolutes.size();
    for (int i = 0; i < n; ++i)
        if (signs[i] == false)
            absolutes[i] *= -1;
    for (int i = 0; i < n; ++i)
        answer += absolutes[i];
    return answer;
}