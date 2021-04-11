#include <stdio.h>

int main()
{
    char n;
    scanf("%c", &n);

    for(int i = 1; i < 16; i++)
        printf("%X*%X=%X\n", n - 55, i, (n - 55) * i);
}
