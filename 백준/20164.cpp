#include <bits/stdc++.h>

using namespace std;

int Min = INT_MAX;
int Max = 0;

int check_odd(string s) {
	int cnt = 0;
	for (int i = 0; i < s.length(); ++i)
		if ((s[i] - '0') % 2 == 1)
			++cnt;
	return cnt;
}

void odd_holic(string s, int totalCount) {
	if (s.length() == 1) {
		totalCount += check_odd(s);
		Min = min(Min, totalCount);
		Max = max(Max, totalCount);
		return;
	}
	else if (s.length() == 2) {
		string s1(1, s[0]), s2(1, s[1]);

		string next = to_string((s[0] - '0') + (s[1] - '0'));
		int nowCount = check_odd(s1) + check_odd(s2);
		odd_holic(next, totalCount + nowCount);
	}
	else if (s.length() >= 3) {
		vector<bool> comb(s.length() - 1, false);
		for (int i = 0; i < 2; ++i)
			comb[i] = true;

		do {
			vector<int> boundary;
			for (int i = 0; i < s.length() - 1; ++i) 
				if (comb[i])
					boundary.push_back(i);
			string s1 = s.substr(0, boundary[0] + 1);
			string s2 = s.substr(boundary[0] + 1, boundary[1] - boundary[0]);
			string s3 = s.substr(boundary[1] + 1, s.length() - 1 - boundary[1]);

			string next = to_string(stoi(s1) + stoi(s2) + stoi(s3));
			int nowCount = check_odd(s1) + check_odd(s2) + check_odd(s3);
			odd_holic(next, totalCount + nowCount);

		} while (prev_permutation(comb.begin(), comb.end()));
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string N;
	cin >> N;
	
	odd_holic(N, 0);
	cout << Min << ' ' << Max;
}