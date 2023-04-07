/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:52:36 by eoh               #+#    #+#             */
/*   Updated: 2023/04/07 21:24:24 by eoh              ###   ########.fr       */
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
	int top;
	int tries;
} t_node;

typedef struct s_list
{
    t_node *head;
} t_list;

// check_error
int	check_error(t_list *stack);
int check_sorted(t_list *stack);
int check_dup(t_list *stack);
int check_char(char **argv);
int check_range(long long n);
int	check_splited(char *str);

// parsing
void push_swap(int argc, char **argv);
t_list *first_stack(char **argv);
void lstadd_back(t_list *lst, t_node *new_node);
t_node *make_lst(int data);
long long long_atoi(char *nptr);
int is_digit_sp(char **str);
int is_white_space(char str);
int is_sign(char *str);
char **ft_split(char const *s);
t_list *make_stack(void);
char	**free_result(char **s);

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

//make
t_list *make_stack(void);
t_node *make_lst(int data);
int *make_arr(t_list *stack_a, int size);
int make_dif(t_node *a_node, t_node *b_node);

//count
int count_node(t_list *stack);
void count_to_top(t_list *stack_b);
void count_to_a(t_list *stack_a, t_list *stack_b);
void	do_count_to_a(int i, t_list *stack_a, t_list *stack_b, t_node *node);

//find
t_node *find_close(t_list *stack_a, t_node *b_node);
t_node *find_min_tries(t_list *stack_b);
t_node *find_min_node(t_list *stack);
int find_index(t_list *stack, t_node *node);

//pivot
void sort_arr(int *arr, int size);
int find_to_push(t_list *stack_a, int pivot);
void push_to_b(t_list *stack_a, t_list *stack_b);

//sort
void do_both(t_list *stack_a, t_list *stack_b, t_node *min);
void do_top(t_list *stack_b, t_node *min);
void do_a(t_list *stack_a, t_list *stack_b, t_node *min);
void do_last(t_list *stack_a);
void sort(t_list *stack_a, t_list *stack_b);
void sort_few(t_list *stack_a, int size);


#endif