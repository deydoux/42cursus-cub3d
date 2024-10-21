/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DELETE.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:20:20 by mapale            #+#    #+#             */
/*   Updated: 2024/10/17 14:09:49 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	printf("MAP :\n");
	while (i < map->map_h)
	{
		printf("-%s-\n", map->map[i]);
		i++;
	}
	printf("\n--------------------------------------------------------------------\n\n");
}

void	print_textures(t_map *map)
{
	printf("LES TEXTURES : \n\
NO: %s\nSO: %s\nWE: %s\nEA: %s\nF: %s\nC: %s\n",\
map->txtrs_paths.n_path,\
map->txtrs_paths.s_path,\
map->txtrs_paths.w_path,\
map->txtrs_paths.ea_path,\
map->txtrs_paths.f_color,\
map->txtrs_paths.c_color);
	printf("--------------------------------------------------------------------\n\n");
}
