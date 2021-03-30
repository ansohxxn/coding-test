#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Pos {
    int r;
    int c;
};

string solution(int m, int n, vector<string> board) {
    string answer = "";
    vector<vector<Pos>> pos_record(26);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == '*' || board[i][j] == '.')
                continue;
            pos_record[board[i][j] - 'A'].push_back({ i, j });
        }
    }  

    vector<char> v;
    int v_index = -1;
    while (true) {
        set<char> remove;
        for (int k = 0; k < 26; ++k) {
            if (pos_record[k].empty()) continue;
            bool OK = true;
            
            // 경로 0 번 꺾기 (같은 행 and 열 사이 중간에 장애물 있는지 검사)
            if (pos_record[k][0].r == pos_record[k][1].r) {
                OK = true;
                int i = pos_record[k][0].r;
                for (int j = pos_record[k][0].c + 1; j < pos_record[k][1].c; ++j) {
                    if (board[i][j] == '*') { OK = false; break; }
                    if (board[i][j] >= 'A' && board[i][j] <= 'Z') { OK = false; break; }
                }
                if (OK) {
                    remove.insert(k + 'A');
                    continue;
                }
            }

            // 경로 0 번 꺾기 (같은 열 and 행 사이 중간에 장애물 있는지 검사)
            if (pos_record[k][0].c == pos_record[k][1].c) {
                OK = true;
                int j = pos_record[k][0].c;
                for (int i = pos_record[k][0].r + 1; i < pos_record[k][1].r; ++i) {
                    if (board[i][j] == '*') { OK = false; break; }
                    if (board[i][j] >= 'A' && board[i][j] <= 'Z') { OK = false; break; }
                }
                if (OK) {
                    remove.insert(k + 'A');
                    continue;
                }
            }

            // 경로 1 번 꺾기 
            if (pos_record[k][0].c < pos_record[k][1].c) {  // ㄴ, ㄱ
                // ㄴ
                OK = true;
                int point_r = pos_record[k][1].r;
                int point_c = pos_record[k][0].c;
                
                for (int i = pos_record[k][0].r + 1; i <= point_r; ++i) {
                    if (board[i][point_c] == '*') { OK = false; break; }
                    if (board[i][point_c] >= 'A' && board[i][point_c] <= 'Z') { OK = false; break; }
                }
                for (int j = point_c; j < pos_record[k][1].c; ++j) {
                    if (board[point_r][j] == '*') { OK = false; break; }
                    if (board[point_r][j] >= 'A' && board[point_r][j] <= 'Z') { OK = false; break; }
                }
                if (OK) {
                    remove.insert(k + 'A');
                    continue;
                }

                // ㄱ
                OK = true;
                point_r = pos_record[k][0].r;
                point_c = pos_record[k][1].c;
                for (int j = pos_record[k][0].c + 1; j <= point_c; ++j) {
                    if (board[point_r][j] == '*') { OK = false; break; }
                    if (board[point_r][j] >= 'A' && board[point_r][j] <= 'Z') { OK = false; break; }
                }
                for (int i = point_r; i < pos_record[k][1].r; ++i) {
                    if (board[i][point_c] == '*') { OK = false; break; }
                    if (board[i][point_c] >= 'A' && board[i][point_c] <= 'Z') { OK = false; break; }
                }
                if (OK) {
                    remove.insert(k + 'A');
                    continue;
                }
            }
            if (pos_record[k][0].c > pos_record[k][1].c) { // ┌ ┘
                // ┘
                OK = true;
                int point_r = pos_record[k][1].r;
                int point_c = pos_record[k][0].c;
                for (int i = pos_record[k][0].r + 1; i <= point_r; ++i) {
                    if (board[i][point_c] == '*') { OK = false; break; }
                    if (board[i][point_c] >= 'A' && board[i][point_c] <= 'Z') { OK = false; break; }
                }
                for (int j = pos_record[k][1].c + 1; j <= point_c; ++j) {
                    if (board[point_r][j] == '*') { OK = false; break; }
                    if (board[point_r][j] >= 'A' && board[point_r][j] <= 'Z') { OK = false; break; }
                }
                if (OK) {
                    remove.insert(k + 'A');
                    continue;
                }

                // ┌
                OK = true;
                point_r = pos_record[k][0].r;
                point_c = pos_record[k][1].c;
                for (int j = point_c; j < pos_record[k][0].c; ++j) {
                    if (board[point_r][j] == '*') { OK = false; break; }
                    if (board[point_r][j] >= 'A' && board[point_r][j] <= 'Z') { OK = false; break; }
                }
                for (int i = point_r; i < pos_record[k][1].r; ++i) {
                    if (board[i][point_c] == '*') { OK = false; break; }
                    if (board[i][point_c] >= 'A' && board[i][point_c] <= 'Z') { OK = false; break; }
                }
                if (OK) {
                    remove.insert(k + 'A');
                    continue;
                }
            }
        }

        if (remove.empty()) break;

        for (auto& ele : remove) {
            int i = 0;
            if (find(v.begin(), v.end(), ele) != v.end())
                continue;

            for (i = v_index + 1; i < v.size(); ++i) 
                if (ele < v[i])
                    break;
            
            if (v.empty()) v.push_back(ele);
            else v.insert(v.begin() + i, ele);
        }

        v_index++;

        char next_remove_char = v[v_index];
        Pos pos_next_remove_char1{ pos_record[next_remove_char - 'A'][0].r, pos_record[next_remove_char - 'A'][0].c };
        Pos pos_next_remove_char2{ pos_record[next_remove_char - 'A'][1].r, pos_record[next_remove_char - 'A'][1].c };
        board[pos_next_remove_char1.r][pos_next_remove_char1.c] = '.';
        board[pos_next_remove_char2.r][pos_next_remove_char2.c] = '.';
        pos_record[next_remove_char - 'A'].clear();
    }

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (board[i][j] >= 'A' && board[i][j] <= 'Z')
                return "IMPOSSIBLE";

    for (int i = 0; i < v.size(); ++i)
        answer += v[i];

    return answer;
}