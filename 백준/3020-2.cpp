#include <bits/stdc++.h>

using namespace std;

#define MAX 200000
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, H;
	cin >> N;
	cin >> H;
	vector<int> bottom(N / 2);
	vector<int> top(N / 2);
	for (int i = 0; i < N / 2; ++i) {
		cin >> bottom[i];
		cin >> top[i];
	}

	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());
	
	int min = MAX;
	int min_cnt = 0;
	for (int i = 1; i <= H; ++i) {
		int count = 0;
		count += N / 2 - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
		count += N / 2 - (upper_bound(top.begin(), top.end(), H - i) - top.begin());

		if (count == min)
			++min_cnt;
		else if (count < min) {
			min = count;
			min_cnt = 1;
		}
	}

	cout << min << " " << min_cnt;
}
