#include <stdio.h>
#include <stdlib.h>
typedef struct t_list
    {
        int content;
        struct t_list *prev;
        struct t_list *next;
    } t_list;

t_list *make_lst(void);

int main(void)
{
    t_list *test;

    test = make_lst();
    printf("%p\n", &test);
    printf("%d\n", test->content);

    return (0);
}