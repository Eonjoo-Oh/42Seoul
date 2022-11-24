/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonjoo <eonjoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:23:56 by eoh               #+#    #+#             */
/*   Updated: 2022/11/25 00:31:06 by eonjoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst == 0)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free (*lst);
		(*lst) = tmp;
	}
	(*lst) = 0;
}
