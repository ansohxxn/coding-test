#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    vector<pair<int, int>> foods;
    int n = food_times.size();
    for (int i = 0; i < n; ++i)
        foods.push_back(make_pair(food_times[i], i + 1));
    sort(foods.begin(), foods.end());
    int pretime = 0;
    for (vector<pair<int, int>>::iterator it = foods.begin(); it != foods.end(); ++it, --n) {
        long long spend = (long long)(it->first - pretime) * n;
        if (spend == 0) continue;
        if (spend <= k) {
            k -= spend;
            pretime = it->first;
        }
        else {
            k = k % n;
            sort(it, foods.end(), comp);
            return (it + k)->second;
        }
    }
    return -1;
}