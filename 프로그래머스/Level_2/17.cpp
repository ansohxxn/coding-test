#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

set<int> allComb;

void permutation(string str, int depth, int n, int r)
{
    if (depth == r)
    {
        string temp = "";
        for(int i = 0; i < r; i++)
        {
            temp += str[i]; 
        }
        
        allComb.insert(stoi(temp));
        
        return;
    }
    
    for(int i = depth; i < n; i++)
    {
        iter_swap(str.begin() + depth, str.begin() + i);
        permutation(str, depth + 1, n, r);
        iter_swap(str.begin() + depth, str.begin() + i);
    }
}
    
int solution(string numbers) {
    int answer = 0;
    
    for(int i = 1; i <= numbers.size(); i++)
    {
        permutation(numbers, 0, numbers.size(), i);
    }
    
    int count = 0;
    for(auto & num : allComb)
    {
        if (num == 0 || num == 1)
        {
            count++;
            continue;
        }
        for(int i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                count++;
                break;
            }
        }
    }
    
    answer = allComb.size() - count;
    
    return answer;
}