/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:38:22 by eoh               #+#    #+#             */
/*   Updated: 2022/11/21 13:37:26 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;

	new = (t_list *)(malloc)(sizeof(t_list));
	if (new == 0)
		return (0);
	while (lst != 0)
	{
		f(lst->content);
		new = lst;
		lst = lst->next;
	}
	return (new);
}
//del과 free는 언제 쓰이는 것?