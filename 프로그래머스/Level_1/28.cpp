#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    string number = to_string(n);
    
    for(int i = number.length() - 1; i >= 0; --i)
        answer.push_back(number[i] - '0');
    
    return answer;
}