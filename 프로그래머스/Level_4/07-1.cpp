#include <string>
#include <vector>

using namespace std;

int N, Answer;

void DFS(int open, int close) {
    if (open > N || close > N) return;
    if (open < close) return;
    
    if (open == N && close == N){
        Answer++;
        return;
    }
    
    DFS(open + 1, close);
    DFS(open, close + 1);
}

int solution(int n) {
    N = n;
    DFS(0, 0);
    return Answer;
}