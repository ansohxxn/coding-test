#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> room;
long long GetNextRoom(long long n)
{
    if (room[n] == 0) return n;
    return room[n] = GetNextRoom(room[n]);
}
vector<long long> solution(long long k, vector<long long> room_number){
    vector<long long> answer;

    for (auto num : room_number){
        if (room[num] == 0){
            answer.push_back(num);
            room[num] = GetNextRoom(num + 1);
        }
        else{
            long long next_num = GetNextRoom(num);
            answer.push_back(next_num);
            room[next_num] = GetNextRoom(next_num + 1);
        }
    }
    return answer;
}