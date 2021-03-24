#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    int n = lines.size();
    vector<int> start(n);
    vector<int> end(n);
    vector<int> perSeconds;

    int hours, minutes, seconds, workTime = 0;
    string s, t;
    for (int i = 0; i < n; ++i) {
        istringstream iss(lines[i].substr(11));
        iss >> s >> t;

        hours = stoi(s.substr(0, 2)) * 1000;
        minutes = stoi(s.substr(3, 2)) * 1000;
        seconds = stoi(s.substr(6, 2)) * 1000 + stoi(s.substr(9, 3));
        t.pop_back();
        workTime += stoi(t.substr(0, 1)) * 1000;
        if (t.length() >= 3)
            workTime += stoi(t.substr(2));

        end[i] = 3600 * hours + 60 * minutes + seconds;
        start[i] = end[i] - workTime + 1;
        workTime = 0;
    }

    int range_start = 0, range_end = 0;
    
    int count = 0;
    for (int i = 0; i < n; ++i) 
        if (start[i] < start[0] + 1000)
            count++;
    perSeconds.push_back(count);

    count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (end[i] <= end[j])
                if (start[j] < end[i] + 1000)
                    count++;
        }
        perSeconds.push_back(count);
        count = 0;
    }

    answer = *max_element(perSeconds.begin(), perSeconds.end());
    return answer;
}