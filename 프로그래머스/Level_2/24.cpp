#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    unordered_map<string, vector<int>> db;
    for (int i = 0; i < info.size(); ++i) {
        vector<string> applicant;
        string temp = "";
        for (int j = 0; j < info[i].length(); ++j) {
            if (info[i][j] == ' ') {
                applicant.push_back(temp);
                temp = "";
            }
            else
                temp += info[i][j];
        }
        applicant.push_back(temp);
        
        db[applicant[0] + applicant[1] + applicant[2] + applicant[3]].push_back(stoi(applicant[4]));

        for (int r = 1; r <= 4; ++r) {
            vector<bool> comb(4, false);
            for (int j = 0; j < r; ++j)
                comb[j] = true;
            do {
                string temp = "";
                for (int k = 0; k < 4; ++k) {
                    if (comb[k]) temp += '-';
                    else temp += applicant[k];
                }
                db[temp].push_back(stoi(applicant[4]));
            } while (prev_permutation(comb.begin(), comb.end()));
        }
    }
    
    for(auto& d : db)
        sort(d.second.begin(), d.second.end());

    for (int i = 0; i < query.size(); i++) {
        vector<string> condition;
        string temp = "";
        for (int j = 0; j < query[i].length(); ++j) {
            if (query[i][j] == ' ') {
                if (temp != "and")
                    condition.push_back(temp);
                temp = "";
            }
            else
                temp += query[i][j];
        }
        condition.push_back(temp);

        vector<int> score;
        score = db[condition[0] + condition[1] + condition[2] + condition[3]];
        vector<int>::iterator itr = lower_bound(score.begin(), score.end(), stoi(condition[4]));
        answer.push_back(score.end() - itr);
    }

    return answer;
}