#include <string>
#include <vector>

using namespace std;

void HanoiTower(vector<vector<int>>& answer, int n, int start, int dest) {
    if (n == 1) {
        answer.push_back({ start, dest });
        return;
    }
    
    HanoiTower(answer, n - 1, start, 6 - start - dest);
    answer.push_back({ start, dest });
    HanoiTower(answer, n - 1, 6 - start - dest, dest);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    HanoiTower(answer, n, 1, 3);
    return answer;
}