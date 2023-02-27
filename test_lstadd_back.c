#include <stdio.h>
#include <stdlib.h>

typedef struct t_list
{
    int content;
    struct t_list *prev;
    struct t_list *next;
} t_list;

t_list *make_lst(int data);
void lstadd_back(t_list **lst, t_list *new_node);

int main(void)
{
    int i = 0;
    int arr[5] = {1, 2, 3, 4, 5};
    t_list *result;
    t_list *node;

    result = NULL;
    while (i < 5)
    {
        node = make_lst(arr[i]);
        lstadd_back(&result, node);
        i++;
    }
    while (result->next != NULL)
    {
        printf("%d\n", result->content);
        result = result->next;
    }
    printf("%d\n", result->content);
    return (0);
}


/*
int main()
{
    t_list *lst = NULL;

    lstadd_back(&lst, make_lst(1));
    lstadd_back(&lst, make_lst(2));
    lstadd_back(&lst, make_lst(3));
    lstadd_back(&lst, make_lst(4));
    lstadd_back(&lst, make_lst(5));

    t_list *tmp = lst;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->content);
        tmp = tmp->next;
    }

    return 0;
}
*/