#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> vec(n + 1);
    
    for(int i = 2; i <= n; i++)
        for(int j = i; j <= n; j += i)
            vec[j]++;
    
    for(int i = 2; i <= n; i++)
        if (vec[i] == 1)
            answer++;
    
    return answer;
}