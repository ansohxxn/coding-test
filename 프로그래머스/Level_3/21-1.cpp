#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define time first
#define deltaView second

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
    vector<pair<int, int>> event; // 
    
    event.push_back({ 0, 0 });
    for (auto& log : logs) {
        int startTime = ToInt(log.substr(0, 8));
        event.push_back({ startTime, 1 });
        int endTime = ToInt(log.substr(9, 8));
        event.push_back({ endTime, -1 });
    }
    sort(event.begin(), event.end());
    
    int startIndex = 0, endIndex = 0;
    long long startViews = 0, endViews = 0;
    long long sumViews = 0, maxViews = 0;
    int advStartTime = 0, answerTime = 0;
    
    while(endIndex + 1 < event.size() && event[endIndex + 1].time <= advTotalTime) {
        int deltaTime = event[endIndex + 1].time - event[endIndex].time;
        sumViews += deltaTime * endViews;
        endViews += event[endIndex + 1].deltaView;
        endIndex++;
    }
    sumViews += (advTotalTime - event[endIndex].time) * endViews;
    maxViews = sumViews;
    
    while (advStartTime <= playTotalTime - advTotalTime && endIndex + 1 < event.size()){
        int startDeltaTime = event[startIndex + 1].time - advStartTime;
        int endDeltaTime = event[endIndex + 1].time - (advStartTime + advTotalTime);
        if (startDeltaTime <= endDeltaTime) {
            sumViews += (endViews - startViews) * startDeltaTime;
            startViews += event[startIndex + 1].deltaView;
            startIndex++;
            advStartTime += startDeltaTime;
        }
        else {
            sumViews += (endViews - startViews) * endDeltaTime;
            endViews += event[endIndex + 1].deltaView;
            endIndex++;
            advStartTime += endDeltaTime;
        }
        
        if (maxViews < sumViews){
            maxViews = sumViews;
            answerTime = advStartTime;
        }
    }
    

    answer = ToStr(answerTime);
    return answer;
}