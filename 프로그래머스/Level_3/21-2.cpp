#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ToInt(string log) {
    int hours = stoi(log.substr(0, 2));
    int minutes = stoi(log.substr(3, 2));
    int seconds = stoi(log.substr(6, 2));
    return 3600 * hours + 60 * minutes + seconds;
}

string ToStr(int log) {
    string hours = to_string(log / 3600);
    if (hours.length() == 1) hours = "0" + hours;
    string minutes = to_string((log % 3600) / 60);
    if (minutes.length() == 1) minutes = "0" + minutes;
    string seconds = to_string((log % 3600) % 60);
    if (seconds.length() == 1) seconds = "0" + seconds;
    return hours + ":" + minutes + ":" + seconds;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int playTotalTime = ToInt(play_time);
    int advTotalTime = ToInt(adv_time);
    vector<long long> views(playTotalTime + 1);

    // 1️⃣ 변화량
    for (auto& log : logs) {
        int startTime = ToInt(log.substr(0, 8));
        views[startTime]++;
        int endTime = ToInt(log.substr(9, 8));
        views[endTime]--;
    }

    // 2️⃣ 초 당 시청수 (= 1️⃣변화량 누적 합산)
    for (int time = 1; time <= playTotalTime; ++time)
        views[time] += views[time - 1];

    // 3️⃣ 광고 시작 시간 당 시청수 누적합
    long long sumViews = 0;
    long long maxViews = 0;
    int answerTime = 0;
    for (int time = 0; time < advTotalTime; ++time) // i = 0 👉 A[0] = V[0] + V[1] +..+ V[광고시간 - 1]
        sumViews += views[time];
    maxViews = sumViews;
    for (int time = 1; time <= playTotalTime - advTotalTime; ++time) { // i != 0 👉 A[i] = A[i - 1] - V[i - 1] + V[i + 광고시간 - 1]
        sumViews = sumViews - views[time - 1] + views[time + advTotalTime - 1]; // Prefix SUm
        if (maxViews < sumViews) {
            maxViews = sumViews;
            answerTime = time;
        }
    }

    answer = ToStr(answerTime);
    return answer;
}