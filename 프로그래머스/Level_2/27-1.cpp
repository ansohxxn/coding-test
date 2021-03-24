#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";
    
    do{
        bool flag = true;
        for(int i = 0; i < n; ++i){
            int friend1_idx = 0;
            int friend2_idx = 0;
            for(int j = 0; j < friends.length(); ++j){
                if (friends[j] == data[i][0])
                    friend1_idx = j;
                if (friends[j] == data[i][2])
                    friend2_idx = j;
            }
            
            int gap = max(friend1_idx - friend2_idx, friend2_idx - friend1_idx) - 1;
            if (data[i][3] == '='){
                if (gap != data[i][4] - '0'){
                    flag = false;
                    break;
                }
            }
            if (data[i][3] == '>'){
                if (gap <= data[i][4] - '0'){
                    flag = false;
                    break;
                }
            }
            if (data[i][3] == '<'){
                if (gap >= data[i][4] - '0'){
                    flag = false;
                    break;
                }
            }
        }
        if (flag == true) answer++; 
    }while(next_permutation(friends.begin(), friends.end()));
    
    return answer;
}