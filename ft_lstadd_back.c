/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:08:52 by eoh               #+#    #+#             */
/*   Updated: 2022/11/23 20:54:00 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst == 0 || new == 0)
		return ;
	if (*lst == 0)
		*lst = new;
	temp = *lst;
	while ((*lst)->next != 0)
	{
		*lst = (*lst)->next;
	}
	(*lst)->next = new;
	new->next = NULL;
	*lst = temp;
}
