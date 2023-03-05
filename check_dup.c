#include "push_swap.h"

int check_dup(t_node *node)
{
    int *plus;
    int *minus;
    t_node *temp;
    long long i;
    int n;

    plus = (int *)malloc(sizeof(int) * 2147483647);
    if (!plus)
        return (0);
    minus = (int *)malloc(sizeof(int) * 2147483647);
    if (!minus)
        return (0);
    i = 0;
    while (i < 2147483647)
    {
        plus[i] = 0;
        minus[i] = 0;
        i++;
    }
    temp = node;
    temp->prev->next = NULL;
    while (temp != NULL)
    {
        n = temp->content;
        if (n < 0)
        {
            n = (n + 1) * -1;
            if (minus[n] == 0)
                minus[n]++;
            else
                return (-1);
        }
        else if (n >= 0)
        {
            if (plus[n] == 0)
                plus[n]++;
            else
                return (-1);
        }
        temp = temp->next;
    }
    node->prev->next = node;
    free(plus);
    free(minus);
    return (1);
}