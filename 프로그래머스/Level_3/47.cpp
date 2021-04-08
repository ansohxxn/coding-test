#include <string>
#include <vector>

using namespace std;

string solution(string sentence) {
    string answer = "";
    const string invalid = "invalid";
    vector<string> words;
    vector<bool> checked(26);
    bool first_rule = false;
    bool second_rule = false;
    char char_rule1 = NULL;
    char char_rule2 = NULL;
    string word = "";
    
    for (int i = 0; i < sentence.length(); ++i) {
        if (first_rule && second_rule) {
            if (isupper(sentence[i])) {
                word += sentence[i];

                if (i + 1 == sentence.length())
                    return invalid;
                else if (isupper(sentence[i + 1]))
                    return invalid;
                else if (char_rule1 != sentence[i + 1] && char_rule2 != sentence[i + 1])
                    return invalid;
            }
            if (islower(sentence[i])) {
                if (char_rule2 == sentence[i]) {
                    first_rule = false;
                    checked[char_rule1 - 'a'] = true;
                    char_rule1 = NULL;

                    second_rule = false;
                    checked[char_rule2 - 'a'] = true;
                    char_rule2 = NULL;

                    words.push_back(word);
                    word = "";

                    continue;
                }
                if (i + 1 == sentence.length())
                    return "invalid";
                else if (islower(sentence[i + 1]))
                    return "invalid";
            }
        }
        else if (first_rule) {
            if (isupper(sentence[i])) {
                word += sentence[i];

                if (i + 1 == sentence.length()) {
                    first_rule = false;
                    checked[char_rule1 - 'a'] = true;
                    char_rule1 = NULL;
                    words.push_back(word);
                    word = "";
                }
                else if (isupper(sentence[i + 1])) {
                    first_rule = false;
                    checked[char_rule1 - 'a'] = true;
                    char_rule1 = NULL;
                    words.push_back(word);
                    word = "";
                }
                else if (char_rule1 != sentence[i + 1]) {
                    first_rule = false;
                    checked[char_rule1 - 'a'] = true;
                    char_rule1 = NULL;
                    words.push_back(word);
                    word = "";
                }
            }
            if (islower(sentence[i])) {
                if (i + 1 == sentence.length())
                    return invalid;
                else if (islower(sentence[i + 1]))
                    return invalid;
            }
        }
        else if (second_rule) {
            if (isupper(sentence[i])) {
                word += sentence[i];

                if (i + 1 == sentence.length())
                    return invalid;
                else if (islower(sentence[i + 1]) && char_rule2 != sentence[i + 1]) {
                    if (char_rule2 == sentence[i - 1]) {
                        if (checked[sentence[i + 1] - 'a'])
                            return invalid;
                        first_rule = true;
                        char_rule1 = sentence[i + 1];
                    }
                    else
                        return invalid;
                }
            }
            if (islower(sentence[i])) {
                second_rule = false;
                checked[char_rule2 - 'a'] = true;
                char_rule2 = NULL;
                words.push_back(word);
                word = "";
            }
        }
        else {
            if (isupper(sentence[i])) {
                word += sentence[i];
                first_rule = true;
       
                if (i + 1 == sentence.length()) {
                    first_rule = false;
                    words.push_back(word);
                    word = "";
                }
                else if (isupper(sentence[i + 1])) {
                    first_rule = false;
                    words.push_back(word);
                    word = "";
                }
                else if (islower(sentence[i + 1])) {
                    if (checked[sentence[i + 1] - 'a'])
                        return invalid;
                    char_rule1 = sentence[i + 1];
                    vector<int> pos;
                    for (int j = i + 1; j < sentence.length(); ++j) 
                        if (sentence[j] == char_rule1)
                            pos.push_back(j);
                    if (pos.size() == 1)
                        continue;
                    else if (pos.size() >= 3) {
                        bool flag = true;
                        for (int j = 1; j < pos.size(); ++j) {
                            if (pos[i + 1] - pos[i] != 2) {
                                flag = false;
                                break;
                            }
                        }
                        if (flag)
                            continue;
                    }
                    else {
                        first_rule = false;
                        words.push_back(word);
                        word = "";
                    }
                }
            }
            if (islower(sentence[i])) {
                if (checked[sentence[i] - 'a'])
                    return invalid;
                if (i + 1 == sentence.length())
                    return invalid;
                else if (islower(sentence[i + 1]))
                    return invalid;
                second_rule = true;
                char_rule2 = sentence[i];
            }
        }
    }

    for (int i = 0; i < words.size(); ++i)
        answer += (words[i] + " ");
    answer.pop_back();
    return answer;
}