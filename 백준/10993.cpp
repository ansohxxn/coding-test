#include <iostream>
using namespace std;

char arr[1023][2045];

int getPow(int n, int m)
{
    if (m == 0)
        return 1;
    return getPow(n, m - 1) * n;
}

void draw(int len, int startRow, int startCol, int rowNum, int colNum)
{
    if (len % 2) // 홀수일 때 그리는 방식 : 삼각형
    {
        for (int i = 0; i < rowNum; i++)
        {
            if (i == 0)  // 첫째줄 : 밑변
            {
                for (int j = 0; j < colNum; j++)
                    arr[startRow][startCol + j] = '*';
            }
            else if (i == rowNum - 1)  // 마지막줄 : 꼭짓점
            {
                arr[startRow - i][startCol + rowNum - 1] = '*';
            }
            else // 그 이외 : 2개씩 (선분)
            {
                arr[startRow - i][startCol + i] = '*';
                arr[startRow - i][startCol + colNum - i - 1] = '*';
            }
        }
    }
    else // 짝수일 때 그리는 방식 : 역삼각형
    {
        for (int i = 0; i < rowNum; i++)
        {
            if (i == 0)  // 첫째줄 : 윗변
            {
                for (int j = 0; j < colNum; j++)
                    arr[startRow][startCol + j] = '*';
            }
            else if (i == rowNum - 1)  // 마지막줄 : 꼭짓점
            {
                arr[startRow + i][startCol + rowNum - 1] = '*';
            }
            else // 그 이외 : 2개씩 (선분)
            {
                arr[startRow + i][startCol + i] = '*';
                arr[startRow + i][startCol + colNum - i - 1] = '*';
            }
        }
    }
    return;
}

void triangle(int len, int startRow, int startCol)
{
    int rowNum = getPow(2, len) - 1;
    int colNum = getPow(2, len + 1) - 3;
    
    draw(len, startRow, startCol, rowNum, colNum);
    
    if (len == 1)
        return;
        
    if (len % 2)
        triangle(len - 1, startRow - rowNum / 2, startCol + rowNum / 2 + 1); // 홀수일 때 재귀
    else
        triangle(len - 1, startRow + rowNum / 2, startCol + rowNum / 2 + 1);
}

int main()
{
    int N;
    cin >> N;
    
    int rowNum = getPow(2, N) - 1;
    int colNum = getPow(2, N + 1) - 3;
    
    // 별찍기 전에 미리 공백 넣어주기 
    for (int i = 0; i < rowNum; i++)
    {
        for (int j = 0; j < colNum; j++)
        {
            arr[i][j] = ' ';
        }
    }
    
    // 재귀 (시작점을 인수로 넘김)
    if (N % 2)
    {
        triangle(N, rowNum - 1, 0);  // 홀수면 시작점은 좌하단
    }
    else
    {
        triangle(N, 0, 0);  // 짝수면 시작점은 좌상단
    }
    
    // 출력
    for (int i = 0; i < rowNum; i++)
    {
        if (N % 2)
        {
            for (int j = 0; j < rowNum + i; j++)
            {
                cout << arr[i][j];
            }
        }
        else
        {
            for (int j = 0; j < colNum - i; j++)
            {
                cout << arr[i][j];
            }
        }
        cout << '\n';
    }
    
    return 0;
}