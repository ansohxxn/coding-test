#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer (2, 0);
    unordered_set<string> record;
    
    for(int i = 0; i < words.size(); i++)
    {
        if (i % n == 0) answer[1]++;
        
        bool loseCondition1 = words[i].length() == 1;
        bool loseCondition2 = i > 0 && words[i].front() != words[i - 1].back();
        bool loseCondition3 = i > 0 && record.find(words[i]) != record.end();
        
        if (loseCondition1 || loseCondition2 || loseCondition3)
        {
            answer[0] = i % n + 1;
            return answer;
        }
            
        record.insert(words[i]);
    }
    
    answer[1] = 0;
    return answer;
}