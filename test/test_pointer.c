#include <stdio.h>

int main(void)
{
    int a = 4;
    int *b;
    int **c;

    b =  &a;
    c = &b;
    printf("a: %d\n", a);
    printf("*b: %d\n", *b);
    printf("b: %p\n", b);
    printf("**c: %d\n", **c);
    printf("*c: %p\n", *c);
    printf("c: %p\n", c);
}