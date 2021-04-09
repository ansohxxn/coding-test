#include <iostream>
using namespace std;

char arr[397][397];

void draw(int len, int row, int col)
{
    for(int i = 0; i < len; i++)
    {
        if (i == 0 || i == len - 1) // 윗 변, 아랫 변
        {
            for(int j = 0; j < len; j++)
                arr[row + i][col + j] = '*';
        }
        else // 높이 : 별 두개만 찍기
        {
            arr[row + i][col] = '*';  // 첫번째 열
            arr[row + i][col + len - 1] = '*';  // 마지막 열
        }
    }
}

void square(int n, int row, int col)
{
    int len = 4 * n - 3;
    
    draw(len, row, col);  // 재귀 전, 현재 지점의 사각형 먼저 그리기! 
    
    if (n == 1)
    {
        return;  // 리턴의 유무 중요 !!!
    }
        
    square(n - 1, row + 2, col + 2);  // 다음 사각형으로 재귀시 다음 재귀 시작 지점 인수로 넘겨주기

}

int main()
{
    int N;
    cin >> N;
    
    // 별찍기 전에 미리 전체 배열에 공백 넣어주기 
    for (int i = 0; i < 4 * N - 3; i++)
    {
        for (int j = 0; j < 4 * N - 3; j++)
        {
            arr[i][j] = ' ';
        }
    }
    
    square(N, 0, 0);  // 별 찍기. 가~장 큰 사각형부터 넘기기. 시작점은 좌상단.
    
    // 출력 
    for (int i = 0; i < 4 * N - 3; i++)
    {
        for (int j = 0; j < 4 * N - 3; j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}