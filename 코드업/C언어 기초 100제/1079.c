#include <stdio.h>

int main()
{
    char c;
    while(1)
    {
        scanf("%c", &c);
        if (c == ' ') continue;
        printf("%c\n", c);
        if (c == 'q') break;
    }
}
