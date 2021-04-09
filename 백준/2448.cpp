#include <iostream>
using namespace std;

char arr[3072][6143];

void draw(int row, int col)
{
    // 첫번째 줄 (꼭직점에 * 1개)
    arr[row][col] = '*';
    
    // 두번째 줄 (* 2개)
    arr[row + 1][col - 1] = '*';
    arr[row + 1][col + 1] = '*';
    
    // 세번째 줄 (* 5개)
    for(int i = 0; i < 5; i++)
        arr[row + 2][col - 2 + i] = '*';
}

void triangle(int len, int row, int col)
{
    if (len == 3)
    {
        draw(row, col);
        return;  // 리턴의 유무 중요 !!!
    }
        
    triangle(len / 2, row, col);  // 첫 번째 삼각형의 꼭짓점
    triangle(len / 2, row + len / 2, col - len / 2);  // 두 번째 삼각형의 꼭짓점
    triangle(len / 2, row + len / 2, col + len / 2);  // 세 번째 삼각형의 꼭짓점
}

int main()
{
    int N;
    cin >> N;
    
    // 별찍기 전에 미리 전체 배열에 공백 넣어주기 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2 * N - 1; j++)
        {
            arr[i][j] = ' ';
        }
    }
    
    triangle(N, 0, N - 1);  // 별 찍기. 가~장 큰 삼각형부터 넘기기
    
    // 출력 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2 * N - 1; j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}
