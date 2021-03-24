#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int& answer, int N, int target, int calc, int depth)
{
    if (calc == target)
    {
        answer = min(answer, depth);
        return;
    }
    
    int operand = 0;
    for(int i = 1; i <= 8 - depth; i++)
    {
        operand = operand * 10 + N;
        
        DFS(answer, N, target, calc + operand, depth + i);
        DFS(answer, N, target, calc - operand, depth + i);
        DFS(answer, N, target, calc * operand, depth + i);
        DFS(answer, N, target, calc / operand, depth + i);
    }
    
    return;
}

int solution(int N, int number) {
    int answer = 9;
    
    DFS(answer, N, number, 0, 0);
    
    if (answer == 9) answer = -1;
    return answer;
}