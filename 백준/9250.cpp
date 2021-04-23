#include <bits/stdc++.h>

using namespace std;

struct Trie {
public:
	bool isEnd;
	map<char, Trie*> child;
	Trie* fail;

	Trie() : isEnd(false), fail(nullptr) {}

	void Insert(string pattern) {
		Trie* now = this;
		int m = pattern.length();
		for (int i = 0; i < m; ++i) {
			if (now->child.find(pattern[i]) == now->child.end())
				now->child[pattern[i]] = new Trie;
			now = now->child[pattern[i]];

			if (i == m - 1) now->isEnd = true;
		}
	}

	void Fail() {  // BFS + KMP
		Trie* root = this;
		queue<Trie*> q;

		q.push(root);

		while (!q.empty()) {
			Trie* now = q.front();
			q.pop();

			for (auto& ch : now->child) {

				Trie* next = ch.second;
				if (now == root)
					next->fail = root;
				else {
					Trie* prev = now->fail;
					while (prev != root && prev->child.find(ch.first) == prev->child.end())
						prev = prev->fail;
					if (prev->child.find(ch.first) != prev->child.end())
						prev = prev->child[ch.first];
					next->fail = prev;
				}

				if (next->fail->isEnd)
					next->isEnd = true;

				q.push(next);
			}
		}
	}
};

bool KMP(string word, Trie* root) {
	Trie* now = root;
	int n = word.length();
	for (int i = 0; i < n; ++i) {
		while (now != root && now->child.find(word[i]) == now->child.end())
			now = now->fail;
		if (now->child.find(word[i]) != now->child.end())
			now = now->child[word[i]];
		if (now->isEnd)
			return true;
	}
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);

	int N;
	cin >> N;
	vector<string> patterns(N);
	for (int i = 0; i < N; ++i)
		cin >> patterns[i];
	Trie* root = new Trie;
	for (int i = 0; i < N; ++i)
		root->Insert(patterns[i]);
	root->Fail();

	int Q;
	cin >> Q;
	vector<string> words(Q);
	for (int i = 0; i < Q; ++i)
		cin >> words[i];
	for (int i = 0; i < Q; ++i) {
		if (KMP(words[i], root))
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}
