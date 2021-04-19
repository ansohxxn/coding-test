#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Trie {
private:
    int count;
    unordered_map<char, Trie*> child;
public:
    Trie() : count(0) {}

    void Insert(string str) {
        Trie* now = this;
        for (int i = 0; i < str.length(); ++i) {
            if (now->child[str[i]] == nullptr)
                now->child[str[i]] = new Trie;
            now = now->child[str[i]];
            now->count++;
        }
    }

    int AutoComplete(string str) {
        int numOfInput = 1;
        Trie* now = child[str[0]];
        for (int i = 1; i < str.length(); ++i) {
            if (now->count > 1)
                numOfInput++;
            now = now->child[str[i]];
        }
        return numOfInput;
    }
};

int solution(vector<string> words) {
    int answer = 0;
    Trie root;

    for (string word : words)
        root.Insert(word);

    for (string word : words)
        answer += root.AutoComplete(word);

    return answer;
}