/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonjoo <eonjoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:52:36 by eoh               #+#    #+#             */
/*   Updated: 2023/03/05 19:02:37 by eonjoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

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

// parsing
void push_swap(int argc, char **argv);
t_list *first_stack(char **argv);
void lstadd_back(t_list *lst, t_node *new_node);
t_node *make_lst(int data);
int check_range(long long n);
long long long_atoi(char *nptr);
int is_digit_sp(char *str);
char **ft_split(char const *s);
int check_dup(t_node *node);

// commands
void sa(t_list *stack_a);
void sb(t_list *stack_b);
void ss(t_list *stack_a, t_list *stack_b);

#endif