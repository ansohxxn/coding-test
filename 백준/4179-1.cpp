#include <bits/stdc++.h>

using namespace std;

struct Pos { int x, y, dist; };
struct Data { bool wall, fire, visited; };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int R, C;
    cin >> R >> C;
    vector<vector<Data>> maze(R, vector<Data>(C));
    queue<Pos> fire_q;
    queue<Pos> jihun_q;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            char ch; 
            cin >> ch;
             
            Data data{ false, false, false };
            if (ch == '#')
                data.wall = true;

            if (ch == 'F') {
                data.fire = true;
                fire_q.push({ i, j, 0 });
            }
                
            if (ch == 'J') {
                data.visited = true;
                jihun_q.push({ i, j, 0 });
            }

            maze[i][j] = data;
        }
    }

    int fire_size, jihun_size;
    while (!jihun_q.empty()) {
        
        fire_size = fire_q.size();
        while (fire_size-- > 0) {
            Pos fire_pos = fire_q.front();
            fire_q.pop();

            for (int i = 0; i < 4; ++i) {
                int nextX = fire_pos.x + dx[i];
                int nextY = fire_pos.y + dy[i];

                if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) continue;
                if (maze[nextX][nextY].wall) continue;
                if (maze[nextX][nextY].fire) continue;
                
                fire_q.push({ nextX, nextY });
                maze[nextX][nextY].fire = true;
            }
        }

        jihun_size = jihun_q.size();
        while (jihun_size-- > 0) {
            Pos jihun_pos = jihun_q.front();
            jihun_q.pop();

            for (int i = 0; i < 4; ++i) {
                int nextX = jihun_pos.x + dx[i];
                int nextY = jihun_pos.y + dy[i];

                if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) {
                    cout << jihun_pos.dist + 1;
                    return 0;
                }
                if (maze[nextX][nextY].wall) continue;
                if (maze[nextX][nextY].fire) continue;
                if (maze[nextX][nextY].visited) continue;

                jihun_q.push({ nextX, nextY, jihun_pos.dist + 1 });
                maze[nextX][nextY].visited = true;
            }
        }
    }

    cout << "IMPOSSIBLE";
}