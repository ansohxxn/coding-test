#include <string>
#include <vector>

using namespace std;

int winDFS(vector<vector<int>> results, vector<bool> & visited, int start)
{
    int count = 0;
    visited[start] = true;
    for(int i = 0; i < results.size(); i++)
    {
        if (start == results[i][0] && !visited[results[i][1]])
            count = count + winDFS(results, visited, results[i][1]) + 1;
    }
    return count;
}
                                               
int loseDFS(vector<vector<int>> results, vector<bool> & visited, int start)
{
    int count = 0;
    visited[start] = true;
    for(int i = 0; i < results.size(); i++)
    {
        if (start == results[i][1] && !visited[results[i][0]])
            count = count + loseDFS(results, visited, results[i][0]) + 1;
    }
    return count;
}          

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(int i = 1; i <= n; i++)
    {
        vector<bool> winVisited(n + 1);
        vector<bool> loseVisited(n + 1);
        
        int count = winDFS(results, winVisited, i) + loseDFS(results, loseVisited, i);
        
        if (count == n - 1)
            answer++;
    }
    
    return answer;
}