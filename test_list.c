#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    typedef struct t_list
    {
        int content;
        struct t_list *prev;
        struct t_list *next;
    } t_list;

    t_list *new;
    new = (t_list *)malloc(sizeof(t_list));
    if(!new)
        return (0);
    new->content = 1;
    
    printf("%d\n", new->content);
}