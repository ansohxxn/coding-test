#include <string>
#include <vector>

using namespace std;

string to_number(string s) {
    if (s == "zero") return "0";
    else if (s == "one") return "1";
    else if (s == "two") return "2";
    else if (s == "three") return "3";
    else if (s == "four") return "4";
    else if (s == "five") return "5";
    else if (s == "six") return "6";
    else if (s == "seven") return "7";
    else if (s == "eight") return "8";
    else if (s == "nine") return "9";
    else return "";
}

int solution(string s) {

    string answer = "", tmp = "";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') 
            answer += s[i];
        else {
            tmp += s[i];
            if (to_number(tmp) != "") {
                answer += to_number(tmp);
                tmp = "";
            }
        }
    }
    return stoi(answer);
}