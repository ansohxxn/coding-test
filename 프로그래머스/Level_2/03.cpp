#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;

	vector<pair<int, int>> list;
	queue<int> wait;
	int sum = 0;

	for (auto & elem : truck_weights)
	{
		wait.push(elem);
	}

	while (true)
	{        
        if (!wait.empty() && (sum + wait.front() <= weight))
        {
            list.push_back(make_pair(wait.front(), 0));
            sum +=  wait.front();
            wait.pop();
        }
        
        for (auto & elem : list)
	    {
		    elem.second++;
	    }
        
        answer++;
        
        if (list[0].second == bridge_length)
        {
            sum -= list[0].first;
            list.erase(list.begin());
        }
        
        if (list.empty() && wait.empty())
		{
		    break;
		}
	}

	return answer + 1;
}