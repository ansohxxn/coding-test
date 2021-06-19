#include <bits/stdc++.h>

using namespace std;

struct Pos { int x, y, dist; };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int W, H;
        cin >> W >> H;

        vector<vector<char>> maze(H, vector<char>(W));
        vector<vector<int>> fire_dist(H, vector<int>(W, -1));
        vector<vector<int>> jihun_dist(H, vector<int>(W, -1));
        queue<Pos> fire_q;
        queue<Pos> jihun_q;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> maze[i][j];

                if (maze[i][j] == '*') {
                    fire_q.push({ i, j });
                    fire_dist[i][j] = 0;
                }

                if (maze[i][j] == '@') {
                    jihun_q.push({ i, j });
                    jihun_dist[i][j] = 0;
                }
            }
        }

        while (!fire_q.empty()) {
            Pos now = fire_q.front();
            fire_q.pop();

            for (int i = 0; i < 4; ++i) {
                int nextX = now.x + dx[i];
                int nextY = now.y + dy[i];
                int nextDist = fire_dist[now.x][now.y] + 1;

                if (nextX < 0 || nextX >= H || nextY < 0 || nextY >= W) continue;
                if (maze[nextX][nextY] == '#') continue;
                if (fire_dist[nextX][nextY] >= 0) continue;

                fire_q.push({ nextX, nextY });
                fire_dist[nextX][nextY] = nextDist;
            }
        }

        bool escape = false;
        while (!jihun_q.empty() && !escape) {
            Pos now = jihun_q.front();
            jihun_q.pop();

            for (int i = 0; i < 4; ++i) {
                int nextX = now.x + dx[i];
                int nextY = now.y + dy[i];
                int nextDist = jihun_dist[now.x][now.y] + 1;

                if (nextX < 0 || nextX >= H || nextY < 0 || nextY >= W) {
                    cout << jihun_dist[now.x][now.y] + 1 << '\n';
                    escape = true;
                    break;
                }
                if (maze[nextX][nextY] == '#') continue;
                if (jihun_dist[nextX][nextY] >= 0) continue;
                if (fire_dist[nextX][nextY] != -1 && nextDist >= fire_dist[nextX][nextY]) continue;

                jihun_q.push({ nextX, nextY });
                jihun_dist[nextX][nextY] = nextDist;
            }
        }

        if(!escape) cout << "IMPOSSIBLE" << '\n';
    }
}