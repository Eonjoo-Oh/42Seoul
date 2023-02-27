#include <stdio.h>
#include <stdlib.h>

typedef struct t_list
    {
        int content;
        struct t_list *prev;
        struct t_list *next;
    } t_list;

t_list *first_stack(char **argv);

int main(int argc, char **argv)
{
    t_list *test_lst;
    if (argc == 1)
        return 0;
    test_lst = first_stack(argv);
    while (test_lst != NULL)
    {
        printf("%d\n", test_lst->content);
        test_lst = test_lst->next;
    }
    return (0);
}