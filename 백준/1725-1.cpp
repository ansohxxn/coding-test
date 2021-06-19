#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    stack <int> st;
	
	int N;
	long long answer = 0;
	cin >> N;
	vector<int> histogram(N);
	for (int i = 0; i < N; i++)
		cin >> histogram[i];

	for (int i = 0; i < N; i++) { //
		while (!st.empty() && histogram[i] < histogram[st.top()]) {
			int j = st.top();
			int width;
			st.pop();
			if (st.empty())
				width = i;
			else
				width = i - st.top() - 1;

			answer = max(answer, (long long)histogram[j] * width);

		}
		st.push(i);
	}

	while (!st.empty()) {
		int j = st.top();
		int width;
		st.pop();
		if (st.empty())
			width = N;
		else
			width = N - st.top() - 1;

		answer = max(answer, (long long)histogram[j] * width);
	}

	cout << answer;
}