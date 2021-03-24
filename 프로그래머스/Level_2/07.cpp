#include <cmath>

using namespace std;

long long solution(int w, int h) {
    long long answer = 1;
    long long cantuse = 0;

    for (long long i = 1; i <= w; i++)
        cantuse += (long long)ceil((long double)h * i / w) - (long long)floor((long double)h * (i - 1) / w);

    answer = (long long)w * h - cantuse;
    return answer;
}