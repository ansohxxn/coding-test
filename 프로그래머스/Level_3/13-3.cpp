#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	vector<vector<int>> graph(n, vector<int>(n));
	for (int i = 0; i < costs.size(); i++)
	{
		graph[costs[i][0]][costs[i][1]] = costs[i][2];
		graph[costs[i][1]][costs[i][0]] = costs[i][2];
	}

	vector<int> visited;
	vector<int> unvisited;

	visited.push_back(0);
	for (int i = 1; i < n; i++)
		unvisited.push_back(i);

	for (int i = 1; i < n; i++)
	{
		int min = INT_MAX;
		int min_index = 0;

		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < n - i; k++)
			{
				if (graph[visited[j]][unvisited[k]] > 0 && min > graph[visited[j]][unvisited[k]])
				{
					min = graph[visited[j]][unvisited[k]];
					min_index = k;
				}
			}
		}

		visited.push_back(unvisited[min_index]);
		unvisited.erase(unvisited.begin() + min_index);
		answer += min;
	}

	return answer;
}