#include <stdio.h>

int main()
{
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    
    int count = 1;
    long long i;
    for(i = a; count < c; i *= b)
        count++;
    
    printf("%lld", i);
}
