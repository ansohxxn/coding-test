#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Pos { int i, j; };
struct Block { Pos pos1; Pos pos2; Pos pos3; Pos pos4; };
int N = 0;
vector<vector<int>> Board;
unordered_map<int, bool> Checked;
unordered_map<int, Pos> Start;

bool PossiblePos(Block block, int value) {
    if (block.pos1.i < 0 || block.pos1.j < 0 || block.pos1.i >= N || block.pos1.j >= N) return false;
    if (block.pos2.i < 0 || block.pos2.j < 0 || block.pos2.i >= N || block.pos2.j >= N) return false;
    if (block.pos3.i < 0 || block.pos3.j < 0 || block.pos3.i >= N || block.pos3.j >= N) return false;
    if (block.pos4.i < 0 || block.pos4.j < 0 || block.pos4.i >= N || block.pos4.j >= N) return false;
    if (Board[block.pos1.i][block.pos1.j] != value ||
        Board[block.pos2.i][block.pos2.j] != value ||
        Board[block.pos3.i][block.pos3.j] != value ||
        Board[block.pos4.i][block.pos4.j] != value)
        return false;
    return true;
}

Block BlockPos(Pos pos1, int num) {
    if (num == 1) return { pos1, { pos1.i, pos1.j + 1 }, { pos1.i, pos1.j + 2 }, { pos1.i + 1, pos1.j + 2 } };
    if (num == 2) return { pos1, { pos1.i, pos1.j + 1 }, { pos1.i + 1, pos1.j }, { pos1.i + 2, pos1.j } };
    if (num == 3) return { pos1, { pos1.i + 1, pos1.j }, { pos1.i + 1, pos1.j + 1 }, { pos1.i + 1, pos1.j + 2 } };
    if (num == 4) return { pos1, { pos1.i + 1, pos1.j }, { pos1.i + 2, pos1.j }, { pos1.i + 2, pos1.j - 1 } };
    if (num == 5) return { pos1, { pos1.i, pos1.j + 1 }, { pos1.i, pos1.j + 2 }, { pos1.i + 1, pos1.j } };
    if (num == 6) return { pos1, { pos1.i + 1, pos1.j }, { pos1.i + 2, pos1.j }, { pos1.i + 2, pos1.j + 1 } };
    if (num == 7) return { pos1, { pos1.i + 1, pos1.j - 2 }, { pos1.i + 1, pos1.j - 1 }, { pos1.i + 1, pos1.j } };
    if (num == 8) return { pos1, { pos1.i, pos1.j + 1 }, { pos1.i + 1, pos1.j + 1 }, { pos1.i + 2, pos1.j + 1 } };
    if (num == 9) return { pos1, { pos1.i + 1, pos1.j - 1 }, { pos1.i + 1, pos1.j }, { pos1.i + 1, pos1.j + 1 } };
    if (num == 10) return { pos1, { pos1.i + 1, pos1.j }, { pos1.i + 1, pos1.j + 1 }, { pos1.i + 2, pos1.j } };
    if (num == 11) return { pos1, { pos1.i, pos1.j + 1 }, { pos1.i, pos1.j + 2 }, { pos1.i + 1, pos1.j + 1 } };
    if (num == 12) return { pos1, { pos1.i + 1, pos1.j - 1 }, { pos1.i + 1, pos1.j }, { pos1.i + 2, pos1.j } };
}

int BlockName(Pos pos1, int value) {
    Block block; 
    
    block = BlockPos(pos1, 1); if (PossiblePos(block, value)) return 1;
    block = BlockPos(pos1, 2); if (PossiblePos(block, value)) return 2;
    block = BlockPos(pos1, 3); if (PossiblePos(block, value)) return 3;
    block = BlockPos(pos1, 4); if (PossiblePos(block, value)) return 4;
    block = BlockPos(pos1, 5); if (PossiblePos(block, value)) return 5;
    block = BlockPos(pos1, 6); if (PossiblePos(block, value)) return 6;
    block = BlockPos(pos1, 7); if (PossiblePos(block, value)) return 7;
    block = BlockPos(pos1, 8); if (PossiblePos(block, value)) return 8;
    block = BlockPos(pos1, 9); if (PossiblePos(block, value)) return 9;
    block = BlockPos(pos1, 10); if (PossiblePos(block, value)) return 10;
    block = BlockPos(pos1, 11); if (PossiblePos(block, value)) return 11;
    block = BlockPos(pos1, 12); if (PossiblePos(block, value)) return 12;

}

bool IsErasableBlock(int block) {
    if (block == 3 || block == 4 || block == 6 || block == 7 || block == 9) return true;
    else return false;
}

vector<Pos> BlackBlock(Pos pos1, int block) {
    vector<Pos> blackblocks;
    if (block == 3) {
        Pos black1{ pos1.i, pos1.j + 1 }; Pos black2{ pos1.i, pos1.j + 2 };
        if (Board[black1.i][black1.j] == 0 && Board[black2.i][black2.j] == 0) {
            blackblocks.push_back(black1);
            blackblocks.push_back(black2);
        }
    }
    if (block == 4) {
        Pos black1{ pos1.i, pos1.j - 1 }; Pos black2{ pos1.i + 1, pos1.j - 1 };
        if (Board[black1.i][black1.j] == 0 && Board[black2.i][black2.j] == 0) {
            blackblocks.push_back(black1);
            blackblocks.push_back(black2);
        }
    }
    if (block == 6) {
        Pos black1{ pos1.i, pos1.j + 1 }; Pos black2{ pos1.i + 1, pos1.j + 1 };
        if (Board[black1.i][black1.j] == 0 && Board[black2.i][black2.j] == 0) {
            blackblocks.push_back(black1);
            blackblocks.push_back(black2);
        }
    }
    if (block == 7) {
        Pos black1{ pos1.i, pos1.j - 2 }; Pos black2{ pos1.i, pos1.j - 1 };
        if (Board[black1.i][black1.j] == 0 && Board[black2.i][black2.j] == 0) {
            blackblocks.push_back(black1);
            blackblocks.push_back(black2);
        }
    }
    if (block == 9) {
        Pos black1{ pos1.i, pos1.j - 1 }; Pos black2{ pos1.i, pos1.j + 1 };
        if (Board[black1.i][black1.j] == 0 && Board[black2.i][black2.j] == 0) {
            blackblocks.push_back(black1);
            blackblocks.push_back(black2);
        }
    }
    return blackblocks;
}

void EraseBlock(Block block) {
    Board[block.pos1.i][block.pos1.j] = 0;
    Board[block.pos2.i][block.pos2.j] = 0;
    Board[block.pos3.i][block.pos3.j] = 0;
    Board[block.pos4.i][block.pos4.j] = 0;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    Board = board;
    N = board.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) { 
            if (Board[i][j] == 0) continue;
            if (Checked[Board[i][j]]) continue;

            Pos startPos;
            if (Start.find(Board[i][j]) == Start.end()) {
                startPos.i = i; startPos.j = j;
                Start[Board[i][j]] = startPos;
            }
            else startPos = Start[Board[i][j]];

            int blockNum = BlockName(startPos, Board[i][j]);
            if (IsErasableBlock(blockNum)) {
                vector<Pos> blackblocks = BlackBlock(startPos, blockNum);
                if (blackblocks.empty()) continue;
                
                bool obstacle = false;
                for (int i = blackblocks[0].i; i >= 0; --i) {
                    if (Board[i][blackblocks[0].j] != 0) {
                        obstacle = true;
                        break;
                    }
                }
                if (obstacle) continue;
                for (int i = blackblocks[1].i; i >= 0; --i) {
                    if (Board[i][blackblocks[1].j] != 0) {
                        obstacle = true;
                        break;
                    }
                }
                if (obstacle) continue;
                Block block = BlockPos(startPos, blockNum);
                EraseBlock(block);

                Checked[Board[i][j]] = true;
                answer++;
            }
            else 
                Checked[Board[i][j]] = true;
        }
    }
    return answer;
}