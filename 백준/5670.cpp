#include <bits/stdc++.h>

using namespace std;

class Trie {
private:
    bool isEnd;
    unordered_map<char, Trie*> child;
public:
    void Insert(string str) {
        Trie* now = this;
        for (int i = 0; i < str.length(); ++i) {
            if (now->child[str[i]] == nullptr)
                now->child[str[i]] = new Trie();
            now = now->child[str[i]];
            
            if (i == str.length() - 1)
                now->isEnd = true;
        }
    }

    int AutoComplete(string str) {
        int count = 1;
        Trie* now = child[str[0]];
        for (int i = 1; i < str.length(); ++i) {
            if (now->isEnd || now->child.size() > 1)
                count++;
            now = now->child[str[i]];
        }
        return count;
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin >> n) {
        vector<string> words(n);
        for (int i = 0; i < n; ++i)
            cin >> words[i];
        
        Trie* root = new Trie();
        for (int i = 0; i < n; ++i)
            root->Insert(words[i]);

        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += root->AutoComplete(words[i]);
        
        double result = (double)sum / words.size();
        cout << fixed << setprecision(2) << result << '\n';
    }
}