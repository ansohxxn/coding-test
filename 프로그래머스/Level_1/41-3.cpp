#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool Prime[3001];

int solution(vector<int> nums) {
    int answer = 0;

    for (int i = 2; i < 3001; i++)
        Prime[i] = true;
    for (int i = 2; i < 3001; i++){
        if (Prime[i]){
            for (int j = i * i; j < 3001; j += i)
                Prime[j] = false;
        }
    }
    
    int sum = 0;

    vector<bool> comb_bool(nums.size(), true);
    for(int i = 0; i < nums.size() - 3; i++)
        comb_bool[i] = false;
    
    do{
        sum = 0;
        for(int i = 0; i < comb_bool.size(); i++){
            if (comb_bool[i])
                sum += nums[i];
        }
        
        if (Prime[sum]) 
            answer++;
        
    }while(next_permutation(comb_bool.begin(), comb_bool.end()));

    return answer;
}