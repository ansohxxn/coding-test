#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int& answer, vector<string>& data, string& friends, string perm, vector<bool> checked, int depth) {
    if (depth == friends.length()) {
        bool flag = true;
        for (int i = 0; i < data.size(); ++i) {
            int friend1_idx = 0;
            int friend2_idx = 0;
            for (int j = 0; j < perm.length(); ++j) {
                if (perm[j] == data[i][0])
                    friend1_idx = j;
                if (perm[j] == data[i][2])
                    friend2_idx = j;
            }

            int gap = abs(friend1_idx - friend2_idx) - 1;
            if (data[i][3] == '=') {
                if (gap != data[i][4] - '0') {
                    flag = false;
                    break;
                }
            }
            if (data[i][3] == '>') {
                if (gap <= data[i][4] - '0') {
                    flag = false;
                    break;
                }
            }
            if (data[i][3] == '<') {
                if (gap >= data[i][4] - '0') {
                    flag = false;
                    break;
                }
            }
        }
        if (flag == true) answer++;

        return;
    }

    for (int i = 0; i < friends.length(); ++i) {
        if (checked[i] == false) {
            checked[i] = true;
            perm[depth] = friends[i];
            DFS(answer, data, friends, perm, checked, depth + 1);
            checked[i] = false;
        }
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";
    vector<bool> checked(friends.length(), false);
    string perm;
    perm.resize(friends.length());
    DFS(answer, data, friends, perm, checked, 0);

    return answer;
}