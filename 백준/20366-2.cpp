#include <bits/stdc++.h>

using namespace std;

struct Elem { int index1, index2, sum; };
bool cmp(const Elem& a, const Elem& b) {
	return a.sum < b.sum;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> snow(N);
	for (int i = 0; i < N; ++i)
		cin >> snow[i];
	sort(snow.begin(), snow.end());

	int answer = INT_MAX;
	for (int i = 0; i < N - 3; ++i) {
		for (int j = i + 3; j < N; ++j) {
			int left = i + 1;
			int right = j - 1;

			while (left < right) {
                int elsa = snow[i] + snow[j];
                int anna = snow[left] + snow[right];
				int result = anna - elsa;
				
				if (result > 0) 
					right = right - 1;
				else 
					left = left + 1;
                
                answer = min(answer, abs(result));
			}
		}
	}
	cout << answer;
}
