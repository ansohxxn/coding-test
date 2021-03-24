#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int m = arr1.size();
    int l = arr2.size();
    int n = arr2[0].size();
    vector<vector<int>> answer(m, vector<int>(n, 0));
    
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < l; k++)
                answer[i][j] += arr1[i][k] * arr2[k][j];
    
    return answer;
}