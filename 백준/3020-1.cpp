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

	vector<int> cnt_bottom(H);
	vector<int> cnt_top(H);
	for (int i = 0; i < N / 2; ++i) {
		++cnt_bottom[bottom[i]];
		++cnt_top[top[i]];
	}

	vector<int> accum_cnt_bottom(H); accum_cnt_bottom[H - 1] = cnt_bottom[H - 1];
	vector<int> accum_cnt_top(H); accum_cnt_top[H - 1] = cnt_top[H - 1];
	for (int i = H - 2; i >= 1; --i)
		accum_cnt_bottom[i] = cnt_bottom[i] + accum_cnt_bottom[i + 1];
	for (int i = H - 2; i >= 1; --i)
		accum_cnt_top[i] = cnt_top[i] + accum_cnt_top[i + 1];
	
	int min = MAX;
	int min_cnt = 0;
	for (int i = 1; i <= H; ++i) {
		int count = 0;
		if (i == 1) count = accum_cnt_bottom[i];
		else if (i == H) count = accum_cnt_top[H + 1 - i];
		else count = accum_cnt_bottom[i] + accum_cnt_top[H + 1 - i];

		if (count == min)
			++min_cnt;
		else if (count < min) {
			min = count;
			min_cnt = 1;
		}
	}

	cout << min << " " << min_cnt;
}