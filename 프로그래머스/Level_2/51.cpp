#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string splitStr(string str, int number){
    string word = "";
    for(int i = 0; i < str.length(); i++){
        if (str[i] == ' '){
            number--;
            if (number == 0)
                break;
            else
                word = "";
        }
        else
            word += str[i];
    }
    return word;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> info;        // (ID, nickname)
    vector<pair<string, string>> command_vec;  // (ID, command)
    
    for(int i = 0; i < record.size(); i++) {
        string command = splitStr(record[i], 1);
        string id = splitStr(record[i], 2);
        
        if (command != "Change")
            command_vec.push_back(make_pair(id, command));

        if (command != "Leave"){
            string nickName = splitStr(record[i], 3);
            info[id] = nickName;
        }
    }
    
    for(int i = 0; i < command_vec.size(); i++)
    {
        string nickName = info[command_vec[i].first];
        if (command_vec[i].second == "Enter")
            answer.push_back(nickName + "님이 들어왔습니다.");
        else if (command_vec[i].second == "Leave")
            answer.push_back(nickName + "님이 나갔습니다.");
    }
        
    return answer;
}