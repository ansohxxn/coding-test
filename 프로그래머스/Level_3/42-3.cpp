#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 987654321

struct Pos {
    int row;
    int col;
};

int D[4][2] = { { -1, 0 }, {1, 0}, {0, -1}, {0, 1} }; // 상,하,좌,우

int bfs(vector<vector<int>>& board, Pos start_card, Pos dest_card) {
    bool checked[4][4] = { false };
    int dist[4][4] = { 0 };
    queue<Pos> q;

    checked[start_card.row][start_card.col] = true;
    dist[0][0] = 0;
    q.push(start_card);

    while (!q.empty()) {
        Pos now_card = q.front();
        q.pop();

        if (now_card.row == dest_card.row && now_card.col == dest_card.col)
            return dist[dest_card.row][dest_card.col];

        for (int i = 0; i < 4; ++i) {
            int next_row = now_card.row + D[i][0];
            int next_col = now_card.col + D[i][1];

            // 방향키 이동
            if (next_row < 0 || next_row >= 4 || next_col < 0 || next_col >= 4) continue;
            if (!checked[next_row][next_col]) {
                checked[next_row][next_col] = true;
                dist[next_row][next_col] = dist[now_card.row][now_card.col] + 1;
                q.push({ next_row, next_col });
            }

            // Ctrl 이동
            for (int j = 0; j < 2; ++j) {
                if (board[next_row][next_col] != 0) break;  // 다른 카드 만났다면
                if (next_row + D[i][0] < 0 || next_row + D[i][0] >= 4 || next_col + D[i][1] < 0 || next_col + D[i][1] >= 4) break; // 끝에 도달했다면

                next_row += D[i][0];
                next_col += D[i][1];
            }
            if (!checked[next_row][next_col]) {
                checked[next_row][next_col] = true;
                dist[next_row][next_col] = dist[now_card.row][now_card.col] + 1;
                q.push({ next_row, next_col });
            }
        }
    }
    return INF;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = INF;

    vector<vector<Pos>> pos(7);
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (board[i][j] != 0)
                pos[board[i][j]].push_back({ i, j });
    vector<int> card_num;
    for (int i = 1; i <= 6; ++i)
        if (!pos[i].empty())
            card_num.push_back(i);
    int n = card_num.size();

    do {
        vector<vector<int>> board_temp = board;
        vector<vector<int>> dp(n, vector<int>(2));
        
        dp[0][0] = bfs(board_temp, { r, c }, pos[card_num[0]][0]) + bfs(board_temp, pos[card_num[0]][0], pos[card_num[0]][1]) + 2;
        dp[0][1] = bfs(board_temp, { r, c }, pos[card_num[0]][1]) + bfs(board_temp, pos[card_num[0]][1], pos[card_num[0]][0]) + 2;
        
        board_temp[pos[card_num[0]][0].row][pos[card_num[0]][0].col] = 0;
        board_temp[pos[card_num[0]][1].row][pos[card_num[0]][1].col] = 0;
        
        for (int i = 1; i < n; ++i) {
            dp[i][0] = min(dp[i - 1][0] + bfs(board_temp, pos[card_num[i - 1]][1], pos[card_num[i]][0]),
                           dp[i - 1][1] + bfs(board_temp, pos[card_num[i - 1]][0], pos[card_num[i]][0]))
                     + bfs(board_temp, pos[card_num[i]][0], pos[card_num[i]][1]) + 2;
            dp[i][1] = min(dp[i - 1][0] + bfs(board_temp, pos[card_num[i - 1]][1], pos[card_num[i]][1]),
                           dp[i - 1][1] + bfs(board_temp, pos[card_num[i - 1]][0], pos[card_num[i]][1]))
                      + bfs(board_temp, pos[card_num[i]][1], pos[card_num[i]][0]) + 2;
            
            board_temp[pos[card_num[i]][0].row][pos[card_num[i]][0].col] = 0;
            board_temp[pos[card_num[i]][1].row][pos[card_num[i]][1].col] = 0;
        }
        int res = min(dp[n - 1][0], dp[n - 1][1]);
        answer = min (res, answer);
    } while (next_permutation(card_num.begin(), card_num.end()));

    return answer;
}