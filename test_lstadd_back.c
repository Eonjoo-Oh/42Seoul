#include <stdio.h>
#include <stdlib.h>

typedef struct t_list
{
    struct t_list *prev;
    struct t_list *next;
    int content;
} t_list;

typedef struct s_list
{
    struct t_list *head;
} s_list;

t_list *make_lst(int data);
void lstadd_back(s_list *lst, int data);

int main(void)
{
    int i = 0;
    int arr[5] = {1, 2, 3, 4, 5};
    s_list *result;
    t_list *tmp;

    result = NULL;
    while (i < 5)
    {
        lstadd_back(result, arr[i]);
        i++;
    }
    tmp = result->head;
    while (tmp->next != result->head)
    {
        printf("%d", tmp->content);
        tmp = tmp->next;
    }
    printf("%d", tmp->content);
}
/*
int main(void)
{
    int i = 0;
    int arr[5] = {1, 2, 3, 4, 5};
    s_list *result;
    t_list *temp;
    t_list *node;

    result = NULL;
    while (i < 5)
    {
        node = make_lst(arr[i]);
        lstadd_back(&result, node);
        i++;
    }
    temp = result->head;
    while (temp->next != result->head)
    {
        printf("%d\n", temp->content);
        temp = temp->next;
    }
    return (0);
}
*/

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