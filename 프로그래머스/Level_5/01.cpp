#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> arrows) {
    int answer = 0;
    
    vector<int> dx = { 0, 2, 2, 2, 0, -2, -2, -2 };
    vector<int> dy = { 2, 2, 0, -2, -2, -2, 0, 2 };
    
    map<pair<int, int>, bool> visitedNode;
    map<pair<pair<int, int>, pair<int, int>>, bool> visitedEdge;
    
    int curX = 0;
    int curY = 0;
    visitedNode[make_pair(0, 0)] = true;
    
    for(int i = 0; i < arrows.size(); i++)
    {

            int nextX = curX + dx[arrows[i]];
            int nextY = curY + dy[arrows[i]];
            
            if (visitedNode[make_pair(nextX, nextY)] == true && visitedEdge[make_pair(make_pair(curX, curY), make_pair(nextX, nextY))] == false)
                answer++;
            
            visitedNode[make_pair(nextX, nextY)] = true;
            visitedEdge[make_pair(make_pair(curX, curY), make_pair(nextX, nextY))] = true;
            visitedEdge[make_pair(make_pair(nextX, nextY), make_pair(curX, curY))] = true;
            curX = nextX;
            curY = nextY;

    }
    return answer;
}