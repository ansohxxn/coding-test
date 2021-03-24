#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	vector<vector<int>> vertex(n + 1);
	for (int i = 0; i < edge.size(); i++)
	{
		vertex[edge[i][0]].push_back(edge[i][1]);
		vertex[edge[i][1]].push_back(edge[i][0]);
	}

	vector<bool> found(n + 1);
    vector<int> parent(n + 1);
    vector<int> distance(n + 1);
    queue<int> waiting;
    
    found[1] = true;
    parent[1] = 1;
    distance[1] = 0;
    waiting.push(1);
    
    while(!waiting.empty())
    {
        int nowNode = waiting.front();
        waiting.pop();
        
        for (int i = 0; i < vertex[nowNode].size(); i++)
        {
            int child = vertex[nowNode][i];
            if (!found[child])
            {
                waiting.push(child);
                found[child] = true;
                parent[child] = nowNode;
                distance[child] = distance[nowNode] + 1;
            }
        }
    }
	
    int maxDist = *max_element(distance.begin(), distance.end());
    for(int i = 1; i < distance.size(); i++)
    {
        if (distance[i] == maxDist)
            answer++;
    }

    
	return answer;
}