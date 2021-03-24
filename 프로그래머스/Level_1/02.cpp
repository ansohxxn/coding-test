#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> temp;
    
    for(int i = 0; i < numbers.size(); i++)
        for(int j = i + 1; j < numbers.size(); j++)
            temp.insert(numbers[i] + numbers[j]);
    
    for(auto sum : temp)
        answer.push_back(sum);
    
    return answer;
}