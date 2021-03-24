#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Town {
    int number;
    int shortestTime;

    Town() {}

    Town(int _number, int _shortestTime) {
        number = _number;
        shortestTime = _shortestTime;
    }
};

struct cmp {
    bool operator()(const Town& a, const Town& b) {
        return a.shortestTime > b.shortestTime;
    }
};

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    const int maxTime = 20000000;
    
    vector<bool> visited(N + 1);
    vector<int> time(N + 1, maxTime);
    priority_queue<Town, vector<Town>, cmp> pq;

    time[1] = 0;
    pq.push(Town(1, 0));

    while (!pq.empty()) {
        
        Town startTown = pq.top();
        pq.pop();

        for (int i = 0; i < road.size(); ++i) {
            
            Town nextTown;
            if (road[i][0] == startTown.number)
                nextTown.number = road[i][1];
            else if (road[i][1] == startTown.number)
                nextTown.number = road[i][0];
            else
                continue;

            if (time[nextTown.number] < startTown.shortestTime + road[i][2])
                continue;

            time[nextTown.number] = startTown.shortestTime + road[i][2];
            nextTown.shortestTime = startTown.shortestTime + road[i][2];
            pq.push(nextTown);
        }
    }

    for (int i = 1; i < time.size(); ++i)
        if (time[i] <= K)
            answer++;

    return answer;
}