#include <bits/stdc++.h>

using namespace std;

int arr[1024][1024];

void recur(int N) {
	if (N == 1) {
		cout << arr[0][0];
		return;
	}

	vector<int> tmp(4);
	for (int i = 0; i < N / 2; ++i) {
		for (int j = 0; j < N / 2; ++j) {
			tmp[0] = arr[2 * i][2 * j];
			tmp[1] = arr[2 * i][2 * j + 1];
			tmp[2] = arr[2 * i + 1][2 * j];
			tmp[3] = arr[2 * i + 1][2 * j + 1];
			sort(tmp.begin(), tmp.end(), greater<>());
			
			arr[i][j] = tmp[1];
		}
	}

	recur(N / 2);
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> arr[i][j];

	recur(N);
}