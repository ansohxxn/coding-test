#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare1(pair<string, int> a, pair<string, int> b) // const & 을 없애야 했음
{
	return a.second > b.second;
}

bool compare2(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
{
	if (a.second.second == b.second.second)
		a.second.first < b.second.first;
	return a.second.second > b.second.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	unordered_map<string, int> genre_count;
	unordered_map<string, int> plays_sum;

	vector<pair<string, int>> genre_rank;
	vector<pair<string, pair<int, int>>> temp;
	vector<pair<string, pair<int, int>>> ordered;

	for (int i = 0; i < genres.size(); i++)
	{
		genre_count[genres[i]]++;

		if (plays_sum.find(genres[i]) == plays_sum.end())
		{
			plays_sum[genres[i]] = plays[i];
		}
		else
		{
			plays_sum[genres[i]] = plays_sum[genres[i]] + plays[i];
		}
	}

	for (auto & elem : plays_sum)
	{
		genre_rank.push_back(elem);
		sort(genre_rank.begin(), genre_rank.end(), compare1);
	}

	for (int i = 0; i < genre_rank.size(); i++)
	{
		for (int j = 0; j < genres.size(); j++)
		{
			if (genres[j] == genre_rank[i].first)
			{
				temp.push_back(make_pair(genres[j], make_pair(j, plays[j])));
			}

            sort(temp.begin(), temp.end(), compare2);
		}
		
		for (int k = 0; k < 2; k ++)
		{
		    answer.push_back(temp[k].second.first);
		    if (temp.size() == 1)
		        break;
		}
		
		temp.clear();
	}

	return answer;
}