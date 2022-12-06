#include <stdio.h>

int main(void)
{
    int a;
	a = printf("abc %s hijk\n", "defg");
	printf("%d\n", a);
    printf("%d\n", 3);
    printf("abc %s hijk\n", "defg");
    printf("123 %d 789 abc %s ghi\n", 456, "def");
}
