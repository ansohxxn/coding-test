#include <stdio.h>
int main()
{
    int i, j, k;
    int a[10000] = {0};
    int min = 24;
     
    scanf("%d", &k);
    for(i=0; i<k; i++)
    {
        scanf("%d", &a[i]);
        if(min > a[i])
            min  =a[i];
    }
    printf("%d", min);
    return 0;
}
