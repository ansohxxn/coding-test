#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] % 2 == 0)
            answer.push_back(numbers[i] + 1);
        else {
            if ((numbers[i] & 1) && (numbers[i] & 2) == 0)
                answer.push_back(numbers[i] + 1);
            else {
                long long count = 1;
                while (true) {
                    if ((numbers[i] & count) == 0) break;
                    count *= 2;
                }
                answer.push_back(numbers[i] + count / 2);
            }
        }
    }
    return answer;
}