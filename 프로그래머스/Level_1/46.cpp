#include <string>
#include <vector>

using namespace std;

int pow(int base, int n)
{
    if (n == 0) return 1;
    return base * pow(base, n - 1);
}

int solution(string dartResult) {
    int answer = 0;
    vector<int> vec;

    int i = 0, num = 0;
    while (i < dartResult.length())
    {
        if (dartResult[i] == '1' && dartResult[i + 1] == '0')
        {
            num = 10;
            i += 2;
        }
        else
        {
            num = dartResult[i] - '0';
            i++;
        }
        
        if (dartResult[i] == 'S')
            vec.push_back(pow(num, 1));
        else if (dartResult[i] == 'D')
            vec.push_back(pow(num, 2));
        else if (dartResult[i] == 'T')
            vec.push_back(pow(num, 3));
        
        i++;

        if (i < dartResult.length())
        {
            int back = vec.size() - 1;
            if (dartResult[i] == '*')
            {
                vec[vec.size() - 1] *= 2;
                if ((vec.size() - 2) >= 0)
                    vec[vec.size() - 2] *= 2;
                i++;
            }
            else if (dartResult[i] == '#')
            {
                vec[vec.size() - 1] *= -1;
                i++;
            }
        }
    }

    for (auto& elem : vec)
        answer += elem;

    return answer;
}