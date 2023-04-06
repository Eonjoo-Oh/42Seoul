#include <stdio.h>
#include <stdlib.h>
typedef struct t_list
    {
        struct t_list *prev;
        struct t_list *next;
        int content;
    } t_list;

t_list *make_lst(int data);

int main(void)
{
    t_list *test;

    test = make_lst(32);
    printf("%p\n", &test);
    printf("%d\n", test->content);

    return (0);
}