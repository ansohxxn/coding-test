#include<vector>
#include<queue>
using namespace std;

struct Pos {
    int x;
    int y;
    Pos(int _y, int _x) { y = _y; x = _x; }
};

int solution(vector<vector<int> > maps)
{
    const int n = maps.size();
    const int m = maps[0].size();
    int deltaY[4] = { -1, 0, 1, 0 };
    int deltaX[4] = { 0, 1, 0, -1 };

    vector<vector<bool>> checked(n, vector<bool>(m));
    vector<vector<int>> dist(n, vector<int>(m));
    queue<Pos> q;

    q.push(Pos(0, 0));
    checked[0][0] = true;
    dist[0][0] = 1;

    while (!q.empty()) {
        Pos pos = q.front();
        q.pop();
        
        int nowY = pos.y;
        int nowX = pos.x;

        for (int i = 0; i < 4; ++i) {
            int nextY = nowY + deltaY[i];
            int nextX = nowX + deltaX[i];

            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
                continue;
            if (maps[nextY][nextX] == 0)
                continue;
            if (checked[nextY][nextX])
                continue;

            q.push(Pos(nextY, nextX));
            checked[nextY][nextX] = true;
            dist[nextY][nextX] = dist[nowY][nowX] + 1;
        }
    }
        
    if (!checked[n - 1][m - 1])
        return -1;
    else
        return dist[n - 1][m - 1];
}