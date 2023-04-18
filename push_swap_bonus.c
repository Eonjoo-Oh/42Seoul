/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:10:07 by eoh               #+#    #+#             */
/*   Updated: 2023/04/18 20:47:11 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*checker_error(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc < 2)
		return (0);
	if (check_char(argv) == -1)
		exit(1);
	stack_a = first_stack(argv);
	if (!stack_a)
		return (0);
	if (check_dup(stack_a) == -1)
	{
		write(2, "Error\n", 6);
		free(stack_a);
		exit(1);
	}
	return (stack_a);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n) && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

int	checker_buf(char *buf, t_list *stack_a, t_list *stack_b)
{
	if (ft_strncmp(buf, "pa\n", 3) == 0)
		pa_bonus(stack_a, stack_b);
	else if (ft_strncmp(buf, "pb\n", 3) == 0)
		pb_bonus(stack_a, stack_b);
	else if (ft_strncmp(buf, "sa\n", 3) == 0)
		sa_bonus(stack_a);
	else if (ft_strncmp(buf, "sb\n", 3) == 0)
		sb_bonus(stack_b);
	else if (ft_strncmp(buf, "ss\n", 3) == 0)
		ss_bonus(stack_a, stack_b);
	else if (ft_strncmp(buf, "ra\n", 3) == 0)
		ra_bonus(stack_a);
	else if (ft_strncmp(buf, "rb\n", 3) == 0)
		rb_bonus(stack_b);
	else if (ft_strncmp(buf, "rr\n", 3) == 0)
		rr_bonus(stack_a, stack_b);
	else if (ft_strncmp(buf, "rra\n", 3) == 0)
		rra_bonus(stack_a);
	else if (ft_strncmp(buf, "rrb\n", 3) == 0)
		rrb_bonus(stack_b);
	else if (ft_strncmp(buf, "rrr\n", 3) == 0)
		rrr_bonus(stack_a, stack_b);
	else
		return (-1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*buf;

	stack_a = checker_error(argc, argv);
	if (!stack_a)
		return (0);
	stack_b = make_stack();
	buf = get_next_line(0);
	while (buf)
	{
		if (checker_buf(buf, stack_a, stack_b) == -1)
		{
			write(1, "Error\n", 6);
			free(buf);
			return (0);
		}
		free(buf);
		buf = get_next_line(0);
	}
	if (check_sorted(stack_a) == -1 && stack_b->head == 0)
		write(1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	return (0);
}
