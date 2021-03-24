#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int global;
bool compare(const string& a, const string& b)
{
    if (a[global] == b[global])
        return a < b;
    return a[global] < b[global];
}

vector<string> solution(vector<string> strings, int n) {
    global = n;
    
    sort(strings.begin(), strings.end(), compare);
    
    return strings;
}