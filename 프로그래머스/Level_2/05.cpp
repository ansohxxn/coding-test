#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

bool compare(const int & a, const int & b)
{
    return a > b;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<int> print; 
    queue<pair<int, int>>  waiting; // 인덱스, 우선 순위
    queue<int> sorted;
    
    for(int i = 0; i < priorities.size(); i++)
    {
        waiting.push(make_pair(i, priorities[i]));
    }
    
    sort(priorities.begin(), priorities.end(), compare);
    
    for(int i = 0; i < priorities.size(); i++)
    {
        sorted.push(priorities[i]);
    }
    
    while(!waiting.empty())
    {
        if (waiting.front().second < sorted.front())
        {
            waiting.push(waiting.front());
            waiting.pop();
        }
        else
        {
            print.push(waiting.front().first);
            waiting.pop();
            sorted.pop();
        }
    }
    
    while(true)
    {
        answer++;
        if (location == print.front())
            break;
        else
            print.pop();
    }
    
    return answer;
}