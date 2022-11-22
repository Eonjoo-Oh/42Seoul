/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:50:51 by eoh               #+#    #+#             */
/*   Updated: 2022/11/22 17:25:40 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
typedef struct node
{
	struct node *next;
	void * content;
} t_list
*/
/*
lst
head -> next -> next -> NULL
new -> head -> next -> next -> NULL

lst
new -> NULL
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}
