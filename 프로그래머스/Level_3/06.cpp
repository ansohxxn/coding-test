#include <string>
#include <vector>

using namespace std;

void DFS(vector<vector<int>>& computers, vector<bool>& visited, int computer)
{
	if (computer == computers.size())
		return;

	for (int i = 0; i < computers.size(); i++)
	{
		if (computers[computer][i] == 1 && !visited[i])
		{
			visited[i] = true;
			DFS(computers, visited, i);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	vector<bool> visited(n);

	for (int i = 0; i < computers.size(); i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			DFS(computers, visited, i);
			answer++;
		}
	}

	return answer;
}