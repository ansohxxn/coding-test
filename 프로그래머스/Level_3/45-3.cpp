#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Pos {
    int r;
    int c;
    int dir;
    int turn_count;
};

struct cmp {
    bool operator () (const Pos& p1, const Pos& p2) const {
        return p1.turn_count > p2.turn_count;
    }
};

#define INF 987654321

vector<string> Board;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int M, N;
map<char, Pos> pos_record;
#define alpha first 
#define pos second 

Pos BFS(Pos start, char start_alpha) {
    priority_queue<Pos, vector<Pos>, cmp> q;
    vector<vector<int>> turn_and_check(M, vector<int>(N, INF));
    start.dir = -1;
    start.turn_count = 0;
    q.push(start);
    turn_and_check[start.r][start.c] = 0;

    bool not_first = false;
    while (!q.empty()) {
        Pos now = q.top();
        q.pop();

        if (not_first && Board[now.r][now.c] == start_alpha)
            return { now.r, now.c };
        not_first = true;

        for (int i = 0; i < 4; ++i) {
            int nextR = now.r + dr[i];
            int nextC = now.c + dc[i];
            int nextDir = i;
            int next_turn_count = now.turn_count;
            if (now.dir != -1 && now.dir != nextDir)
                next_turn_count++;

            if (nextR < 0 || nextR >= M || nextC < 0 || nextC >= N)
                continue;
            if (next_turn_count >= 2)
                continue;
            if (Board[nextR][nextC] != '.' && Board[nextR][nextC] != start_alpha)
                continue;
            if (turn_and_check[nextR][nextC] >= next_turn_count) {
                q.push({ nextR, nextC, nextDir, next_turn_count });
                turn_and_check[nextR][nextC] = next_turn_count;
            }
        }
    }
    return { -1, -1 };
}

string solution(int m, int n, vector<string> board) {
    string answer = "";
    M = m;
    N = n;
    Board = board;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (board[i][j] >= 'A' && board[i][j] <= 'Z')
                pos_record[board[i][j]] = { i, j };

    while (true) {
        bool canRemove = false;
        for (auto& letter : pos_record) {
            char start_alpha = letter.alpha;
            Pos start = letter.pos;
            Pos dest = BFS(start, start_alpha);
            if (dest.r != -1 && dest.c != -1){
                canRemove = true;
                Board[start.r][start.c] = '.';
                Board[dest.r][dest.c] = '.';
                answer += start_alpha;
                pos_record.erase(start_alpha);
                break;
            }
        }

        if (canRemove)
            continue;

        if (pos_record.empty())
            return answer;
        else
            return "IMPOSSIBLE";
    }
}