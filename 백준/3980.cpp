#include <bits/stdc++.h>

using namespace std;

int answer = 0;
int arr[11][11];
bool visited[11];

void dfs(int player, int sum) {
	
	if (player == 11) {
		answer = max(answer, sum);
		return;
	}

	for (int position = 0; position < 11; ++position) {
		if (arr[player][position] != 0 && !visited[position]) {
			visited[position] = true;
			dfs(player + 1, sum + arr[player][position]);
			visited[position] = false;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int C;
	cin >> C;
	while (C--) {

		for (int i = 0; i < 11; ++i) 
			for (int j = 0; j < 11; ++j) 
				cin >> arr[i][j];
		
		dfs(0, 0);
		cout << answer << '\n';
		answer = 0;
	}
}