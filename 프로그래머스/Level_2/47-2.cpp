#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    while(a != b){
        a = a / 2 + a % 2;
        b = b / 2 + b % 2;
        answer++;
    }

    return answer;
}