#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    
    for (auto & elem : commands)
    {
        temp = array;
        sort(temp.begin() + elem[0] - 1, temp.begin() + elem[1] - 1 + 1);
        answer.push_back(temp[elem[0] - 1 + elem[2] - 1]);
    }
    
    return answer;
}