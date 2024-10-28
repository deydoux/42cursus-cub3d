/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DELETE.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapale <mapale@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:20:20 by mapale            #+#    #+#             */
/*   Updated: 2024/10/23 16:41:20 by mapale           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

/* void	print_map(t_map *map)
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
} */

int	a_text(t_p_path *t)
{
	int	i;

	i = 0;
	printf("\n");
	while (i < t->size)
	{
		printf(" %d : -%s-\n", i, t->pths[i]);
		i++;
	}
	return (t->size);
}

void	print_textures(t_p_map *map)
{
	printf("LES TEXTURES : \n\
		NO: %d\nSO: %d\nWE: %d\nEA: %d\nF: %s\nC: %s\n", \
		a_text(&map->txtrs_pths.n_path), \
		a_text(&map->txtrs_pths.s_path), \
		a_text(&map->txtrs_pths.w_path), \
		a_text(&map->txtrs_pths.ea_path), \
		map->txtrs_pths.f_color, \
		map->txtrs_pths.c_color);
	printf("----------------------------------------------\n\n");
}
