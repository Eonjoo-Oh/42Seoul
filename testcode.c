#include <stdio.h>

int	ft_printf(const char *arg, ...);

int main(void)
{
    int res;
    int res2;
    int a = 3;

    res = ft_printf("abcd %s hig%d\n", "efg", 345);
    res2 = printf("abcd %s hig%d\n", "efg", 345);
    ft_printf("c: %c\n", 'a');
    ft_printf("s: %s\n", "abc");
    ft_printf("d: %d\n", 2147483647);
    ft_printf("p: %p\n", &a);
    ft_printf("i: %i\n", -123);
    ft_printf("u: %u\n", -123);
    ft_printf("%%: %%\n");
    ft_printf("x: %x\n", 'a');
    ft_printf("X: %X\n", 'A');
    ft_printf("return value: %d\n", res);
    ft_printf("origin return value: %d\n", res2);
    return (0);
}