#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void DFS(vector<string>& user_id, vector<string>& banned_id, set<string>& selected_list, vector<string> temp, vector<bool> visited, int index)
{
    if (index == banned_id.size()) {
        string s = "";
        sort(temp.begin(), temp.end());
        for (int i = 0; i < temp.size(); i++)
            s += temp[i];
        selected_list.insert(s);
        return;
    }

    for (int i = 0; i < user_id.size(); i++) {
        if (visited[i] == true)
            continue;
        if (banned_id[index].length() != user_id[i].length())
            continue;
        bool flag = true;
        for (int j = 0; j < user_id[i].length(); j++) {
            if (banned_id[index][j] != user_id[i][j]) {
                if (banned_id[index][j] == '*')
                    continue;
                else {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            temp[index] = user_id[i];
            visited[i] = true;
            DFS(user_id, banned_id, selected_list, temp, visited, index + 1);
            visited[i] = false;
        }
    }

    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    set<string> selected_list;
    vector<string> temp(banned_id.size());
    vector<bool> visited(user_id.size());
    DFS(user_id, banned_id, selected_list, temp, visited, 0);
    
    answer = selected_list.size();

    return answer;
}