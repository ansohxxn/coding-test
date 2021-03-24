#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<queue<int>> dolls(board.size());
    vector<int> basket;
    
    for(int i = 0; i < board.size(); i++)
        for(int j = 0; j < board.size(); j++)
            if (board[i][j] != 0)
                dolls[j].push(board[i][j]);
    
    for(int i = 0; i < moves.size(); i++)
    {
        if(!dolls[moves[i] - 1].empty())
        {
            basket.push_back(dolls[moves[i] - 1].front());
            dolls[moves[i] - 1].pop();
        }
        
        int end = basket.size() - 1;
        if (basket.size() >= 2 && basket[end] == basket[end - 1])
        {
            for(int j = 0; j < 2; j++)
            {
                basket.pop_back();
                answer++;
            }
        }
    }
    
    return answer;
}