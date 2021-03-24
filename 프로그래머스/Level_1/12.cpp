#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    set<int> sorted;
    
    for(auto& e: arr)
    {
        if(e % divisor == 0)
            sorted.insert(e);
    }
    
    for(auto& e: sorted)
        answer.push_back(e);

    if(answer.empty()) answer.push_back(-1);
    
    return answer;
}