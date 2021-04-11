#include <stdio.h>

int main()
{
    int end;
    scanf("%d", &end);
    
    int sum = 0;
    int i = 0;
    while(sum < end)
    {
        i++;
        sum += i;
    }
    printf("%d", i);
}
