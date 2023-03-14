/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:52:36 by eoh               #+#    #+#             */
/*   Updated: 2023/03/14 19:39:20 by eoh              ###   ########.fr       */
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
    int tries;
} t_node;

typedef struct s_list
{
    t_node *head;
} t_list;

// check_error
int check_error(int argc, char **argv);
int check_dup(t_list *stack);
int check_argc(int argc);
int check_range(long long n);

// parsing
void push_swap(int argc, char **argv);
t_list *first_stack(char **argv);
void lstadd_back(t_list *lst, t_node *new_node);
t_node *make_lst(int data);
long long long_atoi(char *nptr);
int is_digit_sp(char *str);
char **ft_split(char const *s);
t_list *make_stack(void);

// commands
void sa(t_list *stack_a);
void sb(t_list *stack_b);
void ss(t_list *stack_a, t_list *stack_b);
void pa(t_list *stack_a, t_list *stack_b);
void pb(t_list *stack_a, t_list *stack_b);
void ra(t_list *stack_a);
void rb(t_list *stack_b);
void rr(t_list *stack_a, t_list *stack_b);
void rra(t_list *stack_a);
void rrb(t_list *stack_b);
void rrr(t_list *stack_a, t_list *stack_b);

//sort
int count_node(t_list *stack);
int check_sorted(t_list *stack);
void sort_few(t_list *stack_a, int size);

#endif

/*
6
3
2
1
5
7
0

7/2 = 3

*/