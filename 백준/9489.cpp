#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (true) {
		int N, K;
		cin >> N >> K;
		if (N == 0 || K == 0)
			break;

		vector<int> arr(N);
		for (int i = 0; i < N; ++i)
			cin >> arr[i];

		map<int, int> parent;
		parent[arr[0]] = 0;
		map<int, vector<int>> children;
		map<int, int>::iterator parent_ptr;
		for (int i = 1; i < N; ++i) {
			if (arr[i] - arr[i - 1] > 1) {
				if (i == 1) parent_ptr = parent.begin();
				else ++parent_ptr;
			}
			parent[arr[i]] = parent_ptr->first;
			children[parent_ptr->first].push_back(arr[i]);
		}

		if (parent[K] == K || parent[K] == arr[0])
			cout << 0 << '\n';
		else {
			int grandParent = parent[parent[K]];
			vector<int> uncles= children[grandParent];
			int count = 0;
			for (int i = 0; i < uncles.size(); ++i)
				if (uncles[i] != parent[K])
					count += children[uncles[i]].size();
			cout << count << '\n';
		}
	}
}