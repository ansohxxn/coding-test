#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<string> a, vector<string> b)
{
	if (a[0] == b[0])
		return a[1] < b[1];
	return a[0] < b[0];
}

bool DFS(vector<vector<string>> tickets, vector<string>& answer, vector<bool> usedTickets, string start, int depth)
{
    if (depth == usedTickets.size())
    {
        return true;
    }
    
	for (int i = 0; i < tickets.size(); i++)
	{
		if (tickets[i][0] == start && !usedTickets[i])
		{
			usedTickets[i] = true;
			answer.push_back(tickets[i][1]);
            if (DFS(tickets, answer, usedTickets, tickets[i][1], depth + 1))
			    return true;
            usedTickets[i] = false;
		}
	}
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) 
{
    sort(tickets.begin(), tickets.end(), compare);
         
    vector<string> answer;
    vector<bool> usedTickets(tickets.size());
    vector<string> temp;
    answer.push_back("ICN");
    
    DFS(tickets, answer, usedTickets, "ICN", 0);
    
    return answer;
}