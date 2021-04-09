#include <iostream>
using namespace std;

char arr[6561][6561];

void draw(int row, int col)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if (!(i == 1 && j == 1))
                arr[row + i][col + j] = '*';
        }
    }
}

void square(int len, int row, int col)  // 좌상단
{
    if (len == 3)
    {
        draw(row, col);
        return;  // 리턴의 유무 중요 !!!
    }
        
    square(len / 3, row, col);  // 첫 번째 정사각형
    square(len / 3, row, col + len / 3);  // 두 번째 정사각형
    square(len / 3, row, col + 2 * len / 3);  // 세 번째 정사각형
    square(len / 3, row + len / 3, col);  // 네 번째 정사각형
    // 가운데에 있는 다섯 번째 정사각형은 그리지 않는다.
    square(len / 3, row + len / 3, col + 2 * len / 3);  // 여섯 번째 정사각형
    square(len / 3, row + 2 * len / 3, col);  // 일곱 번째 정사각형
    square(len / 3, row + 2 * len / 3, col + len / 3);  // 여덟 번째 정사각형
    square(len / 3, row + 2 * len / 3, col + 2 * len / 3);  // 아홉 번째 정사각형
}

int main()
{
    int N;
    cin >> N;
    
    // 별찍기 전에 미리 전체 배열에 공백 넣어주기 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = ' ';
        }
    }
    
    square(N, 0, 0);  // 별 찍기. 가~장 큰 사각형의 좌상단부터 넘기기
    
    // 출력 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}
