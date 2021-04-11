#include <stdio.h>

int main()
{
    int arr[101][101] = { 0 };
    
    int row, col;
    scanf("%d %d", &row, &col);
    
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++)
    {
        int len, dir, x, y;
        scanf("%d %d %d %d", &len, &dir, &x, &y);
        
        if (dir == 0)
        {
            for(int j = y; j < y + len; j++)
                arr[x][j] = 1;
        }
        else if (dir == 1)
        {
            for(int j = x; j < x + len; j++)
                arr[j][y] = 1;
        }
    }
    
    for(int i = 1; i <= row; i++)
    {
        for(int j = 1; j <= col; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
        
}
