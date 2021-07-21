#include <bits/stdc++.h>

using namespace std;

struct Node {
    bool isDeleted = false;
    bool isFirst = false;
    bool isLast = false;
    Node* prev = NULL;
    Node* next = NULL;
};

string solution(int n, int k, vector<string> cmd) {
    vector<Node> li(n);
    Node* now;
    stack<Node*> deleted;

    for (int i = 0; i < n; i++) {
        if (i != 0) 
            li[i].prev = &li[i - 1];
        if (i != n - 1) 
            li[i].next = &li[i + 1];
    }
    li[0].isFirst = true;
    li[n - 1].isLast = true;
    now = &li[k];

    for (int i = 0; i < cmd.size(); ++i) {
        if (cmd[i][0] == 'U') {
            int count = stoi(cmd[i].substr(2));
            while (count--)
                now = now->prev;
        }
        else if (cmd[i][0] == 'D') {
            int count = stoi(cmd[i].substr(2));
            while (count--)
                now = now->next;
        }
        else if (cmd[i][0] == 'C') {
            deleted.push(now);
            now->isDeleted = true;
            if (now->isFirst) {
                now = now->next;
                now->isFirst = true;
            }
            else if (now->isLast) {
                now = now->prev;
                now->isLast = true;
            }
            else {
                now->prev->next = now->next;
                now->next->prev = now->prev;
                now = now->next;
            }
        }
        else if (cmd[i][0] == 'Z') {
            Node* re = deleted.top();
            deleted.pop();
            if (re->isFirst) {
                re->next->prev = re;
                re->next->isFirst = false;
            }
            else if (re->isLast) {
                re->prev->next = re;
                re->prev->isLast = false;
            }
            else {
                re->prev->next = re;
                re->next->prev = re;
            }
            re->isDeleted = false;
        }
    }

    string answer(n, 'O');
    for (int i = 0; i < n; i++) 
        if (li[i].isDeleted)
            answer[i] = 'X';

    return answer;
}