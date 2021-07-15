#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	map<string, int> trees;
	string tree_name;
	double size = 0;
	while (getline(cin, tree_name)) {
		trees[tree_name]++;
		size++;
	}
	
	cout << fixed << setprecision(4);
	for (auto& tree : trees)
		cout << tree.first << " " << (tree.second / size) * 100 << '\n';
}