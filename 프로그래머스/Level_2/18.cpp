#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> citations) {

    sort(citations.begin(), citations.end(), greater<int>());
    
    for(int i = citations[0]; i > 0; i--)
    {
        int count = 0;
        for(auto & elem : citations)
        {
            if (elem >= i)
            {
                count++;
                if (i == count)
                    return count;
            }
        }
    }
}