#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct cmp
{
    bool operator() (const int & a, const int & b)
    {
        return a > b;
    }
};

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, cmp> minHeap;
    
    for (auto & oper : operations)
    {
        
        if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() < minHeap.top())
        {
            while(!maxHeap.empty())
                maxHeap.pop();
            while(!minHeap.empty())
                minHeap.pop();
        } 
        
        if (oper == "D 1")
        {
            if (!maxHeap.empty() && !minHeap.empty())
                    maxHeap.pop();
        }
        else if (oper == "D -1")
        {
            if (!maxHeap.empty() && !minHeap.empty())
                    minHeap.pop();
        }
        else
        {
            maxHeap.push(stoi(oper.substr(2)));
            minHeap.push(stoi(oper.substr(2)));
        }
    }
    
    
    if (maxHeap.empty() || minHeap.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(maxHeap.top());
        answer.push_back(minHeap.top());
    }

    return answer;
}