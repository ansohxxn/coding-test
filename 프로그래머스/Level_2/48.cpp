#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string strLower(string str) {
    for (int i = 0; i < str.length(); ++i)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = tolower(str[i]);

    return str;
}

vector<string> makeSet(string str) {
    vector<string> str_set;

    for (int i = 0; i < str.length() - 1; ) {
        string temp = str.substr(i, 2);
        if (temp[0] >= 'a' && temp[0] <= 'z') {
            if (temp[1] >= 'a' && temp[1] <= 'z') {
                str_set.push_back(temp);
                i++;
            }
            else i += 2;
        }
        else {
            if (temp[1] >= 'a' && temp[1] <= 'z') i++;
            else i += 2;
        }
    }
    return str_set;
}

int solution(string str1, string str2) {
    int answer = 0;
    int intersec = 0;   // (교집합의 원소 수)
    int uni = 0;        // (합집합의 원소 수)
    vector<string> str1_set;
    vector<string> str2_set;
    unordered_map<string, int> count;

    // 소문자로 변환
    str1 = strLower(str1);
    str2 = strLower(str2);

    // 다중 집합 만들기 (오직 영문자로 된 쌍만 반영)
    str1_set = makeSet(str1);
    str2_set = makeSet(str2);
    
    // 교집합 개수 구하는 과정
    for(int i = 0; i < str1_set.size(); i++)
        count[str1_set[i]]++;
    for(int i = 0; i < str2_set.size(); i++){
        if (count.find(str2_set[i]) != count.end()){
            if (count[str2_set[i]] == 0)
                continue;
            count[str2_set[i]]--;
            intersec++;
        }
    }
    
    // 합집합 개수 구하기
    uni = str1_set.size() + str2_set.size() - intersec;
    
    // 자카드 유사도 구하기
    if (uni == 0) answer = 65536;
    else answer = (int)((float)intersec / uni * 65536);

    return answer;
}