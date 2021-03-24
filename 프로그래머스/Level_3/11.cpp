#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    
    sort(routes.begin(), routes.end(), compare);
    
    int answer = 1;
    
    int end = routes[0][1];
    
    for(int i = 1; i < routes.size(); i++)
    {        
        if (routes[i][0] > end)
        {
            answer++;
            end = routes[i][1];
        }
        else
            end = min(end, routes[i][1]);
    }
    return answer;
}