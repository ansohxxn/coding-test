#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for(int num = begin; num <= end; ++num){
        if (num == 1){
            answer.push_back(0);
            continue;
        }
        bool found = false;
        for (int i = 2; i <= sqrt(num); ++i){
            if (num % i == 0 && num / i <= 10000000){
                answer.push_back(num / i);
                found = true;
                break;
            }
        }
        if (!found) answer.push_back(1);
    }
    return answer;
}