/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:38:22 by eoh               #+#    #+#             */
/*   Updated: 2022/11/25 15:19:30 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*result;
	void	*new_content;

	result = NULL;
	while (lst != 0)
	{
		new_content = f(lst->content);
		new = ft_lstnew(new_content);
		if (new == 0)
		{
			del(new_content);
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, new);
		lst = lst -> next;
	}
	return (result);
}
