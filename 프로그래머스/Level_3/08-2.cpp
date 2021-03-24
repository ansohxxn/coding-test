#include <string>
#include <vector>
#include <queue>

using namespace std;

int differentCount(string str, string target) 
{
	int differentCount = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != target[i])
			differentCount++;
	}
	return differentCount;
}

struct compare 
{
	bool operator() (pair<string, int> a, pair<string, int> b)
	{
		return a.second > b.second;  
	}
};

int solution(string begin, string target, vector<string> words) {
	int answer = 0;

	priority_queue<pair<string, int>, vector<pair<string, int>>, compare> waiting_queue;
	vector<bool> pushedStr(words.size());

	waiting_queue.push(make_pair(begin, differentCount(begin, target)));

	while (!waiting_queue.empty()) 
	{
		begin = waiting_queue.top().first;
		waiting_queue.pop();

		if (begin == target) break;

		for (int i = 0; i < words.size(); i++)
		{
			if (!pushedStr[i] && differentCount(begin, words[i]) == 1)
			{
				waiting_queue.push(make_pair(words[i], differentCount(words[i], target)));
				pushedStr[i] = true;
			}
		}
		answer++;
	}

	if (begin != target) answer = 0;

	return answer;
}