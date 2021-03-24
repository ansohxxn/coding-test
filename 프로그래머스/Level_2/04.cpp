#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;
    
    for(int i = 0; i < speeds.size(); i++)
    {
        if ((100 - progresses[i]) % speeds[i] == 0)
            q.push((100 - progresses[i]) / speeds[i]);
        else
            q.push((100 - progresses[i]) / speeds[i] + 1);
    }
    
    int count = 0;  
    int temp = q.front();
    while (true)
    {
        if (temp >= q.front())
        {
            count++;
            q.pop();
            if (q.empty())
            {
                answer.push_back(count);
                break;
            }
        }
        else
        {
            answer.push_back(count);
            count = 0;
            temp = q.front();
        }
    }
    
    return answer;
}