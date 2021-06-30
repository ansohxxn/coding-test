#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> prefix_sum(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			int num;
			cin >> num;

			if (i == 1 && j == 1) prefix_sum[i][j] = num;
			else if (i == 1) prefix_sum[i][j] = num + prefix_sum[i][j - 1];
			else if (j == 1) prefix_sum[i][j] = num + prefix_sum[i - 1][j];
			else prefix_sum[i][j] = num + prefix_sum[i][j - 1] + prefix_sum[i - 1][j] - prefix_sum[i - 1][j - 1];
		}
	}
		
	int K;
	cin >> K;
	for (int i = 0; i < K; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int answer;
		if (x1 == 1 && y1 == 1) answer = prefix_sum[x2][y2];
		else if (x1 == 1) answer = prefix_sum[x2][y2] - prefix_sum[x2][y1 - 1];
		else if (y1 == 1) answer = prefix_sum[x2][y2] - prefix_sum[x1 - 1][y2];
		else answer = prefix_sum[x2][y2] - prefix_sum[x2][y1 - 1] - prefix_sum[x1 - 1][y2] + prefix_sum[x1 - 1][y1 - 1];

		cout << answer << '\n';
	}
}