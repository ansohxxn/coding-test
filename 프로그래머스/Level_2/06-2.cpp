#include <string>
#include <vector>
#include <stack>

using namespace std;

struct price_and_second { int price, second; };
vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n);
    stack<price_and_second> s;
    
    for(int i = 0; i < n; ++i){
        while(!s.empty() && prices[i] < s.top().price){
            answer[s.top().second] = i - s.top().second;
            s.pop();
        }
        s.push({ prices[i], i });
    }
    
    while(!s.empty()){
        answer[s.top().second] = n - s.top().second - 1;
        s.pop();
    }
    
    return answer;
}