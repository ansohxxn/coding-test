#include <stdio.h>

int main()
{
    char c;
    scanf("%c", &c);
    
    char c2 = 'a';
    while(c2 <= c)
    {
        printf("%c ", c2++);
    }
}
