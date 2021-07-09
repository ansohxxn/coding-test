#include <string>
#include <vector>

using namespace std;

int di[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };
int dj[8] = { 0, 0, -1, 1, -1, -1, 1, 1 };

bool is_social_distancing(vector<string> place) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (place[i][j] != 'P')
                continue;

            for (int dir = 0; dir < 4; ++dir) {
                int other_cand_i = i + di[dir];
                int other_cand_j = j + dj[dir];

                if (other_cand_i < 0 || other_cand_i >= 5 || other_cand_j < 0 || other_cand_j >= 5) continue;
                if (place[other_cand_i][other_cand_j] != 'P') continue;

                return false;
            }

            for (int dir = 0; dir < 4; ++dir) {
                int other_cand_i = i + 2 * di[dir];
                int other_cand_j = j + 2 * dj[dir];

                int partition_i = i + di[dir];
                int partition_j = j + dj[dir];

                if (other_cand_i < 0 || other_cand_i >= 5 || other_cand_j < 0 || other_cand_j >= 5) continue;
                if (place[other_cand_i][other_cand_j] != 'P') continue;
                if (place[partition_i][partition_j] == 'X') continue;

                return false;
            }

            for (int dir = 4; dir < 8; ++dir) {
                int other_cand_i = i + di[dir];
                int other_cand_j = j + dj[dir];

                int partition_1_i = i + di[dir];
                int partition_1_j = j;

                int partition_2_i = i;
                int partition_2_j = j + dj[dir];

                if (other_cand_i < 0 || other_cand_i >= 5 || other_cand_j < 0 || other_cand_j >= 5) continue;
                if (place[other_cand_i][other_cand_j] != 'P') continue;
                if (place[partition_1_i][partition_1_j] == 'X' && place[partition_2_i][partition_2_j] == 'X') continue;

                return false;
            }
        }
    }

    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer; 
    for (int n = 0; n < 5; ++n) {
        if (is_social_distancing(places[n]))
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    return answer;
}