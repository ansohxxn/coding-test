#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 1;  
    int start = 1;
    int end = distance;
    
    sort(rocks.begin(), rocks.end());
    
    while(start <= end)
    {
        int mid = (start + end) / 2;
            
        int gap = 0;
        int lastRock = 0;
        int removeCount = 0;
        
        for(int i = 0; i <= rocks.size(); i++)
        {
            if (i == rocks.size())
                gap = distance - lastRock;
            else
                gap = rocks[i] - lastRock;
            
            if (gap < mid)
                removeCount++;
            else if (i != rocks.size())
                lastRock = rocks[i];
        }
        
        if (removeCount > n)
            end = mid - 1;
        else
        {
            start = mid + 1;
            answer = mid;
        }
    }
    
    return answer;
}