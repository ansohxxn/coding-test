#include <string>
#include <vector>

using namespace std;

void DFS(vector<int>& answer, int& n, int elem, int startIndex, int depth) {

    int arrSize = n * (n + 1) / 2;

    // 1. 꼭짓점
    answer[startIndex] = elem++;

    if (elem > arrSize)
        return;

    const int length = n - 3 * depth;

    // 2. 왼쪽 빗변 
    int indexTerm = 2 * depth + 1;
    for (int count = 1; count <= length - 1 && elem <= arrSize; count++) {
        answer[startIndex + indexTerm] = elem++;
        startIndex += indexTerm;
        indexTerm++;
    }

    // 3. 밑변 
    for (int count = 1; count <= length - 1 && elem <= arrSize; count++) {
        startIndex++;
        answer[startIndex] = elem++;
    }

    // 4. 오른쪽 빗변 
    indexTerm =  n - depth;
    for (int count = 1; count <= length - 2 && elem <= arrSize; count++) {
        answer[startIndex - indexTerm] = elem++;
        startIndex -= indexTerm;
        indexTerm--;
    }

    int X = 2 * (depth + 1);
    startIndex = X * (X + 1) / 2 + (depth + 1);
    if (elem <= arrSize)
        DFS(answer, n, elem, startIndex, depth + 1);

    return;
}

vector<int> solution(int n) {
    vector<int> answer(n * (n + 1) / 2);

    DFS(answer, n, 1, 0, 0);

    return answer;
}