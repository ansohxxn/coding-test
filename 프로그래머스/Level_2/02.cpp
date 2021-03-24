#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int pow(int base, int n)
{
    if (n == 0) return 1;
    return base * pow(base, n - 1);
}

string solution(int n)
{
    string answer = "";
    vector<string> num = { "1", "2", "4" };

    int sum = 0;
    int x = 1;
    while (true)
    {
        if (sum + pow(3, x) < n)
        {
            sum += pow(3, x);
            x++;
        }
        else
            break;
    }

    n = n - sum - 1;

    for(int i = 0; i < x; i++)
    {
        answer.append(num[n % 3]);
        n /= 3;
    } 

    reverse(answer.begin(), answer.end());

    return answer;
}