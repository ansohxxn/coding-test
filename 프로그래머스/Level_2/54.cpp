#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dic;
    for(int i = 0; i < 26; i++){
        char c = 'A' + i;
        dic[string(1, c)] = i + 1;
    }
    
    string str = "";
    int number = 27;
    for(int i = 0; i < msg.length(); ){
        str += msg[i];
        if (dic.find(str) == dic.end()){
            dic[str] = number++;
            str.pop_back();
            answer.push_back(dic[str]);
            str = "";
        }
        else i++;
    }
    answer.push_back(dic[str]);
    
    return answer;
}