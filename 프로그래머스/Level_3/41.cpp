#include <string>
#include <vector>

using namespace std;

struct Data {
    string my_url;
    vector<string> link;
    string text;
};

struct Score {
    int basic;
    int outer_link;
    double link;
    double matching;
};

int solution(string word, vector<string> pages) {
    int answer = 0;
    vector<Data> data(pages.size());
    vector<Score> scores(pages.size());

    for (int i = 0; i < word.length(); ++i)
        word[i] = tolower(word[i]); // 대소문자 구분하지 않으니 word 도 모두 소문자로 변환

    /* 이 페이지의 링크 저장 */
    const string mlink1 = "<meta property=\"og:url\" content=\"https://";
    const string mlink2 = "\"";
    for (int i = 0; i < pages.size(); ++i) {
        int start = pages[i].find(mlink1);
        int end = pages[i].find(mlink2, start + mlink1.length());
        int len = end - (start + mlink1.length());
        data[i].my_url = pages[i].substr(start + mlink1.length(), len);
    }

    /* 이 페이지의 외부 링크들 저장 */
    const string olink1 = "<a href=\"https://";
    const string olink2 = "\">";
    for (int i = 0; i < pages.size(); ++i) {
        int start = 0;
        int end = 0;
        while (true) {
            start = pages[i].find(olink1, end + olink2.length());
            if (start == string::npos) break;
            end = pages[i].find(olink2, start + olink1.length());
            int len = end - (start + olink1.length());
            data[i].link.push_back(pages[i].substr(start + olink1.length(), len));
        }
    }

    /* 이 페이지의 텍스트들 저장 */
    const string body_start = "<body>";
    const string body_end = "</body>";
    for (int i = 0; i < pages.size(); ++i) {
        int start = pages[i].find(body_start);
        int end = pages[i].find(body_end);
        int len = end - (start + body_start.length());
        string body = pages[i].substr(start + body_start.length(), len);
        
        bool aTag = false;
        string str = "";
        for (int j = 0; j < body.length(); ++j) {
            if (body[j] == '<') {
                aTag = true;
                continue;
            }
            if (body[j] == '>') {
                aTag = false;
                continue;
            }
            if (aTag == false)
                str += body[j];
        }

        data[i].text = str;
    }

    /* 1. 기본 점수 구하기 */
    for (int i = 0; i < data.size(); ++i) {

        // 대문자는 소문자로 바꾸고 알파벳이 아닌 문자는 모두 공백으로 
        for (int j = 0; j < data[i].text.length(); ++j) {
            if (data[i].text[j] >= 'A' && data[i].text[j] <= 'Z')
                data[i].text[j] = tolower(data[i].text[j]);
            if (data[i].text[j] >= 'a' && data[i].text[j] <= 'z')
                continue;
            data[i].text[j] = ' ';
        }

        // 공백을 기준으로, 즉 단어 단위로 파싱하여 벡터에 저장
        vector<string> v_temp;
        string temp = "";
        for (int j = 0; j < data[i].text.length(); ++j) {
            if (data[i].text[j] == ' ') {
                v_temp.push_back(temp);
                temp = "";
                continue;
            }
            temp += data[i].text[j];
        }
        v_temp.push_back(temp);

        // 기본점수 카운팅
        scores[i].basic = 0.0;
        for (int j = 0; j < v_temp.size(); ++j)
            if (v_temp[j] == word)
                scores[i].basic++;
    }

    /* 2. 외부 링크 수 구하기 */ 
    for (int i = 0; i < data.size(); ++i) 
        scores[i].outer_link = data[i].link.size();
    
    /* 3. 링크 점수 구하기 */
    for (int i = 0; i < data.size(); ++i) {
        scores[i].link = 0.0;
        for (int j = 0; j < data.size(); ++j) {
            for (int k = 0; k < data[j].link.size(); ++k) {
                if (data[i].my_url == data[j].link[k])
                    scores[i].link += (double)scores[j].basic / scores[j].outer_link;
            }
        }
    }

    /* 4. 매칭 점수 구하기 (+ 최대 매칭 점수)*/
    double max = 0.0;
    for (int i = 0; i < data.size(); ++i) {
        scores[i].matching = scores[i].basic + scores[i].link;
        if (max < scores[i].matching) {
            max = scores[i].matching;
            answer = i;
        }
    }
    
    return answer;
}