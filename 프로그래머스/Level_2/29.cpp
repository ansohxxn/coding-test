#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> count;
    
    string oneNumStr = "";
    for(int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            oneNumStr += s[i];
        
        if (s[i] == '}' || (s[i] == ',' && oneNumStr != ""))
        {
            count[stoi(oneNumStr)]++;
            oneNumStr = "";
        }
    }
    
    vector<pair<int, int>> sortByValue(count.begin(), count.end());
    sort(sortByValue.begin(), sortByValue.end(), compare);
    
    for(int i = 0; i < sortByValue.size(); i++)
        answer.push_back(sortByValue[i].first);
    
    return answer;  
}