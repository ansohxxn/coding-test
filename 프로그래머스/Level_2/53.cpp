#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<vector<string>> info(musicinfos.size());
    vector<pair<string, int>> included;

    // tokenizing with ','
    for (int i = 0; i < musicinfos.size(); i++) {
        string temp = "";
        for (int j = 0; j < musicinfos[i].length(); j++) {
            if (musicinfos[i][j] == ',') {
                info[i].push_back(temp);
                temp = "";
            }
            else
                temp += musicinfos[i][j];
        }
        info[i].push_back(temp);
    }

    // A# C# D# F# G# 는 각각 a,c,d,f,g 로 변경
    for (int i = 0; i < m.length(); ) {
        if (m[i] == '#') {
            m[i - 1] = tolower(m[i - 1]);
            m.erase(m.begin() + i);
        }
        else
            i++;
    }
    for (int i = 0; i < info.size(); i++) {
        for (int j = 0; j < info[i][3].length(); ) {
            if (info[i][3][j] == '#') {
                info[i][3][j - 1] = tolower(info[i][3][j - 1]);
                info[i][3].erase(info[i][3].begin() + j);
            }
            else
                j++;
        }
    }

    for (int i = 0; i < info.size(); i++) {
        // 시간(분) 구하기 
        int hours = stoi(info[i][1].substr(0, 2)) - stoi(info[i][0].substr(0, 2));
        int minutes = stoi(info[i][1].substr(3, 2)) - stoi(info[i][0].substr(3, 2));
        int time = 60 * hours + minutes;

        // 원곡의 음 중 라디오에서 실제 재생된 음
        int n = info[i][3].length();
        if (time > n) {
            string temp = "";
            for (int count = 0; count < time; count++)
                temp += info[i][3][count % n];
            info[i][3] = temp;
        }
        else if (time < n)
            info[i][3] = info[i][3].substr(0, time);

        // 기억하는 음을 포함하는지 여부
        n = info[i][3].length();
        if (m.length() > n)
            continue;
        if (info[i][3].find(m) != string::npos)
            included.push_back(make_pair(info[i][2], time));
    }

    if (included.empty())
        return "(None)";
    
    sort(included.begin(), included.end(), cmp);
    answer = included[0].first;
    return answer;
}