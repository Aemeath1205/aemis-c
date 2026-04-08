#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int a;
    int b;
    int c;
    scanf("ÊäÈëabcµÄÖµ:%d%d%d", &a, &b, &c);
    if (a + b > c && a + c > b && b + c > a)
    {
        if (a == b || a == c || b == c)
        {
            if (a == b && a == c)
                printf("Equilateral triangle!");
            else
                printf("Isosceles triangle!");
        }
        else
            printf("Ordinary triangle!");
    }
    else
        printf("Not a triangle!");

    return 0;
}