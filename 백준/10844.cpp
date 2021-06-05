#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000000

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<vector<int>> digit(N, vector<int>(10, 1));
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j <= 9; ++j) {
			if (j == 0) digit[i][0] = digit[i - 1][1];
			else if (j == 9) digit[i][9] = digit[i - 1][8];
			else digit[i][j] = (digit[i - 1][j - 1] + digit[i - 1][j + 1]) % MOD;
		}
	}
		
	int answer = 0;
	for (int i = 1; i <= 9; ++i)
		answer = (answer + digit[N - 1][i]) % MOD;
	cout << answer % MOD;
}
