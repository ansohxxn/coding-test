#include <string>
#include <vector>
#include <queue>

using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int N;

struct Pos {
    int y;
    int x;
    int dir;
};

struct Robot {
    Pos part1;
    Pos part2;
    int time;
};

bool possible(vector<vector<int>> board, Pos part1, Pos part2) {
    if (part1.y < 0 || part1.y >= N || part1.x < 0 || part1.x >= N ||
        part2.y < 0 || part2.y >= N || part2.x < 0 || part2.x >= N)
        return false;
    if (board[part1.y][part1.x] == 1 ||
        board[part2.y][part2.x] == 1)
        return false;

    return true;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    N = board.size();
   
    queue<Robot> q;
    bool checked[100][100][4] = { false };

    Robot start{ { 0, 0, LEFT }, { 0, 1, RIGHT }, 0 };
    checked[0][0][LEFT] = true;
    checked[0][1][RIGHT] = true;
    q.push(start);

    while (!q.empty()) {
        Robot now = q.front();
        q.pop();

        if (now.part1.y == N - 1 && now.part1.x == N - 1 || now.part2.y == N - 1 && now.part2.x == N - 1) {
            answer = now.time;
            break;
        }
        
        /* 예약 : 이동 */
        for (int i = 0; i < 4; ++i) {
            Pos next_part_1{ now.part1.y + dy[i], now.part1.x + dx[i], now.part1.dir };
            Pos next_part_2{ now.part2.y + dy[i], now.part2.x + dx[i], now.part2.dir };
            
            if (!possible(board, next_part_1, next_part_2))
                continue;
            if (checked[next_part_1.y][next_part_1.x][next_part_1.dir] && checked[next_part_2.y][next_part_2.x][next_part_2.dir])
                continue;

            Robot next{ next_part_1, next_part_2, now.time + 1 };
            q.push(next);
            checked[next.part1.y][next.part1.x][next.part1.dir] = true;
            checked[next.part2.y][next.part2.x][next.part2.dir] = true;
        }

        /* 예약 : 회전 */
        if (now.part1.dir == LEFT) {
            Pos up_left{ now.part1.y - 1, now.part1.x, UP };
            Pos up_right{ now.part2.y - 1, now.part2.x, UP };
            if (possible(board, up_left, up_right)) {
                if (!checked[up_left.y][up_left.x][UP] || !checked[now.part1.y][now.part1.x][DOWN]) {
                    q.push({ up_left, { now.part1.y, now.part1.x, DOWN } , now.time + 1});
                    checked[up_left.y][up_left.x][UP] = true;
                    checked[now.part1.y][now.part1.x][DOWN] = true;
                }
                if (!checked[up_right.y][up_right.x][UP] || !checked[now.part2.y][now.part2.x][DOWN]) {
                    q.push({ up_right, { now.part2.y, now.part2.x, DOWN } , now.time + 1 });
                    checked[up_right.y][up_right.x][UP] = true;
                    checked[now.part2.y][now.part2.x][DOWN] = true;
                }
            }
            Pos down_left{ now.part1.y + 1, now.part1.x, DOWN };
            Pos down_right{ now.part2.y + 1, now.part2.x, DOWN };
            if (possible(board, down_left, down_right)) {
                if (!checked[down_left.y][down_left.x][DOWN] || !checked[now.part1.y][now.part1.x][UP]) {
                    q.push({ { now.part1.y, now.part1.x, UP } , down_left, now.time + 1 });
                    checked[down_left.y][down_left.x][DOWN] = true;
                    checked[now.part1.y][now.part1.x][UP] = true;
                }
                if (!checked[down_right.y][down_right.x][DOWN] || !checked[now.part2.y][now.part2.x][UP]) {
                    q.push({ { now.part2.y, now.part2.x, UP } , down_right, now.time + 1 });
                    checked[down_right.y][down_right.x][DOWN] = true;
                    checked[now.part2.y][now.part2.x][UP] = true;
                }
            }
        }
        if (now.part1.dir == UP) {
            Pos left_up{ now.part1.y, now.part1.x - 1, LEFT };
            Pos left_down{ now.part2.y, now.part2.x - 1, LEFT };
            if (possible(board, left_up, left_down)) {
                if (!checked[left_up.y][left_up.x][LEFT] || !checked[now.part1.y][now.part1.x][RIGHT]) {
                    q.push({ left_up, { now.part1.y, now.part1.x, RIGHT } , now.time + 1 });
                    checked[left_up.y][left_up.x][LEFT] = true;
                    checked[now.part1.y][now.part1.x][RIGHT] = true;
                }
                if (!checked[left_down.y][left_down.x][LEFT] || !checked[now.part2.y][now.part2.x][RIGHT]) {
                    q.push({ left_down, { now.part2.y, now.part2.x, RIGHT } , now.time + 1 });
                    checked[left_down.y][left_down.x][LEFT] = true;
                    checked[now.part2.y][now.part2.x][RIGHT] = true;
                }
            }
            Pos right_up{ now.part1.y, now.part1.x + 1, RIGHT };
            Pos right_down{ now.part2.y, now.part2.x + 1, RIGHT };
            if (possible(board, right_up, right_down)) {
                if (!checked[right_up.y][right_up.x][RIGHT] || !checked[now.part1.y][now.part1.x][LEFT]) {
                    q.push({ { now.part1.y, now.part1.x, LEFT } , right_up, now.time + 1 });
                    checked[right_up.y][right_up.x][RIGHT] = true;
                    checked[now.part1.y][now.part1.x][LEFT] = true;
                }
                if (!checked[right_down.y][right_down.x][RIGHT] || !checked[now.part2.y][now.part2.x][LEFT]) {
                    q.push({ { now.part2.y, now.part2.x, LEFT } , right_down, now.time + 1 });
                    checked[right_down.y][right_down.x][RIGHT] = true;
                    checked[now.part2.y][now.part2.x][LEFT] = true;
                }
            }
        }
    }

    return answer;
}