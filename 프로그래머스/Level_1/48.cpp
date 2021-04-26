#include <string>
#include <vector>
#include <set>
using namespace std;

int Rank(int num){
    if(num == 1 || num == 0) return 6;
    else return 7 - num;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    set<int> win_num;
    for(int i = 0; i < 6; ++i)
        win_num.insert(win_nums[i]);

    int illegible = 0;
    int same = 0;
    for(int i = 0; i < 6; ++i){
        if (lottos[i] == 0)
            illegible++;
        else if (win_num.find(lottos[i]) != win_num.end())
            same++;
    }
    
    answer.push_back(Rank(same + illegible));
    answer.push_back(Rank(same));
    return answer;
}