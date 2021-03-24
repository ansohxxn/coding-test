#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {	

	  sort(costs.begin(), costs.end(), compare);
    
    vector<bool> usedBridge(costs.size());
    vector<bool> visitedIsland(n);
    int answer = 0;
    int numOfVisitedIsland = 0;
    
    usedBridge[0] = true;
    visitedIsland[costs[0][0]] = true;
    visitedIsland[costs[0][1]] = true;
    answer += costs[0][2];
    numOfVisitedIsland += 2;
    
    while(numOfVisitedIsland < n)
    {
        for (int i = 1; i < costs.size(); i++)
        {
            if (visitedIsland[costs[i][0]] && visitedIsland[costs[i][1]])
                continue;
            
            if (usedBridge[i])
                continue;
            
            if (visitedIsland[costs[i][0]] || visitedIsland[costs[i][1]])
            {
                usedBridge[i] = true;
                visitedIsland[costs[i][0]] = true;
                visitedIsland[costs[i][1]] = true;
                numOfVisitedIsland++;
                answer += costs[i][2];          
                break;
            }
        }
    }

	return answer;
}