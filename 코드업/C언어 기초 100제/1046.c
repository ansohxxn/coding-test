#include <stdio.h>

int main()
{
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    printf("%d\n", a + b + c);
    printf("%.1f", (float)(a + b + c) / 3);
}
