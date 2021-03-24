#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    
    for(int i = 0; i < lost.size(); i++)
    {
        for(int j = 0; j < reserve.size(); j++)
        {
            if (lost[i] == reserve[j])
            {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                answer++;
                i--;
                break;
            }
        }
    }
    
    for(int i = 0; i < lost.size(); i++)
    {
        int j = 0;
        
        while(j < reserve.size())
        {
            if(lost[i] - 1 == reserve[j] || lost[i] + 1 == reserve[j])
            {
                answer++;
                reserve.erase(reserve.begin() + j);
                break;
            }
            j++;
        }
    }
    
    return answer;
}