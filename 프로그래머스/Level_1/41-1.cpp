#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool Prime[3001];

bool isPrime(vector<int> three){
    int sum = three[0] + three[1] + three[2];

    if (Prime[sum]) return true;
    else return false;
}

void DFS(vector<int>& nums, vector<int> three, int& answer, int start, int depth){
    if (depth == 3){
        if (isPrime(three))
            answer++;
        return;
    }

    // 👇 조합의 특징
    // a가 등장했다면 그 다음엔 b,c,d 에서만 등장할 수 있다.
    // a는 다시는 한번 등장했다면 다시는 등장할 수 없다.
    for (int i = start; i < nums.size(); i++){
        three[depth] = nums[i];
        DFS(nums, three, answer, i + 1, depth + 1);
    }
}

int solution(vector<int> nums){
    int answer = 0;

    for (int i = 2; i < 3001; i++)
        Prime[i] = true;
    for (int i = 2; i < 3001; i++){
        if (Prime[i]){
            for (int j = i * i; j < 3001; j += i)
                Prime[j] = false;
        }
    }

    vector<int> three(3);
    DFS(nums, three, answer, 0, 0);

    return answer;
}