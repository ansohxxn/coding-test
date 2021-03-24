#include <string>
#include <vector>

using namespace std;

#define INF 20000000

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    vector<vector<int>> minTaxiCost(n + 1, vector<int>(n + 1, INF));
    
    for(int i = 0; i < fares.size(); ++i){ 
        minTaxiCost[fares[i][0]][fares[i][1]] = fares[i][2];
        minTaxiCost[fares[i][1]][fares[i][0]] = fares[i][2];
    }   

    for(int i = 1; i <= n; ++i)
        minTaxiCost[i][i] = 0;

    for(int k = 1; k <= n; ++k) 
        for(int i = 1; i <= n; ++i) 
            for(int j = 1; j <= n; ++j) 
                if (minTaxiCost[i][j] > minTaxiCost[i][k] + minTaxiCost[k][j]) 
                    minTaxiCost[i][j] = minTaxiCost[i][k] + minTaxiCost[k][j];

    for(int i = 1; i <= n; ++i)
        if (answer > minTaxiCost[s][i] + minTaxiCost[i][a] + minTaxiCost[i][b])
            answer = minTaxiCost[s][i] + minTaxiCost[i][a] + minTaxiCost[i][b];
          
    return answer;
}