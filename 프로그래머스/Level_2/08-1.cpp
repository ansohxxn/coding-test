#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2);

    vector<vector<bool>> found(m, vector<bool>(n, false));
    vector<int> colorCount;  // 그래프별로 정점(=타일) 개수 저장

    const int dirX[4] = { 0, -1, 0, 1 };
    const int dirY[4] = { 1, 0, -1, 0 };

    for (int i = 0; i < picture.size(); i++) {
        for (int j = 0; j < picture[i].size(); j++) {
            if (picture[i][j] == 0 || found[i][j] == true) continue;

            // BFS 과정 (while문까지)  : 처음으로 방문 안한 지역을 발견한다면 그건 새로운 그래프(=새로운 색 발견)라는 뜻이다. BFS 순회를 시작해야함.
            int nowRow = i;
            int nowCol = j;
            queue<pair<int, int>> q;
            q.push(make_pair(nowRow, nowCol));
            found[nowRow][nowCol] = true;

            colorCount.push_back(1); // 새로운 그래프 순회를 시작했으니 출발지 1개 추가

            while (q.empty() == false) {
                pair<int, int> pos = q.front();
                nowRow = pos.first;
                nowCol = pos.second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nextRow = nowRow + dirX[k];
                    int nextCol = nowCol + dirY[k];

                    if (nextRow < 0 || nextRow > m - 1 || nextCol < 0 || nextCol > n - 1) // 1. 그림을 벗어난 영역이 아니고
                        continue;
                    if (found[nextRow][nextCol] == true) // 2. 예약된 적이 없고
                        continue;
                    if (picture[nowRow][nowCol] != picture[nextRow][nextCol]) // 3. 색깔이 같다면 ! 이렇게 1,2,3 조건을 모두 만족하면 연결되어 있는 타일이니 추후 방문을 위해 큐에 예약! 
                        continue;

                    q.push(make_pair(nextRow, nextCol));
                    found[nextRow][nextCol] = true;

                    colorCount.back()++; // 지금 순회중인 이 그래프는 colorCount에 최근에 뒤에 추가되었으니 가장 마지막 원소다. 예약했고 곧 방문 예정이니 타일 개수 1 더해줌.
                }
            }
        }
    }

    answer[0] = colorCount.size();
    answer[1] = *max_element(colorCount.begin(), colorCount.end());

    return answer;
}