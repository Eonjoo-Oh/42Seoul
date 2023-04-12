/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:49:21 by eoh               #+#    #+#             */
/*   Updated: 2023/04/12 21:33:56 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PUSH_SWAP_H
# define BONUS_PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "gnl/get_next_line.h"

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

typedef struct s_cmd
{
	struct s_cmd *next;
	char *cmd;
} t_cmd;

t_list	*checker_error(int argc, char **argv);
int		check_char(char **argv);
t_list	*first_stack(char **argv);
void	check_only_null(const char *s, t_list *stack);
char	**ft_split(const char *s);
size_t	cnt_word(const char *s);
int		is_white_space(char str);
char	**free_result(char **s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	free_splited(char **splited, t_list *stack);
void	add_stack(char **splited, t_list *stack);
int		check_splited(char *str);
int		check_range(long long n);
t_node	*make_lst(int data);
long long	long_atoi(char *ptr);
void	lstadd_back(t_list *lst, t_node *new_node);
int		check_dup(t_list *stack);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		checker_buf(char *buf, t_list *stack_a, t_list *stack_b);
int		make_stack();
int		check_sorted(t_list *stack);
void	pa_less_bonus(t_list *stack_a, t_list *stack_b);
void	pb_less_bonus(t_list *stack_a, t_list *stack_b);
void	pa_bonus(t_list *stack_a, t_list *stack_b);
void	pb_bonus(t_list *stack_a, t_list *stack_b);
void	do_sa_bonus(t_list *stack_a);
void	do_sb_bonus(t_list *stack_b);
void	sa_bonus(t_list *stack_a);
void	sb_bonus(t_list *stack_b);
void	ss_bonus(t_list *stack_a, t_list *stack_b);
void	ra_bonus(t_list *stack_a);
void	rb_bonus(t_list *stack_b);
void	rr_bonus(t_list *stack_a, t_list *stack_b);
void	rra_bonus(t_list *stack_a);
void	rrb_bonus(t_list *stack_b);
void	rrr_bonus(t_list *stack_a, t_list *stack_b);








#endif