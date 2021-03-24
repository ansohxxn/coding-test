#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool compare (int a, int b)
{ 
    string str_a = to_string(a) + to_string(b);
    string str_b = to_string(b) + to_string(a);
    
    return str_a > str_b;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), compare);
    
    if (numbers[0] == 0)
        return "0";
    
    for(auto & elem : numbers)
    {
        answer += to_string(elem);
    }
    
    return answer;
}