/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:52:36 by eoh               #+#    #+#             */
/*   Updated: 2023/04/24 12:22:18 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				content;
	int				top;
	int				tries;
}	t_node;

typedef struct s_list
{
	t_node	*head;
}	t_list;

// check_error
int			check_range(long long n);
int			check_dup(t_list *stack);
int			check_sorted(t_list *stack);
int			check_char(char **argv);
int			check_error(t_list *stack);
void		check_only_space(char *s, t_list *stack);

// find
t_node		*find_close(t_list *stack_a, t_node *b_node);
int			get_abs(int a);
t_node		*find_min_tries(t_list *stack_b);
t_node		*find_min_node(t_list *stack);
int			find_index(t_list *stack, t_node *node);

// first_stack
void		free_splited(char **splited, t_list *stack);
void		add_stack(char **splited, t_list *stack);
t_list		*first_stack(char **argv);

// utils
int			check_splited(char *str);
char		**free_result(char **s);
void		check_only_null(char const *s, t_list *stack);
char		**ft_split(char const *s);
int			is_digit_sp(char **str);
int			is_white_space(char str);
int			is_sign(char *str);
t_list		*make_stack(void);
t_node		*make_lst(int data);
int			*make_arr(t_list *stack_a, int size);
int			make_dif(t_node *a_node, t_node *b_node);
int			count_node(t_list *stack);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
long long	long_atoi(char *nptr);
void		lstadd_back(t_list *lst, t_node *new_node);
void		free_stack(t_list *stack);

// pivot
void		sort_arr(int *arr, int size);
int			find_to_push(t_list *stack_a, int pivot);
void		do_push_to_b(int st, int nd, t_list *stack_a, t_list *stack_b);
void		push_to_b(t_list *stack_a, t_list *stack_b);
void		count_to_top(t_list *stack_b);
void		count_to_a(t_list *stack_a, t_list *stack_b);

// commands
void		pa(t_list *stack_a, t_list *stack_b);
void		pb(t_list *stack_a, t_list *stack_b);
void		rra(t_list *stack_a);
void		rrb(t_list *stack_b);
void		rrr(t_list *stack_a, t_list *stack_b);
void		ra(t_list *stack_a);
void		rb(t_list *stack_b);
void		rr(t_list *stack_a, t_list *stack_b);
void		sa(t_list *stack_a);
void		sb(t_list *stack_b);
void		ss(t_list *stack_a, t_list *stack_b);

// sort
void		do_both(t_list *stack_a, t_list *stack_b, t_node *min);
void		do_top(t_list *stack_b, t_node *min);
void		do_else_a(t_list *stack_a, t_list *stack_b, t_node *min);
void		do_a(t_list *stack_a, t_list *stack_b, t_node *min);
void		do_last(t_list *stack_a);
int			find_min(t_list *stack_a);
int			find_max(t_list *stack_a);
void		do_sort_three(int min, int max, t_list *stack_a);
void		sort_three(t_list *stack_a);
void		sort_few(t_list *stack_a, int size);
void		sort_else(t_list *stack_a, t_list *stack_b, t_node *min);
void		sort(t_list *stack_a, t_list *stack_b);
void		push_swap(t_list *stack_a, t_list *stack_b);

//free
void		free_a(t_list *stack_a);
void		free_b(t_list *stack_b);
void		free_all(t_list *stack_a, t_list *stack_b);

#endif