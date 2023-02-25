/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:03:07 by eoh               #+#    #+#             */
/*   Updated: 2023/02/21 19:19:12 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct t_list
{
    int content;
    struct t_list *prev;
    struct t_list *next;
} t_list;

t_list *new_stack(int (*int_argv)[1])
{
	t_list	*first;
	t_list	*new;
	t_list *result;
    int i;

    i = 1;
	first = (t_list *)malloc(sizeof(t_list));
	if (!first)
		return (0);
	first->content = int_argv[0][0];
	first->prev = NULL;
	first->next = NULL;
	result = first;
	while (int_argv[i][0])
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (!new)
		return (0);
		new->content = int_argv[i][0];
		new->prev = first;
		new->next = NULL;
		first->next = new;
		first = new;
		i++;
	}
	return (result);
}