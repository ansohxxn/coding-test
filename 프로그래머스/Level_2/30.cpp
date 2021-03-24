#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int countOfN = 0;
    int temp = n;
    while(temp > 0)
    {
        if (temp % 2 == 1)
            countOfN++;
        temp /= 2;
    }
    
    while(true)
    {
        int count = 0;
        
        temp = ++n;
        
        while(temp > 0)
        {
            if (temp % 2 == 1)
                count++;
            temp /= 2;
        }
        
        if (countOfN == count)
            break;
    }
    
    answer = n;
    
    return answer;
}