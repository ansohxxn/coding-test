#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    int count = 1;
    int i;
    for(i = a; count < c; i += b)
        count++;
    
    printf("%d", i);
}
