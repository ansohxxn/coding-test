#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++)
    {
        i % 3 == 0 ? printf("X ") : printf("%d ", i);
    }
}
