/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:39:01 by eoh               #+#    #+#             */
/*   Updated: 2023/03/14 19:32:51 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void push_swap(int argc, char **argv)
{
    t_list  *stack_a;
    t_list  *stack_b;

    if (check_error(argc, argv) == -1)
        exit(1);
    stack_a = first_stack(argv);
    if (count_node(stack_a) < 4)
    {
        sort_few(stack_a, count_node(stack_a));
        return ;
    }
    else
    {
        stack_b = make_stack();
        sort(stack_a, stack_b, count_node(stack_a));
    }
    // test_makestack;
    t_node  *node;
    node = stack_a->head;
    while (node->next != stack_a->head)
    {
        printf("%d\n", node->content);
        node = node->next;
    }
    printf("%d\n", node->content);
    printf("size: %d\n", count_node(stack_a));
}
/*
void push_swap(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    t_node *node;

    if (argc <= 2)
        exit(1);
    stack_a = first_stack(argv);
    if (stack_a == 0)
    {
        write (2, "Error\n", 6);
        exit(1);
    }
    node = stack_a->head;

    if ((check_dup(stack_a) == -1))
    {
        write(2, "Error\n", 6);
        exit(1);
    }
    if ((check_sorted(stack_a) == -1))
        exit(1);
    if (count_node(stack_a) < 4)
    {
        sort_few(stack_a, count_node(stack_a));
        return ;
    }
    else
    {
        stack_b = (t_list *)malloc(sizeof(t_list));
        if (!stack_b)
            return ;
        //sort(stack_a, stack_b, count_node(stack_a));
    }

    // test_makestack;
    while (node->next != stack_a->head)
    {
        printf("%d\n", node->content);
        node = node->next;
    }
    printf("%d\n", node->content);
    printf("size: %d\n", count_node(stack_a));
}
*/
int main(int argc, char ** argv)
{
    push_swap(argc, argv);
    //system ("leaks a.out");
    return (0);
}