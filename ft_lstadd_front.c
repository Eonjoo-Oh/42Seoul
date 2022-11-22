/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:50:51 by eoh               #+#    #+#             */
/*   Updated: 2022/11/22 14:42:06 by eoh              ###   ########.fr       */
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
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
}
