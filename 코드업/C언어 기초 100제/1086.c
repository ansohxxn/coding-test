#include <stdio.h>

int main()
{
    float w, h, b;
    scanf("%f %f %f", &w, &h, &b);
    
    printf("%.2f MB", (w * h * b) / (1024 * 1024 * 8));
}
