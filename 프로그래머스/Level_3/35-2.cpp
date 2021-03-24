#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 999999
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

struct Pos {
    int y, x, cost, dir;
};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();

    int deltaY[4] = { -1, 1, 0, 0 };
    int deltaX[4] = { 0, 0, -1, 1 };

    int cost[25][25][4];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < 4; ++k)
                cost[i][j][k] = INF;
    for (int i = 0; i < 4; ++i)
        cost[0][0][i] = 0;
    
    queue<Pos> q;
    q.push({ 0, 0, 0, -1});
    //if (board[1][0] == 0) q.push({ 1, 0, 100, DOWN});
    //if (board[0][1] == 0) q.push({ 0, 1, 100, RIGHT });

    while (!q.empty()) {

        Pos now = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {

            int nextY = now.y + deltaY[i];
            int nextX = now.x + deltaX[i];
            int nextDir = i;
            int nextCost = now.cost;

            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n || board[nextY][nextX] == 1)
                continue;

            nextCost += 100;
            if (now.dir == UP || now.dir == DOWN) 
                if (nextDir == LEFT || nextDir == RIGHT)
                    nextCost += 500;
            if (now.dir == LEFT || now.dir == RIGHT) 
                if (nextDir == UP || nextDir == DOWN)
                    nextCost += 500;

            if (nextCost < cost[nextY][nextX][nextDir]) {
                cost[nextY][nextX][nextDir] = nextCost;
                q.push({ nextY, nextX, nextCost, nextDir });
            }
        }
    }

    answer = *min_element(cost[n - 1][n - 1], cost[n - 1][n - 1] + 4);
    return answer;
}