/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:10:07 by eoh               #+#    #+#             */
/*   Updated: 2023/04/10 22:09:18 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_push_swap.h"

//pipe통해서 받은 인자는 어떻게받지?
	//일단 인자가 들어오고 그 인자가 유효하면 표준입력으로 전환해서 명령어들을 받고 
	//그 명령어대로 스택을 돌려보고 정렬이 됐으면 ok 안됐으면 ko

t_list	*checker_error(int argc, char **argv)
{
	t_list *stack_a;

	if (argc <2)
		return 0;
	if (check_char(argv) == -1)
		exit(1);
	stack_a = first_stack(argv);
	if (!stack_a)
		return 0;
	if (check_dup(stack_a) == -1)
	{
		write(2, "Error\n", 6);
		free(stack_a);
		exit(1);
	}
	return (stack_a);
}

int	check_cmd(char *buf, t_list *stack, t_cmd *cmd)
{
	int	len;

	len = 0;
	while (buf[len])
	{
		len++;
	}
	if (len != 2 && len != 3)
	{
		free(stack);
		free(cmd);
		write(2, "Error\n", 6);
		exit(1);
	}
	if ((buf[0] == 'p' && (buf[1] == 'a' || buf[1] == 'b'))
		|| (buf[0] == 's' && (buf[1] == 'a' || buf[1] == 'b' || buf[1] == 's'))
		|| (buf[0] == 'r' && (buf[1] == 'a' || buf[1] == 'b' || buf[1] == 'r'))
		|| (buf[0] == 'r' && buf[1] == 'r' && (buf[2] == 'a' || buf[2] == 'b' || buf[2]== 'r')))
		return (1);
	else
	{
		free(stack);
		free(cmd);
		write(2, "Error\n", 6);
		exit(1);
	}
	return (-1);
}

t_cmd	*make_stack_cmd(char *buf)
{
	t_cmd	*stack_cmd;

	stack_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!stack_cmd)
		return (0);
	stack_cmd->cmd = buf;
	stack_cmd->next = NULL;
	return (stack_cmd);
}

void	add_buf(t_cmd **stack_cmd, t_cmd *new)
{
	t_cmd	*temp;
	t_cmd	*node;

	if (*stack_cmd == 0)
		*stack_cmd = new;
	else
	{
		temp = *stack_cmd;
		while ((*temp)->next != 0)
			(*temp) = (*temp)->next;
		(*temp)->next = new;
	}
}

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	checker_sort2(char *temp, t_list *stack_a, t_list *stack_b)
{	
	if (temp[0] == 'r' && temp[1] == 'r' && temp[2] == '\0')
			rr(stack_a, stack_b);
	else if (temp[0] == 'r' && temp[1] == 'r' && temp[2] == 'a')		
		rra(stack_a);
	else if (temp[0] == 'r' && temp[1] == 'r' && temp[2] == 'b')
		rrb(stack_b);
	else if (temp[0] == 'r' && temp[1] == 'r' && temp[2] == 'r')
		rrr(stack_a, stack_b);
}

void	checker_sort(t_cmd *stack_cmd, t_list *stack_a, t_list *stack_b)
{
	char	*temp;

	while (stack_cmd != 0)
	{
		temp = stack_cmd->cmd;
		if (ft_strlen(temp) == 2)
		{
			if (temp[0] == 'p' && temp[1] == 'a')
				pa(stack_a, stack_b);
			else if (temp[0] == 'p' && temp[1] == 'b')
				pb(stack_a, stack_b);
			else if (temp[0] == 's' && temp[1] == 'a')
				sa(stack_a);
			else if (temp[0] == 's' && temp[1] == 'b')
				sb(stack_b);
			else if (temp[0] == 's' && temp[1] == 's')
				ss(stack_a, stack_b);
			else if (temp[0] == 'r' && temp[1] == 'a')
				ra(stack_a);
			else if (temp[0] == 'r' && temp[1] == 'b')
				rb(stack_b);
		}
		else
			checker_sort2(temp, stack_a, stack_b);
		stack_cmd = stack_cmd->next;
	}
}

void	checker_sorted(t_list *stack_a, t_list *stack_b)
{
	if (stack_b->head != 0)
	{
		write(1, "Error\n", 6);
	}
	else if (stack_b->head == 0 && check_sorted(stack_a) == 1)
		write(1, "OK\n", 3);
	else if (stack_b->head == 0 && check_sorted(stack_a) == -1)
		write(1, "Error\n", 6);
	free(stack_a);
	free(stack_b);
}

void	checker(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_cmd	*stack_cmd;
	t_cmd	*temp;
	char	*buf;

	stack_a = checker_error(argc, argv);
	if (!stack_cmd)
		return ;
	while (1)
	{
		buf = get_next_line(1);
		check_cmd(buf, stack_a, stack_cmd);
		temp = make_stack_cmd(buf);
		add_buf(&stack_cmd, temp);
	}
	stack_b = make_stack();
	checker_sort(stack_cmd, stack_a, stack_b);
	free(stack_cmd);
	free(temp);
	checker_sorted(stack_a, stack_b);
}