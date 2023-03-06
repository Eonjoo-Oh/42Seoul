#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
    struct s_node *prev;
    struct s_node *next;
    int content;
} t_node;

typedef struct s_list
{
    t_node *head;
} t_list;

t_node *make_lst(int data);
void lstadd_back(t_list *lst, t_node *new_node);

int main(void)
{
    int i = 0;
    int arr[5] = {1, 2, 3, 4, 5};
    t_list *result;
    t_node *temp;
    t_node *node;

    result = (t_list *)malloc(sizeof(t_list));
    if (!result)
        return (0);
    result->head = NULL;
    while (i < 5)
    {
        node = make_lst(arr[i]);
        lstadd_back(result, node);
        i++;
    }
    temp = result->head;
    while (temp->next != result->head)
    {
        printf("%d\n", temp->content);
        temp = temp->next;
    }
    printf("%d\n", temp->content);
    return (0);
}
