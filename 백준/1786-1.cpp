#include <bits/stdc++.h>

using namespace std;

vector<int> Fail(string pattern) {
	int m = pattern.length();
	vector<int> pi(m); // partial match table

	int begin = 1;
	int matched = 0;
	pi[0] = 0;
	while (begin + matched < m) {
		if (pattern[begin + matched] == pattern[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

vector<int> KMP(string pattern, string text) {
	int m = pattern.length();
	int n = text.length();
	vector<int> pos;
	vector<int> pi = Fail(pattern);

	int begin = 0;
	int matched = 0;
	while (begin + m <= n) {
		if (matched < m && text[begin + matched] == pattern[matched]) {
			matched++;

			if (matched == m)
				pos.push_back(begin + 1);
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pos;
}

int main() {
	//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	string text;
	getline(cin, text);
	string pattern;
	getline(cin, pattern);

	vector<int> answer = KMP(pattern, text);
	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << ' ';
}
