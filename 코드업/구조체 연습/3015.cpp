#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct stu {
	string name;
	int score;
};

bool cmp(const stu& a, const stu& b) { return a.score > b.score; }

int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	vector<stu> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].name;
		cin >> v[i].score;
	}
	stable_sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < m; ++i)
		cout << v[i].name << '\n';
}
