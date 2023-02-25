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
    int i = 1;
    t_list *first;
    t_list *new;
    t_list *result;

    int int_argv[4][1] = {
        {1},{2},{3},{4}
    };

    first = (t_list *)malloc(sizeof(t_list));
	if (!first)
		return (0);
	first->content = int_argv[0][0];
	first->prev = NULL;
	first->next = NULL;
    result = first;
    while (int_argv[i++])
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (!new)
		return (0);
		new->content = int_argv[i][0];
		new->prev = first;
		new->next = NULL;
		first = first->next;
	}

    while (result != NULL)
    {
        printf("%d\n", result->content);
        result = result->next;
    }

    return (0);
}