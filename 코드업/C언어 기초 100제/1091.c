#include <stdio.h>

int main()
{
    long long a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    
    int count = 1;
    long long i;
    for(i = a; count < d; )
    {
        count++;
        i *= b;
        i += c;
    }
    printf("%lld", i);
}
