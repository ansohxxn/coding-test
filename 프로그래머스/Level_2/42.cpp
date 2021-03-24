#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    
    int max = *max_element(arr.begin(), arr.end());
    int cur = max;
    while(true)
    {
        bool flag = true;
        for(int i = 0; i < arr.size(); i++)
        {
            if (cur % arr[i] != 0)
            {
                flag = false;
                break;
            }
        }
        
        if (flag)
        {
            answer = cur;
            break;
        }
        else
            cur += max;
    }
    
    return answer;
}