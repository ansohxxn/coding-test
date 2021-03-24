#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {

    vector<int> length(s.length() + 1);
    int count = 0;
    for (int i = 1; i <= s.length(); i++)
    {
        int next = 0;
        while (next < s.length())
        {
            string sub = s.substr(next, i);
            int count = 1;
            for (int k = next + i; k < s.length(); k += i)
            {
                if (sub == s.substr(k, i))
                {
                    next += i;
                    count++;
                }
                else
                    break;
            }

            if (count == 1)
                length[i] += sub.length();
            else if (count > 1)
                length[i] += sub.length() + to_string(count).length();

            next += i;
        }
    }

    return *min_element(length.begin() + 1, length.end());
}