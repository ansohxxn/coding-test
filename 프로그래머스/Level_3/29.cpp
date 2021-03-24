#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long perm(int n)
{
    if (n == 0) return 1;
    return n * perm(n - 1);
}

void func(vector<int>& v, vector<int>& answer, long long& k)
{
    if (v.size() == 1) {
        answer.push_back(v[0]);
        return;
    }

    long long p = perm(v.size() - 1);
    for (int i = 1; i <= v.size(); ++i) {
        if (i * p >= k) {
            answer.push_back(v[i - 1]);
            v.erase(v.begin() + i - 1);
            k = k - (i - 1) * p;
            func(v, answer, k);
        }
    }
}

vector<int> solution(int n, long long k)
{
    vector<int> answer;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        v[i] = i + 1;

    func(v, answer, k);

    return answer;
}