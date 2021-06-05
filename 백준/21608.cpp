#include <bits/stdc++.h>

using namespace std;

struct Elem {
	int x, y;
	int num_of_favorite_student;
	int num_of_empty;
};

struct cmp {
	bool operator() (const Elem& a, const Elem& b) {
		if (a.num_of_favorite_student != b.num_of_favorite_student)
			return a.num_of_favorite_student < b.num_of_favorite_student;
		else if (a.num_of_empty != b.num_of_empty)
			return a.num_of_empty < b.num_of_empty;
		else if (a.x != b.x)
			return a.x > b.x;
		return a.y > b.y;
	}
};

int satisfaction(int num_of_favorite_student) {
	switch (num_of_favorite_student) {
	case 0:
		return 0;
	case 1:
		return 1;
	case 2:
		return 10;
	case 3: 
		return 100;
	case 4:
		return 1000;
	}
}

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> students(N * N);
	map<int, unordered_set<int>> crush_on;
	for (int idx = 0; idx < N * N; ++idx) {
		cin >> students[idx];
		for (int j = 0; j < 4; ++j) {
			int stu;
			cin >> stu;
			crush_on[students[idx]].insert(stu);
		}
	}

	vector<vector<int>> class_room(N, vector<int>(N, 0));
	for (int idx = 0; idx < N * N; ++idx) {
		priority_queue<Elem, vector<Elem>, cmp> pq;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (class_room[i][j] != 0) continue;

				int fav_cnt = 0, empty_cnt = 0;
				for (int k = 0; k < 4; ++k) {
					int next_x = i + dx[k];
					int next_y = j + dy[k];

					if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;
					if (class_room[next_x][next_y] == 0)
						++empty_cnt;
					if (crush_on[students[idx]].find(class_room[next_x][next_y]) != crush_on[students[idx]].end())
						++fav_cnt;
				}

				pq.push({ i, j, fav_cnt, empty_cnt });
			}
		}

		Elem elem = pq.top();
		pq.pop();

		class_room[elem.x][elem.y] = students[idx];
	}


	int answer = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int fav_cnt = 0;
			for (int k = 0; k < 4; ++k) {
				int next_x = i + dx[k];
				int next_y = j + dy[k];

				if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;
				if (crush_on[class_room[i][j]].find(class_room[next_x][next_y]) != crush_on[class_room[i][j]].end())
					++fav_cnt;
			}
			answer += satisfaction(fav_cnt);
		}
	}

	cout << answer;
}
