#include <string>
#include <vector>
#include <unordered_set>
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

    bool operator == (const Robot& other) const {
        bool condition1 = part1.y == other.part1.y && part1.x == other.part1.x;
        bool condition2 = part2.y == other.part2.y && part2.x == other.part2.x;
        bool condition3 = part1.y == other.part2.y && part1.x == other.part2.x;
        bool condition4 = part2.y == other.part1.y && part2.x == other.part1.x;
        if (condition1 && condition2 || condition3 && condition4)
            return true;
        return false;
    }
};

struct MyHash {
    size_t operator()(const Robot& robot) const {
        hash<int> hash_func;
        return hash_func(robot.part1.y) ^ robot.part1.x ^ robot.part2.y + hash_func(robot.part2.x);
    }
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
    unordered_set<Robot, MyHash> checked;

    Robot start{ { 0, 0, LEFT }, { 0, 1, RIGHT }, 0 };
    checked.insert(start);
    q.push(start);

    while (!q.empty()) {
        // 방문
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
            Robot next{ next_part_1, next_part_2, now.time + 1 };

            if (!possible(board, next_part_1, next_part_2))
                continue;
            if (checked.find(next) != checked.end())
                continue;

            q.push(next);
            checked.insert(next);
        }

        /* 예약 : 회전 */
        if (now.part1.dir == LEFT) {
            Pos up_left{ now.part1.y - 1, now.part1.x, UP };
            Pos up_right{ now.part2.y - 1, now.part2.x, UP };
            if (possible(board, up_left, up_right)) {
                Robot next1{ up_left, { now.part1.y, now.part1.x, DOWN } , now.time + 1 };
                if (checked.find(next1) == checked.end()) {
                    q.push(next1);
                    checked.insert(next1);
                }
                Robot next2{ up_right, { now.part2.y, now.part2.x, DOWN } , now.time + 1 };
                if (checked.find(next2) == checked.end()) {
                    q.push(next2);
                    checked.insert(next2);
                }
            }
            Pos down_left{ now.part1.y + 1, now.part1.x, DOWN };
            Pos down_right{ now.part2.y + 1, now.part2.x, DOWN };
            if (possible(board, down_left, down_right)) {
                Robot next1{ { now.part1.y, now.part1.x, UP }, down_left, now.time + 1 };
                if (checked.find(next1) == checked.end()) {
                    q.push(next1);
                    checked.insert(next1);
                }
                Robot next2{ { now.part2.y, now.part2.x, UP } , down_right, now.time + 1 };
                if (checked.find(next2) == checked.end()) {
                    q.push(next2);
                    checked.insert(next2);
                }
            }
        }
        if (now.part1.dir == UP) {
            Pos left_up{ now.part1.y, now.part1.x - 1, LEFT };
            Pos left_down{ now.part2.y, now.part2.x - 1, LEFT };
            if (possible(board, left_up, left_down)) {
                Robot next1{ left_up, { now.part1.y, now.part1.x, RIGHT } , now.time + 1 };
                if (checked.find(next1) == checked.end()) {
                    q.push(next1);
                    checked.insert(next1);
                }
                Robot next2{ left_down, { now.part2.y, now.part2.x, RIGHT } , now.time + 1 };
                if (checked.find(next2) == checked.end()) {
                    q.push(next2);
                    checked.insert(next2);
                }
            }
            Pos right_up{ now.part1.y, now.part1.x + 1, RIGHT };
            Pos right_down{ now.part2.y, now.part2.x + 1, RIGHT };
            if (possible(board, right_up, right_down)) {
                Robot next1{ { now.part1.y, now.part1.x, LEFT } , right_up, now.time + 1 };
                if (checked.find(next1) == checked.end()) {
                    q.push(next1);
                    checked.insert(next1);
                }
                Robot next2{ { now.part2.y, now.part2.x, LEFT } , right_down, now.time + 1 };
                if (checked.find(next2) == checked.end()) {
                    q.push(next2);
                    checked.insert(next2);
                }
            }
        }
    }

    return answer;
}