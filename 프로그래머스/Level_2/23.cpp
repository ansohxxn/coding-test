#include <string>
#include <vector>

using namespace std;

void DFS(vector<int>& numbers, int& answer, int target, int count, int sum)
{
    if (count == numbers.size() - 1)
    {
        if (sum + numbers[count] == target) answer++;
        if (sum - numbers[count] == target) answer++;
        return;
    }
    
    DFS(numbers, answer, target, count + 1, sum + numbers[count]);
    DFS(numbers, answer, target, count + 1, sum - numbers[count]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    DFS(numbers, answer, target, 0, 0);
    
    return answer;
}