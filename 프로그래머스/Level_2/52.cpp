#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int numOfRow = relation.size();
    int numOfCol = relation[0].size();
    
    vector<string> candKey;      // 후보키 모아 둠
    vector<bool> comb(numOfCol); // 조합 구하는데 쓰일 bool 배열
    vector<int> cols(numOfCol);  // colums 인덱스 (조합 할 대상)
    for (int i = 0; i < numOfCol; ++i)
        cols[i] = i;
    
    for (int r = 1; r <= numOfCol; ++r) {

        fill(comb.begin(), comb.end(), true);
        for (int i = 0; i < r; ++i)
            comb[i] = false;
        do {
            // Column 조합 뽑기
            string combCols = "";     // 이번에 뽑은 Column 조합(stirng으로 관리)
            for (int i = 0; i < numOfCol; ++i) 
                if (!comb[i])
                    combCols += to_string(cols[i]);
            
            // 최소성 검사
            bool isMinimal = true;
            if (!candKey.empty()) {
                for (int i = 0; i < candKey.size(); ++i) {
                    int count = 0;
                    for (int j = 0; j < candKey[i].length(); ++j) {
                        if (combCols.find(candKey[i][j]) != string::npos)
                            count++;
                    }
                    if (count == candKey[i].length()) isMinimal = false;
                }
            }
            if (isMinimal == false) continue;

            // 유일성 검사
            bool isUnique = true;
            for (int i = 0; i < numOfRow - 1; ++i) {
                for (int j = i + 1; j < numOfRow; ++j) {
                    if (relation[i][combCols[0] - '0'] == relation[j][combCols[0] - '0']) {
                        if (combCols.length() == 1){
                            isUnique = false;
                            break;
                        }
                        bool canDisc = false;
                        for (int k = 1; k < combCols.length(); ++k) {
                            if (relation[i][combCols[k] - '0'] != relation[j][combCols[k] - '0']) 
                                canDisc = true;
                        }
                        if (!canDisc)
                            isUnique = false;
                    }
                }
            }
            if (isUnique == false) continue;

            // 후보키 찾음 (위 두 검사 통과)
            candKey.push_back(combCols);

        } while (next_permutation(comb.begin(), comb.end()));
    }

    answer = candKey.size();

    return answer;
}