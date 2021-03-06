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

    // π μ‘°ν©μ νΉμ§
    // aκ° λ±μ₯νλ€λ©΄ κ·Έ λ€μμ b,c,d μμλ§ λ±μ₯ν  μ μλ€.
    // aλ λ€μλ νλ² λ±μ₯νλ€λ©΄ λ€μλ λ±μ₯ν  μ μλ€.
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