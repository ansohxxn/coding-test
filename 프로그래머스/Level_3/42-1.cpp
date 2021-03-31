#include <string>
#include <vector>
#include <queue>

using namespace std;

#define INF 9999
int n = 0;
int answer = 0;
struct Pos {
    int r;
    int c;
};
int dirR[] = { 0, 0, -1, 1 };
int dirC[] = { 1, -1, 0, 0 };
vector<vector<Pos>> allCard(7);
vector<bool> numOfCard_visited(7);
vector<vector<bool>> singleCard_visited(7);

void SmallDFS(vector<vector<int>> board, vector<Pos> sameCards, int cardNum, Pos card, int dist, int small_depth, int big_depth);

vector<vector<Pos>> Categorize(vector<vector<int>> board) {
    vector<vector<Pos>> allCard(7);
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] != 0) {
                allCard[board[i][j]].push_back({ i, j });
                n++;
            }
        }
    }
    n /= 2;

    for (int i = 0; i < allCard.size(); ++i) {
        vector<bool> v(allCard[i].size());
        singleCard_visited[i] = v;
    }
        
                
    return allCard;
}

int BFS(vector<vector<int>> board, Pos startCard, Pos destCard) {
    queue<Pos> q;
    vector<vector<bool>> checked(4, vector<bool>(4));
    vector<vector<int>> dist(4, vector<int>(4));

    q.push(startCard);
    checked[startCard.r][startCard.c] = true;
    dist[startCard.r][startCard.c] = 0;

    while (!q.empty()) {
        int nowR = q.front().r;
        int nowC = q.front().c;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextR = nowR + dirR[i];
            int nextC = nowC + dirC[i];

            if (nextR < 0 || nextC < 0 || nextR >= 4 || nextC >= 4)
                continue;
            if (checked[nextR][nextC])
                continue;

            q.push({ nextR, nextC });
            checked[nextR][nextC] = true;
            dist[nextR][nextC] = dist[nowR][nowC] + 1;
        }

        for (int i = 0; i < 4; ++i) {
            int nextR = nowR;
            int nextC = nowC;
            bool found = false;
            while (!found) {
                if (nextR + dirR[i] < 0 || nextC + dirC[i] < 0 || nextR + dirR[i] >= 4 || nextC + dirC[i] >= 4)
                    break;
                if (board[nextR + dirR[i]][nextC + dirC[i]] != 0) 
                    found = true;

                nextR += dirR[i];
                nextC += dirC[i];
            }

            if (checked[nextR][nextC])
                continue;

            q.push({ nextR, nextC });
            checked[nextR][nextC] = true;
            dist[nextR][nextC] = dist[nowR][nowC] + 1;
        }
    }

    return dist[destCard.r][destCard.c];
}

void BigDFS(vector<vector<int>> board, Pos card, int dist, int small_depth, int big_depth) {
    if (big_depth == n) {
        if (dist < answer)
            answer = dist;
        return;
    }

    for (int i = 1; i <= 6; ++i) {
        if (allCard[i].size() == 0)
            continue;
        if (numOfCard_visited[i] == false) {
            vector<Pos> sameCards = allCard[i];
            vector<bool>& sameCard_visited = singleCard_visited[i];
            SmallDFS(board, sameCards, i, card, dist, 0, big_depth);
            numOfCard_visited[i] = false;
        }
    }
}

void SmallDFS(vector<vector<int>> board, vector<Pos> sameCards, int cardNum, Pos card, int dist, int small_depth, int big_depth) {
    if (small_depth == 2) {
        dist += 2;
        bool flag = true;
        for (int i = 0; i < singleCard_visited[cardNum].size(); ++i) {
            if (singleCard_visited[cardNum][i] == false) {
                flag = false;
                break;
            }
        }
        if (flag)
            numOfCard_visited[cardNum] = true;
        BigDFS(board, card, dist, 0, big_depth + 1);
        return;
    }

    for (int i = 0; i < sameCards.size(); ++i) {
        if (singleCard_visited[cardNum][i] == false) {
            singleCard_visited[cardNum][i] = true;
            Pos nextCard{ sameCards[i].r, sameCards[i].c };
            int newDist = dist + BFS(board, card, nextCard);
            board[sameCards[i].r][sameCards[i].c] = 0;
            SmallDFS(board, sameCards, cardNum, nextCard, newDist, small_depth + 1, big_depth);
            board[sameCards[i].r][sameCards[i].c] = cardNum;
            singleCard_visited[cardNum][i] = false;
        }
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    answer = INF;
    n = 0;
    allCard = Categorize(board);
    Pos start{ r, c };
    BigDFS(board, start, 0, 0, 0);
    return answer;
}