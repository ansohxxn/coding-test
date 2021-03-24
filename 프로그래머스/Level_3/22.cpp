#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool board[101][101][2]; // [y][x][0] 기둥  [y][x][1] 보
int num = 0;
bool IsColumnOK(int x, int y) {
    bool cond1 = y == 0;
    bool cond2 = board[x][y][1] || (x - 1 >= 0 && board[x - 1][y][1]);
    bool cond3 = y - 1 >= 0 && board[x][y - 1][0];
    return cond1 || cond2 || cond3;
}

bool IsPaperOK(int x, int y) {
    bool cond1 = (board[x][y - 1][0] || (x + 1 <= num && board[x + 1][y - 1][0])); // y - 1 생략
    bool cond2 = (x - 1 >= 0 && board[x - 1][y][1]) && (x + 1 <= num && board[x + 1][y][1]);
    return cond1 || cond2;
}

bool compare(vector<int> a, vector<int> b) {
    if (a[0] == b[0] && a[1] == b[1])
        return a[2] < b[2];
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    num = n;
    for (int i = 0; i < build_frame.size(); ++i) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        if (build_frame[i][3] == 0) {
            if (build_frame[i][2] == 0) { // 기둥 삭제
                if (!board[x][y][0])
                    continue;

                board[x][y][0] = false; // 삭제
                if (y + 1 <= n && board[x][y + 1][0] && !IsColumnOK(x, y + 1)) {
                    board[x][y][0] = true; // 삭제취소
                    continue;
                }
                if (y + 1 <= n && board[x][y + 1][1] && !IsPaperOK(x, y + 1)) {
                    board[x][y][0] = true; // 삭제취소
                    continue;
                }
                if (x - 1 >= 0 && y + 1 <= n && board[x - 1][y + 1][1] && !IsPaperOK(x - 1, y + 1)) {
                    board[x][y][0] = true; // 삭제취소
                    continue;
                }
            }
            else {  // 보 삭제
                if (!board[x][y][1])
                    continue;

                board[x][y][1] = false; // 삭제
                if (board[x][y][0] && !IsColumnOK(x, y)) {
                    board[x][y][1] = true; // 삭제취소
                    continue;
                }
                if (x + 1 <= n && board[x + 1][y][0] && !IsColumnOK(x + 1, y)) {
                    board[x][y][1] = true; // 삭제취소
                    continue;
                }
                if (x - 1 >= 0 && board[x - 1][y][1] && !IsPaperOK(x - 1, y)) {
                    board[x][y][1] = true; // 삭제취소
                    continue;
                }
                if (x + 1 <= n && board[x + 1][y][1] && !IsPaperOK(x + 1, y)) {
                    board[x][y][1] = true; // 삭제취소
                    continue;
                }
            }
        }
        else {
            if (build_frame[i][2] == 0) { // 기둥 추가
                if (IsColumnOK(x, y))
                    board[x][y][0] = true;
            }
            else {  // 보 추가
                if (IsPaperOK(x, y))
                    board[x][y][1] = true;
            }
        }
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (board[i][j][0]) {
                vector<int> v(3);
                v[0] = i;
                v[1] = j;
                v[2] = 0;
                answer.push_back(v);
            }
            if (board[i][j][1]) {
                vector<int> v(3);
                v[0] = i;
                v[1] = j;
                v[2] = 1;
                answer.push_back(v);
            }
        }
    }

    sort(answer.begin(), answer.end(), compare);

    return answer;
}