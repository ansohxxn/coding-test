#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

void DFS(vector<vector<int>> & vertex, vector<bool> & visited, vector<int> & shortestPath, int start, int depth)
{
   for (int i = 0; i < vertex[start].size(); i++)
   {
      if (!visited[vertex[start][i]] && depth + 1 < shortestPath[vertex[start][i]])
      {
          visited[vertex[start][i]] = true;
          shortestPath[vertex[start][i]] = depth + 1;
          DFS(vertex, visited, shortestPath, vertex[start][i], depth + 1);
          visited[vertex[start][i]] = false;
      }
   }
}

int solution(int n, vector<vector<int>> edge) {
   int answer = 0;

   vector<vector<int>> vertex(n + 1);
   for (int i = 0; i < edge.size(); i++)
   {
      vertex[edge[i][0]].push_back(edge[i][1]);
      vertex[edge[i][1]].push_back(edge[i][0]);
   }

   vector<bool> visited(n + 1);
   visited[1] = true;

   vector<int> shortestPath(n + 1);
   for (int i = 1; i <= n; i++)
      shortestPath[i] = INT_MAX;
   shortestPath[1] = 0;

   DFS(vertex, visited, shortestPath, 1, 0);
    
    int maxDist = *max_element(shortestPath.begin(), shortestPath.end());
    for(int i = 1; i < shortestPath.size(); i++)
    {
        if (shortestPath[i] == maxDist)
            answer++;
    }

   return answer;
}