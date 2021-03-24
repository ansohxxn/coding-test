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

    for(int i = 0; i < nums.size(); i++)
        for(int j = i + 1; j < nums.size(); j++)
            for(int k = j + 1; k < nums.size(); k++){
                if(Prime[nums[i] + nums[j] + nums[k]])
                    answer++;
            }
    return answer;
}