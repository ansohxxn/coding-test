#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const char& a, const char& b)
{
    if (a >= 'A' && b <= 'z') // a는 대문자, b는 소문자
        return a > b;
    return a < b;
}

string solution(string s) {
    string answer = "";
    vector<char> v;
    
    for(int i = 0; i < s.length(); i++)
        v.push_back(s[i]);
    
    sort(v.begin(), v.end(), cmp);
    
    answer.resize(v.size());
    for(int i = 0; i < v.size(); i++)
        answer[i] = v[i];
    
    return answer;
}