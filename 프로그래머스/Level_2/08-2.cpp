#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int DFS (vector<vector<int>>& picture, vector<vector<bool>>& found, int& m, int& n, int& color, int row, int col){
    int count = 1;
    found[row][col] = true;
    
    if (row - 1 >= 0) 
        if(picture[row - 1][col] == color)
            if(found[row - 1][col] == false)
                count += DFS(picture, found, m, n, color, row - 1, col);
    
    if (row + 1 < m) 
        if(picture[row + 1][col] == color)
            if(found[row + 1][col] == false)
                count += DFS(picture, found, m, n, color, row + 1, col);
    
    if (col - 1 >= 0) 
        if(picture[row][col - 1] == color)
            if(found[row][col - 1] == false)
                count += DFS(picture, found, m, n, color, row, col - 1);
    
    if (col + 1 < n) 
        if(picture[row][col + 1] == color)
            if(found[row][col + 1] == false)
                count += DFS(picture, found, m, n, color, row, col + 1);
    
    return count;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2);

    vector<vector<bool>> found(m, vector<bool>(n, false));
    vector<int> colorCount;

    for (int i = 0; i < picture.size(); i++) {
        for (int j = 0; j < picture[i].size(); j++) {
            if (picture[i][j] == 0 || found[i][j] == true) continue;
                colorCount.push_back(DFS(picture, found, m, n, picture[i][j], i, j));
        }
    }

    answer[0] = colorCount.size();
    answer[1] = *max_element(colorCount.begin(), colorCount.end());

    return answer;
}