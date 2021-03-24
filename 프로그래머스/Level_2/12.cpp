#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(auto & elem : scoville)
    {
        pq.push(elem);
    }
    
    while(true)
    {
        if (pq.size() > 1)
        {
            int sum = pq.top();
            pq.pop();
            sum = sum + 2 * pq.top();
            pq.pop();
            pq.push(sum);
            answer++;
        }
        else
        {
            if(pq.top() < K)
            {
                answer = -1;
            }
            break;
        }
        if(pq.top() >= K)
            break;
    }
    
    return answer;
}