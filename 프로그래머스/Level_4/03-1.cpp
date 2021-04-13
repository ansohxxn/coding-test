#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int n = food_times.size();
    map<int, int> freq;
    set<int> kind;
    for (int i = 0; i < n; ++i) {
        freq[food_times[i]]++;
        kind.insert(food_times[i]);
    }

    long long sum = 0;
    long long temp_n = n;
    long long now, prev = 0;
    for (auto& d : kind) {
        now = d;
        long long temp = (now - prev) * temp_n;
        if (sum + temp > k)
            break;
        sum += temp;
        temp_n -= freq[d];
        prev = now;
    }
    if (temp_n == 0) return -1;
    
    long long offset = k - sum;
    vector<pair<int, int>> notzero;
    for (int i = 0; i < n; ++i)
        if (food_times[i] >= now)
            notzero.push_back({ food_times[i], i + 1 });
    int index = offset % notzero.size();
    answer = notzero[index].second;

    return answer;
}