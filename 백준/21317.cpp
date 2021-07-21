#include <bits/stdc++.h>

using namespace std;

int N, K;
int big[20];
int small[20];
int answer = INT_MAX;

void dfs(int stone, bool can_k, int sum) {
	if (stone == N) {
		answer = min(answer, sum);
		return;
	}

	if (can_k && stone + 3 <= N) {
		can_k = false;
		dfs(stone + 3, can_k, sum + K);
		can_k = true;
	}

	if (stone + 1 <= N)
		dfs(stone + 1, can_k, sum + small[stone]);
	if (stone + 2 <= N)
		dfs(stone + 2, can_k, sum + big[stone]);
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N - 1; ++i) {
		cin >> small[i];
		cin >> big[i];
	}
	cin >> K;

	dfs(1, true, 0);
	cout << answer;
}