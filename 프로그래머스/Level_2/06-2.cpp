#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n);
    stack<int> s;
    
    for(int i = 0; i < n; ++i){
        while(!s.empty() && prices[i] < prices[s.top()]){
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    
    while(!s.empty()){
        answer[s.top()] = n - s.top() - 1;
        s.pop();
    }
    
    return answer;
}