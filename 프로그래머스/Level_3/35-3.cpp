#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 999999
#define DOWN 0
#define RIGHT 1
#define UP 2
#define LEFT 3

int deltaY[4] = { 1, 0, -1, 0 };
int deltaX[4] = { 0, 1, 0, -1 };
int n = 0;
int minDest = INF; // 현재까지 찾은 출발지->목적지 까지의 최~~~소의 비용
int cost_4Dir[25][25][4];

void DFS(vector<vector<int>>& board, int y, int x, int curCost, int dir) {
    // 현재 방문 정점 (y, x) 에 방향은 dir, 그리고 현재까지의 비용은 curCost

    /* 시간 효율성 높이는 기능! */
    // return 조건 1 (더 이상 이 경로는 검사 X ) : 현재까지 찾은 최소값보다 더 커질 때! 더 이상 검사할 필요가 없음
    if (minDest < curCost)
        return;
    // return 조건 2 (더 이상 이 경로는 검사 X ) : 목적지에 도착했을 떄
    if (y == n - 1 && x == n - 1) {
        minDest = min(curCost, minDest);
        return;
    }

    // 4가지 방향 중 다음 방문 후보 검사
    for (int i = 0; i < 4; ++i) {
        int nextY = y + deltaY[i];
        int nextX = x + deltaX[i];

        if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n || board[nextY][nextX] == 1)
            continue;

        int nextCost = curCost + 100;
        if (dir == UP || dir == DOWN)
            if (i == LEFT || i == RIGHT)
                nextCost += 500;
        if (dir == LEFT || dir == RIGHT)
            if (i == UP || i == DOWN)
                nextCost += 500;

        if (cost_4Dir[nextY][nextX][i] > nextCost) {
            cost_4Dir[nextY][nextX][i] = nextCost;
            DFS(board, nextY, nextX, nextCost, i);  // 바로 방문하러 ㄱㄱ
        }  
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    n = board.size();

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < 4; ++k)
                cost_4Dir[i][j][k] = INF;

    DFS(board, 0, 0, 0, -1);

    answer = minDest;
    return answer;
}