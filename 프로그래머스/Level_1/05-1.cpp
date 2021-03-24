#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) 
{
	return a.second > b.second;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<pair<int,int>> temp{make_pair(0, 0), make_pair(1, 0), make_pair(2, 0)};
    
    vector<int> one{1, 2, 3, 4, 5};
    vector<int> two{2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> three{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int i = 0; i < answers.size(); i++)
    {
        if (i >= one.size())
        {
            if (answers[i] == one[i % one.size()])
                temp[0].second++;
        }
        else
        {
            if (answers[i] == one[i])
                temp[0].second++;
        }
    }
    
    for(int i = 0; i < answers.size(); i++)
    {
        if (i >= two.size())
        {
            if (answers[i] == two[i % two.size()])
                temp[1].second++;
        }
        else
        {
            if (answers[i] == two[i])
                temp[1].second++;
        }
    }
    
    for(int i = 0; i < answers.size(); i++)
    {
        if (i >= three.size())
        {
            if (answers[i] == three[i % three.size()])
                temp[2].second++;
        }
        else
        {
            if (answers[i] == three[i])
                temp[2].second++;
        }
    }
    
    sort(temp.begin(), temp.end(), compare);
    
    
    for(int i = 0; i < 3; i++)
    {
        if (i >= 1 && temp[i - 1].second != temp[i].second)
            break;
        answer.push_back(temp[i].first + 1);
    }
    
    return answer;
}