#include <bits/stdc++.h>

using namespace std;

int R, C;
struct Pos { int r, c; };
struct Shark { int id; Pos pos; int speed, dir, size; };
#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

void move(Shark& shark) {
	int tmp, mod;

	switch (shark.dir) {
	case UP:
		tmp = (shark.speed - shark.pos.r + 1 > 0) ? shark.speed - shark.pos.r + 1 : 0;
		mod = ceil((double)tmp / (R - 1));
		if (mod == 0) // 방향 안 바뀜 (턴을 한 번도 안함)
			shark.pos.r = shark.pos.r - shark.speed;
		else if (mod % 2 == 0) // 방향 안 바뀜 (턴 함. 2번 이상 짝수로 한 것.)
			shark.pos.r = R - (tmp % (R - 1) == 0 ? R - 1 : tmp % (R - 1));
		else if (mod % 2 == 1) {  // 방향 바뀜 (턴 함. 홀수로 한 것.)
			shark.pos.r = 1 + (tmp % (R - 1) == 0 ? R - 1 : tmp % (R - 1));
			shark.dir = DOWN;
		}
		break;

	case DOWN:
		tmp = (shark.speed - (R - shark.pos.r) > 0) ? shark.speed - (R - shark.pos.r) : 0;
		mod = ceil((double)tmp / (R - 1));
		if (mod == 0)
			shark.pos.r = shark.pos.r + shark.speed;
		else if (mod % 2 == 0) 
			shark.pos.r = 1 + (tmp % (R - 1) == 0 ? R - 1 : tmp % (R - 1));
		else if (mod % 2 == 1) {
			shark.pos.r = R - (tmp % (R - 1) == 0 ? R - 1 : tmp % (R - 1));
			shark.dir = UP;
		}
		break;

	case RIGHT:
		tmp = (shark.speed - (C - shark.pos.c) > 0) ? shark.speed - (C - shark.pos.c) : 0;
		mod = ceil((double)tmp / (C - 1));
		if (mod == 0)
			shark.pos.c = shark.pos.c + shark.speed;
		else if (mod % 2 == 0)
			shark.pos.c = 1 + (tmp % (C - 1) == 0 ? C - 1 : tmp % (C - 1));
		else if (mod % 2 == 1) {
			shark.pos.c = C - (tmp % (C - 1) == 0 ? C - 1 : tmp % (C - 1));
			shark.dir = LEFT;
		}
		break;

	case LEFT:
		tmp = (shark.speed - shark.pos.c + 1 > 0) ? shark.speed - shark.pos.c + 1 : 0;
		mod = ceil((double)tmp / (C - 1));
		if (mod == 0) 
			shark.pos.c = shark.pos.c - shark.speed;
		else if (mod % 2 == 0) 
			shark.pos.c = C - (tmp % (C - 1) == 0 ? C - 1 : tmp % (C - 1));
		else if (mod % 2 == 1) {  
			shark.pos.c = 1 + (tmp % (C - 1) == 0 ? C - 1 : tmp % (C - 1));
			shark.dir = RIGHT;
		}
		break;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int M;
	cin >> R >> C >> M;
	vector<vector<int>> board(R + 1, vector<int>(C + 1, -1));
	vector<Shark> sharks;
	for (int i = 0; i < M; ++i) {
		Shark shark;
		shark.id = i;
		cin >> shark.pos.r >> shark.pos.c >> shark.speed >> shark.dir >> shark.size;
		
		sharks.push_back(shark);
		board[shark.pos.r][shark.pos.c] = i;
	}

	int answer = 0;
	for (int c = 1; c <= C; ++c) {
		for (int r = 1; r <= R; ++r) { // 상어 낚시
			if (board[r][c] != -1) {
				answer += sharks[board[r][c]].size;
				sharks[board[r][c]].id = -1;
				board[r][c] = -1;
				break;
			}
		}
		for (int i = 0; i < sharks.size(); ++i) { // 상어 이동
			if (sharks[i].id == -1)
				continue;
			
			int r = sharks[i].pos.r;
			int c = sharks[i].pos.c;
			
			board[r][c] = -1;
			move(sharks[i]);
		}

		for (int i = 0; i < sharks.size(); ++i) { // 상어 싸움
			if (sharks[i].id == -1)
				continue;

			int r = sharks[i].pos.r;
			int c = sharks[i].pos.c;
			
			if (board[r][c] == -1)
				board[r][c] = i;
			else {
				Shark& other = sharks[board[r][c]];
				if (other.size < sharks[i].size) {
					board[r][c] = i;
					other.id = -1;
				}
				else
					sharks[i].id = -1;
			}
		}
	}
	cout << answer;
}