#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    int min = *min_element(arr.begin(), arr.end());

    for(int i = 0; i < arr.size(); )
    {
        if (min == arr[i])
            arr.erase(arr.begin() + i);
        else 
            i++;
    }

    if (arr.empty()) arr.push_back(-1);
    
    return arr;
}