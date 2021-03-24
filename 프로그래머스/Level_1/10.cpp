#include <string>
#include <vector>

using namespace std;

int pow(int n)
{
    if (n == 0)
        return 1;
    return 3 * pow(n - 1);
}

int solution(int n) {
    int answer = 0;
    int q = n;
    vector<int> temp;
    
    while(true)
    {
        temp.push_back(q % 3);
        q = q / 3;
        if (q == 0)
            break;
    }
    
    for(int i = 0; i < temp.size(); i++)
        answer += temp[i] * pow(temp.size() - 1 - i);
    
    return answer;
}