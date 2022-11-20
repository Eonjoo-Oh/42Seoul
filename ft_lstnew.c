#include "libft.h"
#include <stdlib.h>

typedef struct node
{
    struct node *next;
    int content;
} t_list;
//이부분은 안써줘도 되나?
t_list *ft_lstnew(void *content)
{
    t_list *result;

    result = (t_list *)malloc(sizeof(t_list));
    if (result == 0)
        return (0);
    result->content = content;
    result->next = NULL;
    return (result);
}
