#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct machine {
	int num;
	int gas;
};

bool cmp(const machine& a, const machine& b) { return a.num < b.num; }

int main()
{
	int n;
	scanf("%d", &n);
	vector<machine> machines(n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &machines[i].num, &machines[i].gas);
	sort(machines.begin(), machines.end(), cmp);
	for (int i = 0; i < n; ++i)
		printf("%d %d\n", machines[i].num, machines[i].gas);
}
