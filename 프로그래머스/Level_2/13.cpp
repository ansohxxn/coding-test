#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int n = number.size();
    
    int start = 0;
    int end = k;
    
    int max = 0;
    int lastMaxIndex = 0;
    
    for(int i = 0; i < n - k; i++)
    {
        for(int j = start; j <= end; j++)
        {
            if(max < number[j])
            {
                max = number[j];
                lastMaxIndex = j;
            }
        }
        answer.append(1, max);
        start = lastMaxIndex + 1;
        end++;
        max = 0;
    }
    
    return answer;
}