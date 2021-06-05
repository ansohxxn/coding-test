#include <bits/stdc++.h>

using namespace std;

void postorder(vector<int>& preorder, map<int, int>& inorder_map, int root_index, int start, int end) {
	if (start > end) return;
	if (start == end) {
		cout << preorder[root_index] << ' ';
		return;
	}
	int pivot = inorder_map[preorder[root_index]];
	postorder(preorder, inorder_map, root_index + 1, start, pivot - 1);
	postorder(preorder, inorder_map, root_index + 1 + (pivot - start), pivot + 1, end);
	cout << preorder[root_index] << ' ';
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, N;
	cin >> T;
	while (--T >= 0) {
		cin >> N;
		vector<int> preorder(N);
		for (int i = 0; i < N; ++i) 
			cin >> preorder[i];
		map<int, int> inorder_map; // key : num,  value : inorder's index
		for (int i = 0; i < N; ++i) {
			int key;
			cin >> key;
			inorder_map[key] = i;
		}
		
		postorder(preorder, inorder_map, 0, 0, N - 1);
		cout << '\n';
	}
}
