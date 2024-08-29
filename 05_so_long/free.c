/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 03:20:03 by eoh               #+#    #+#             */
/*   Updated: 2023/06/24 11:45:28 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map == 0)
		return ;
	while (map->form[i])
	{
		free(map->form[i]);
		i++;
	}
	free(map->form);
}

void	free_check_element(t_map *map, char *msg)
{
	free_map(map);
	error_msg(msg);
}
