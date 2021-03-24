#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<bool>> isSqaure(m, vector<bool>(n, false));
    bool canRemove = false;

    do {
        // 초기화
        for (int i = 0; i < isSqaure.size(); i++)
            fill(isSqaure[i].begin(), isSqaure[i].end(), false);
        canRemove = false;

        // 2x2 정사각형 찾아 기록
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || board[i][j] == '0')
                    continue;
                if (board[i - 1][j - 1] == board[i][j - 1]
                    && board[i - 1][j - 1] == board[i - 1][j]
                    && board[i - 1][j - 1] == board[i][j]) {
                    isSqaure[i][j] = true;
                    isSqaure[i - 1][j] = true;
                    isSqaure[i][j - 1] = true;
                    isSqaure[i - 1][j - 1] = true;
                    canRemove = true;
                }
            }
        }

        // 2x2 정사각형 다 없애기
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isSqaure[i][j] == true) {
                    board[i][j] = '0';
                    answer++;
                }
            }
        }

        // 블록 떨어뜨려 빈공간 채우기 (두 번째 행 부터 시작)
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '0') {
                    for (int k = i; k > 0; k--) {
                        if (board[k - 1][j] == '0')
                            break;
                        board[k][j] = board[k - 1][j];
                        board[k - 1][j] = '0';
                    }
                }
            }
        }
    } while (canRemove);

    return answer;
}