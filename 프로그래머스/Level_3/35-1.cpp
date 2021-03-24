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

struct Pos { // 정점
    int y, x, cost, dir; // 행, 열, 현재까지의 최소 금액, 바라보고 있는 방향
};

struct cmp {
    bool operator()(const Pos& a, const Pos& b) {
        return a.cost > b.cost;
    }
};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();

    // 상하좌우
    int deltaY[4] = { -1, 1, 0, 0 };
    int deltaX[4] = { 0, 0, -1, 1 };

    // 하나의 y, x 위치에 4 가지 바라보는 방향 저장. 하나의 위치마다 바라보는 방향별 최소 건설비용이 다를 수 있으므로! 
    // 2가지 정보 저장 (위치 + 바라보는 방향)
    int cost[25][25][4]; 
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < 4; ++k)
                cost[i][j][k] = INF; // 최소 비용을 업뎃할 것이므로 최대값으로 초기화
    for (int i = 0; i < 4; ++i)
        cost[0][0][i] = 0;
    
    priority_queue<Pos, vector<Pos>, cmp> pq;
    pq.push({ 0, 0, 0, -1}); // 출발지가 바라보는 방향은 UP DOWN RIGHT LEFT 어디에도 해당하지 않도록 -1 로 넘긴다. 오른쪽, 아래 두 정점 다 코너로 판단되지 않고 100이 될 수 있게.
    //if (board[1][0] == 0) pq.push({ 1, 0, 100, DOWN});
    //if (board[0][1] == 0) pq.push({ 0, 1, 100, RIGHT });

    while (!pq.empty()) {
        // 방문
        Pos now = pq.top();
        pq.pop();

        /* 
        방문 체크 안해줫음 그냥 (다익스트라 굳이 방문체크 안해줘도 답 도출에 지장없다.)
        근데 해주면 for문을 안들어가도 되니까 밑에 코너 계산, 비용 계산 안해도 되니까 성능상 조금은 유리하지 않을까 싶다.
        if (visited[now.y][now.x][now.dir])
            continue;
        */

        // 예약
        for (int i = 0; i < 4; ++i) {

            int nextY = now.y + deltaY[i];
            int nextX = now.x + deltaX[i];
            int nextDir = i;
            int nextCost = now.cost;

            // 범위를 벗어난 곳이라면 예약 불가
            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n || board[nextY][nextX] == 1)
                continue;

            // 비용 계산 (코너가 아니라면 100, 코너라면 600)
            nextCost += 100;
            if (now.dir == UP || now.dir == DOWN) 
                if (nextDir == LEFT || nextDir == RIGHT)
                    nextCost += 500;
            if (now.dir == LEFT || now.dir == RIGHT) 
                if (nextDir == UP || nextDir == DOWN)
                    nextCost += 500;

            // 🤍현재 바라보는 방향에서의 여태 구한 최소비용보다 작으면 예약🤍
            if (nextCost < cost[nextY][nextX][nextDir]) {
                cost[nextY][nextX][nextDir] = nextCost;
                pq.push({ nextY, nextX, nextCost, nextDir });
            }
        }
    }

    // 목적지의 4 가지 방향별 최소비용 중 가장 작은 값을 선택하면 그게 바로 정답
    // cost[n-1][n-1][0], cost[n-1][n-1][1], cost[n-1][n-1][2], cost[n-1][n-1][3] 중 가장 작은 것.
    answer = *min_element(cost[n - 1][n - 1], cost[n - 1][n - 1] + 4);
    return answer;
}