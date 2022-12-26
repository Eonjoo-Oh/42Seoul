#include <stdio.h>

struct t_list
{
    struct t_list next;
    void *content;
}

int
main(void)
{
    struct t_list new_list;
    new_list->next = 0;
    new_list->content = "abc";

    ft_lstadd_back(new_list, )
}