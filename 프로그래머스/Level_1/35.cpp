#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = num;
    if (n == 1) return 0;
    
    while(answer < 500)
    {
        if(n % 2 == 0)
            n /= 2;
        else
            n = n * 3 + 1;
        answer++;
        
        if (n == 1) return answer;
    }
    
    if (answer == 500) return -1;
}