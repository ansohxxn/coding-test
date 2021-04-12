#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	unordered_map<int, int> m;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) 
		cin >> v[i];
	vector<int> temp = v;
	sort(temp.begin(), temp.end());
	for (int i = 0; i < n; ++i)
		m[temp[i]] = i;
	for (int i = 0; i < n; ++i)
		cout << m[v[i]] << ' ';
}
