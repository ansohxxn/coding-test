#include <string>
#include <vector>
#include <queue>

using namespace std;
#define INF 987654321

struct Pos {
    int row;
    int col;
};

vector<vector<int>> Board;
int D[4][2] = { { -1, 0 }, {1, 0}, {0, -1}, {0, 1} }; // 상,하,좌,우

int bfs(Pos start_card, Pos dest_card) {
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
                if (Board[next_row][next_col] != 0) break;  // 다른 카드 만났다면
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

int permutate(Pos start_card) {
    int ret = INF;
    for (int num = 1; num <= 6; ++num) { // 카드는 1~6 있을 수 있다. 카드 넘버별 저장
        vector<Pos> card; // 넘버별 같은 카드들 저장할 곳, 크기 2
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (Board[i][j] == num)
                    card.push_back({ i, j });

        if (card.empty()) continue; // num이 이미 제거된 카드 or 혹은 없는 카드

        // 같은 카드를 순회하는 2가지 방법
        int one = bfs(start_card, card[0]) + bfs(card[0], card[1]) + 2; // a1 -> a2
        int two = bfs(start_card, card[1]) + bfs(card[1], card[0]) + 2; // a2 -> a1

        // 카드 제거
        for (int i = 0; i < 2; ++i)
            Board[card[i].row][card[i].col] = 0;

        // 가장 작은게 ret 에 담기게 된다. (최대 12번 비교)
        ret = min(ret, one + permutate(card[1])); // a1 -> a2 을 끝낸 후 이제 다른 카드 순회
        ret = min(ret, two + permutate(card[0])); // a2 -> a1 을 끝낸 후 이제 다른 카드 순회

        // 돌아와서 복원 (다음 num 선택을 위하여)
        for (int i = 0; i < 2; ++i)
            Board[card[i].row][card[i].col] = num;
    }

    if (ret == INF) // 이 재귀 호출에서 ret 가 INF 일 때는 모든 카드가 제거됐을 때! 모든 카드가 제거된 상태일 때는 재귀 호출 종료
        return 0;

    return ret;
}

int solution(vector<vector<int>> board, int r, int c) {
    Board = board;
    int answer = permutate({ r, c });
    return answer;
}