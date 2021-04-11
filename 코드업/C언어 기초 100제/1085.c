#include <stdio.h>

int main()
{
    float h, b, c, s;
    scanf("%f %f %f %f", &h, &b, &c, &s);
    
    printf("%.1f MB", h * ((b * c * s) / (1024 * 1024 * 8)));
}
