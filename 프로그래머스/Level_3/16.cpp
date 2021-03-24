#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    
    long long start = 1;
    long long end = (long long)n * *max_element(times.begin(), times.end());
    long long answer = end;
    long long mid;
    
    while(start <= end)
    {
        mid = (start + end) / 2;
        long long man = 0;
        for(auto time : times)
            man += mid / time;
        
        if (man < n)
            start = mid + 1;
        else
        {
            end = mid - 1;
            answer = mid;
        }
    }
    
    return answer;
}