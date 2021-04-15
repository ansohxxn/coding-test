#include <bits/stdc++.h>

using namespace std;

class Trie {
private :
    bool isEnd = false;
    Trie* child[10];
    
public :
    Trie() : child() { }
    
    void Insert(string phone_number) {
        Trie* now = this;
        for (int i = 0; i < phone_number.length(); ++i) {
            if (now->child[phone_number[i] - '0'] == nullptr)
                now->child[phone_number[i] - '0'] = new Trie();
            now = now->child[phone_number[i] - '0'];
            
            if (i == phone_number.length() - 1) now->isEnd = true;
        }
    }
    
    bool IsTherePrefix(string phone_number) {
        Trie* now = this;
        for (int i = 0; i < phone_number.length(); ++i) {
            if (now->child[phone_number[i] - '0'] != nullptr) {
                now = now->child[phone_number[i] - '0'];
                if (now->isEnd) 
                    return true;
            }
            else if (!now->isEnd) 
                return false;
        }
        return false;
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        cin >> n;
        vector<string> phone_number_list(n);
        for (int j = 0; j < n; ++j)
            cin >> phone_number_list[j];
        sort(phone_number_list.begin(), phone_number_list.end());
        Trie* trie = new Trie();
        bool ok = true;
        for(auto phone_number : phone_number_list) {
            if (trie->IsTherePrefix(phone_number)) {
                ok = false;
                break;
            }
            trie->Insert(phone_number);
        }
        if (ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}