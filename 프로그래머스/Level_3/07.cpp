#include <string>
#include <vector>

using namespace std;

void rotate(int m, vector<pair<int, int>>& pos) {
    for (int i = 0; i < pos.size(); i++) {
        int temp_row = pos[i].first;
        int temp_col = pos[i].second;
        pos[i].first = temp_col;
        pos[i].second = m - 1 - temp_row;
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

    int n = lock.size();
    int m = key.size();

    vector<vector<int>> lockk(2 * m + n - 2, vector<int>(2 * m + n - 2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            lockk[m - 1 + i][m - 1 + j] = lock[i][j];

    vector<pair<int, int>> bumpPos;
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < m; j++) 
            if (key[i][j] == 1) 
                bumpPos.push_back(make_pair(i, j));

    for (int i = 0; i < 4; i++) {
        // 회전
        if (i != 0) {
            for (int j = 0; j < m; j++)
                fill(key[j].begin(), key[j].end(), 0);
            rotate(m, bumpPos);
            for (int j = 0; j < bumpPos.size(); j++)
                key[bumpPos[j].first][bumpPos[j].second] = 1;
        }

        // 좌상단 
        for (int j = 0; j < n + m - 1; j++) {
            for (int k = 0; k < n + m - 1; k++) {
                vector<vector<int>> tempLock(lockk);
                for (int x = 0; x < m; x++){
                    for (int y = 0; y < m; y++) {
                        tempLock[j + x][k + y] += key[x][y];
                    }
                }
                bool flag = true;
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        if (tempLock[m - 1 + i][m - 1 + j] != 1)
                            flag = false;
                if (flag) 
                    return true;
            }
        }
    }

    return false;
}