/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:26:38 by mapale            #+#    #+#             */
/*   Updated: 2024/09/28 11:12:58 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parse.h"

void	free_map_and_exit(char* msg, t_map *map)
{
	int	i;

	i = 0;
	while ( i < map->map_h)
	{
		free(map->map[i]);
		i++;
	}
	perror(msg);
	exit(1);
}