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

	vector<Elem> bind;
	for (int i = 0; i < N - 1; ++i)
		for (int j = i + 1; j < N; ++j)
			bind.push_back({ i, j, snow[i] + snow[j] });
	sort(bind.begin(), bind.end(), cmp);

	int answer = INT_MAX;
	for (int i = 0; i < bind.size() - 1; ++i) {
		Elem anna = bind[i];
		for (int j = i + 1; j < bind.size(); ++j) {
			Elem elsa = bind[j];
			if (elsa.index1 != anna.index1 && elsa.index1 != anna.index2 && elsa.index2 != anna.index1 && elsa.index2 != anna.index2) {
				answer = min(answer, elsa.sum - anna.sum);
				break;
			}
		}
	}
	cout << answer;
}
