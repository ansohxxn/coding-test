#include <bits/stdc++.h>

using namespace std;

int N;
long long func(int _a) {
	long long a = (long long)_a;
	return (a + 1) * (N - a + 1);
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	long long K;
	cin >> N >> K;

	bool is_possible = false;
	int start = 0;
	int end = N / 2;
	
	while (start <= end) {
		int mid = (start + end) / 2;
		long long color_paper = func(mid);
		
		if (color_paper < K)
			start = mid + 1;
		else if (color_paper > K)
			end = mid - 1;
		else {
			is_possible = true;
			break;
		}
	}

	if (is_possible) cout << "YES";
	else cout << "NO";
}