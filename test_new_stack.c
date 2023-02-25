#include <stdio.h>

typedef struct t_list
{
    int content;
    struct t_list *prev;
    struct t_list *next;
} t_list;

t_list *new_stack(int (*int_argv)[1]);

int main(void)
{
    t_list *result;
    int num[4][1] = {
        {1},{2},{3},{4}
    };
    result = new_stack(num);
    while (result != NULL)
    {
        printf("%d\n", result->content);
        result = result->next;
    }
    return (0);
}