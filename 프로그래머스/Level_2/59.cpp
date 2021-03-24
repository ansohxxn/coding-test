#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    
    priority_queue<int> pq;

    int index = 0;
    for(int day = 0; day < k; day++)
    {
        if (day == dates[index])
        {
            pq.push(supplies[index]);
            index++;
        }
        
        if (stock == 0)
        {
            stock += pq.top();
            pq.pop();
            answer++;
        }
        
        stock--;
    }
    
    return answer;
}