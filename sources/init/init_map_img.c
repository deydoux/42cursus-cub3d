/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:17:01 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/29 14:37:10 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

bool	init_map_img(t_cub *cub)
{
	size_t	x;
	size_t	y;

	if (new_img(cub->map.h * MAP_CUB_SIZE, cub->map.w * MAP_CUB_SIZE, cub->mlx,
			&cub->map.img))
		return (true);
	fill_img(MAP_COLOR_WALL, cub->map.img);
	y = 0;
	while (y < cub->map.h)
	{
		x = 0;
		while (cub->map.buf[y][x])
		{
			if (cub->map.buf[y][x] == 'd')
				draw_map_square(x * MAP_CUB_SIZE, y * MAP_CUB_SIZE,
					MAP_COLOR_DOOR, cub->map.img);
			else if (cub->map.buf[y][x] != ' ' && cub->map.buf[y][x] != '1')
				draw_map_square(x * MAP_CUB_SIZE, y * MAP_CUB_SIZE,
					MAP_COLOR_BG, cub->map.img);
			x++;
		}
		y++;
	}
	return (false);
}
