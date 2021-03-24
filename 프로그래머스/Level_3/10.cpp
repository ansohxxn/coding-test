#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct compare_queue
{
	bool operator() (vector<int> a, vector<int> b)
	{
		return a[1] > b[1];
	}
};

bool compare_sort(vector<int> a, vector<int> b)
{
	if (a[0] == b[0])
		return a[1] < b[1];
	return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
	int answer = 0;

	priority_queue<vector<int>, vector<vector<int>>, compare_queue> waiting;
    queue<vector<int>> processing;

	sort(jobs.begin(), jobs.end(), compare_sort);

	int index = 0;   
    int time = 0;
    while (index < jobs.size() || !waiting.empty())
    {
        if (index < jobs.size() && jobs[index][0] <= time)
        {
            waiting.push(jobs[index]);
            index++;
            continue;
        }
        
        if (!waiting.empty())
        {
            time += waiting.top()[1];  
            answer += time - waiting.top()[0];
            waiting.pop();
        }
        else
        {
            time = jobs[index][0];
        }
    }

	return answer / jobs.size();
}