#include <bits/stdc++.h>

using namespace std;

int N, answer;
int queen[15];

void dfs(int row) {
	if (row == N) {
		++answer;
		return;
	}
	
	for (int col = 0; col < N; ++col) {
		queen[row] = col;
		
		bool promising = true;
		for (int i = 0; i < row; ++i) {
			if (queen[i] == queen[row] || abs(queen[i] - queen[row]) == abs(i - row)) {
				promising = false;
				break;
			}
		}

		if (promising)
			dfs(row + 1);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	
	dfs(0);
	
	cout << answer;
}