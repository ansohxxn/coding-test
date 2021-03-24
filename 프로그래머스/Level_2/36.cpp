#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> vec;
    
    int lastSpaceIndex = -1;
    for(int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            vec.push_back(stoi(s.substr(lastSpaceIndex + 1, i - lastSpaceIndex - 1)));
            lastSpaceIndex = i;
        }
    }
    vec.push_back(stoi(s.substr(lastSpaceIndex + 1, s.length() - lastSpaceIndex - 1)));
    
    sort(vec.begin(), vec.end());
    answer = to_string(vec.front()) + " " + to_string(vec.back());
    
    return answer;
}