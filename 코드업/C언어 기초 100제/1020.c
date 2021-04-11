#include <stdio.h>

int main()
{
    char str[14];
    scanf("%s", str);
    for (int i = 0; i < 14; i++)
    {
        if (str[i] == '-') continue;
        printf("%c", str[i]);
    }
}
