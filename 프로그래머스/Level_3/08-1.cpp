#include <string>
#include <vector>

using namespace std;

bool canChangeWord(string a, string b)
{
	int differentCount = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != b[i])
			differentCount++;
	}
	if (differentCount == 1) return true;
	else return false;
}

void DFS(vector<string> words, vector<bool> visited, int& answer, string target, string begin, int depth)
{
	if (begin == target)
    {
        answer = min(answer, depth);
        return;
    }

	for (int i = 0; i < words.size(); i++)
	{
		if (!visited[i] && canChangeWord(begin, words[i]))
		{
			visited[i] = true;
			DFS(words, visited, answer, target, words[i], depth + 1);
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	int answer = 100;

	vector<bool> visited(words.size());

	DFS(words, visited, answer, target, begin, 0);

    if(answer == 100) return 0;
    else return answer;
}