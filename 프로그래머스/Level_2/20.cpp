#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int i = 0;
    int j = people.size() - 1;
    
    while(true)
    {
        if (i == j)
        {
            answer++;
            break;
        }
        
        if (i > j)
            break;   
        
        if (people[i] + people[j] <= limit)
            i++;
        
        j--;
        
        answer++;
    }
    
    return answer;
}