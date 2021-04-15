#include <bits/stdc++.h>

using namespace std;

class AntDen {
private:
    map<string, AntDen*> child;

public:
    void Insert(vector<string>& foods, int index) {
        if (index == foods.size())
            return;

        if (child.find(foods[index]) == child.end())
            child[foods[index]] = new AntDen();
        child[foods[index]]->Insert(foods, index + 1);
    }

    void Output(int depth) {
        for (auto& ch : child) {
            for (int i = 0; i < depth; ++i)
                cout << "--";
            cout << ch.first << '\n';
            ch.second->Output(depth + 1);
        }
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    AntDen* root = new AntDen();
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        vector<string> foods(k);
        for (int j = 0; j < k; ++j)
            cin >> foods[j];

        root->Insert(foods, 0);
    }

    root->Output(0);
}