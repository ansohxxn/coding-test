#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b) {
    
    /* HEAD */
    string a_HEAD = "";
    int a_index = 0;
    while (a_index < a.length()) {
        if (a[a_index] >= '0' && a[a_index] <= '9')
            break;
        else {
            a_HEAD += tolower(a[a_index]);
            a_index++;
        }
    }
    string b_HEAD = "";
    int b_index = 0;
    while (b_index < b.length()) {
        if (b[b_index] >= '0' && b[b_index] <= '9')
            break;
        else {
            b_HEAD += tolower(b[b_index]);
            b_index++;
        }
    }

    if (a_HEAD != b_HEAD)
        return a_HEAD < b_HEAD;

    /* NUMBER */
    string a_NUMBER = "";
    for (int i = 0; i < 5 && a_index < a.length(); i++) {
        if (a[a_index] >= '0' && a[a_index] <= '9') {
            a_NUMBER += a[a_index];
            a_index++;
        }
        else break;
    }
    string b_NUMBER = "";
    for (int i = 0; i < 5 && b_index < b.length(); i++) {
        if (b[b_index] >= '0' && b[b_index] <= '9') {
            b_NUMBER += b[b_index];
            b_index++;
        }
        else break;
    }
    int a_num = stoi(a_NUMBER);
    int b_num = stoi(b_NUMBER);
    if (a_num != b_num)
        return a_num < b_num;
}

vector<string> solution(vector<string> files) {
    vector<string> answer = files;
    stable_sort(answer.begin(), answer.end(), cmp);
    return answer;
}