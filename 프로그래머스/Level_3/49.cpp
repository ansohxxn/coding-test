#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, string> parent;
unordered_map<string, int> profit;

void UpdateProfit(string name, int money) {
    if (name == "none") return;

    int notmine = money * 0.1;
    profit[name] += (money - notmine);
    UpdateProfit(parent[name], notmine);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    for (int i = 0; i < enroll.size(); ++i) {
        if (referral[i] == "-") parent[enroll[i]] = "none";
        else parent[enroll[i]] = referral[i];
    }
    for (int i = 0; i < seller.size(); ++i)
        UpdateProfit(seller[i], amount[i] * 100);

    for (int i = 0; i < enroll.size(); ++i)
        answer.push_back(profit[enroll[i]]);
    return answer;
}