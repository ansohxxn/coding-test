#include <string>
#include <vector>

using namespace std;

void DFS(vector<vector<bool>> queen, int& answer, int row)
{
    if (row == queen.size()) {
        answer++;            
        return;
    }

    for (int col = 0; col < queen[row].size(); ++col) {
        bool isOk = true;
        for (int i = row - 1, j = 1; i >= 0; --i, ++j) {
            bool con1 = queen[i][col];
            bool con2 = col - j >= 0 && queen[i][col - j];
            bool con3 = col + j <= queen.size() - 1 && queen[i][col + j];
            if (con1 || con2 || con3) {
                isOk = false;
                break;
            }
        }
        if (isOk) {
            queen[row][col] = true;
            DFS(queen, answer, row + 1);
            queen[row][col] = false;
        }
    }
}

int solution(int n) {
    int answer = 0;
    vector<vector<bool>> queen(n, vector<bool>(n, false));
    DFS(queen, answer, 0);
    return answer;
}