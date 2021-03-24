#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 문자열 시간을 초 단위의 int 정수로 변환
int ToInt(string log) {
    int hours = stoi(log.substr(0, 2));
    int minutes = stoi(log.substr(3, 2));
    int seconds = stoi(log.substr(6, 2));
    return 3600 * hours + 60 * minutes + seconds;
}

// 초 단위의 int 정수를 문자열 시간으로 변환
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
    int playTotalTime = ToInt(play_time); // 동영상 전체 시간 (초 단위 정수)
    int advTotalTime = ToInt(adv_time); // 광고 재생 시간 (초 단위 정수)
    vector<long long> views(playTotalTime + 1); // 인덱스를 "초"에 대응시킴

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
    
    // 3️⃣ 초 당 시청수 누적합 (= 2️⃣초 당 시청수 누적 합산)
    for (int time = 1; time <= playTotalTime; ++time)
        views[time] += views[time - 1];

    // 4️⃣ 광고 시작 시간 당 시청수 누적합
    long long sumViews = views[advTotalTime - 1]; 
    long long maxViews = sumViews; 
    int answerTime = 0; 
    for (int time = 1; time <= playTotalTime - advTotalTime; ++time) { 
        sumViews = views[time + advTotalTime - 1] - views[time - 1]; 
        if (maxViews < sumViews) {
            maxViews = sumViews;  
            answerTime = time;  
        }
    }

    answer = ToStr(answerTime); 
    return answer;
}