#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s)
{
    int answer = 1;
    // aabaa
    for (int center = 1; center < s.length() - 1; center++) {
        int t_max = 1;
        for (int left = center - 1, right = center + 1; left >= 0, right < s.length(); left--, right++) {
            if (s[left] != s[right]) break;
            t_max += 2;
        }
        answer = max(answer, t_max);
    }
    // aabb
    for (int center = 0; center < s.length() - 1; center++) {
        int t_max = 0;
        for (int left = center, right = center + 1; left >= 0, right < s.length(); left--, right++) {
            if (s[left] != s[right]) break;
            t_max += 2;
        }
        answer = max(answer, t_max);
    }

    return answer;
}