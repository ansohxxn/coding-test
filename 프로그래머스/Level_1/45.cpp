#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, float> a, pair<int, float> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer(N);

    vector<int> all(N);
    vector<int> success(N);
    vector<pair<int, float>> temp(N);

    for (int i = 0; i < stages.size(); i++)
    {
        for (int j = 0; j < stages[i] && j < N; j++)
            all[j]++;
        for (int j = 0; j < stages[i] - 1; j++)
            success[j]++;
    }

    for (int i = 0; i < N; i++)
    {
        float fail = (all[i] == 0? 0 : (all[i] - success[i]) / (float)all[i]);
        temp[i] = make_pair(i + 1, fail);
    }

    sort(temp.begin(), temp.end(), compare);

    for (int i = 0; i < N; i++)
        answer[i] = temp[i].first;

    return answer;
}