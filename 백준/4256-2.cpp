#include <bits/stdc++.h>

using namespace std;

void post_order(vector<int>& preorder, vector<int>& inorder, int s, int e, int r) {
	for (int i = s; i < e; ++i) {
		if (inorder[i] == preorder[r]) {
			post_order(preorder, inorder, s, i, r + 1);
			post_order(preorder, inorder, i + 1, e, r + 1 + i - s);
			cout << preorder[r] << ' ';
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> preorder(n);
		for (int i = 0; i < n; ++i)
			cin >> preorder[i];
		vector<int> inorder(n);
		for (int i = 0; i < n; ++i)
			cin >> inorder[i];

		post_order(preorder, inorder, 0, n, 0);
		cout << '\n';
	}
}