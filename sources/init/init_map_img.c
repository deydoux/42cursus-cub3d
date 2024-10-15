/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:17:01 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/15 11:16:54 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	draw_map_square(size_t x, size_t y, uint32_t raw_color, t_img img)
{
	size_t	sq_x;
	size_t	sq_y;

	sq_y = 0;
	while (sq_y < MAP_CUB_SIZE)
	{
		sq_x = 0;
		while (sq_x < MAP_CUB_SIZE)
			read_img(img, x + sq_x++, y + sq_y)->raw = raw_color;
		sq_y++;
	}
}

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
			if (cub->map.buf[y][x] != ' ' && cub->map.buf[y][x] != '1')
				draw_map_square(x * MAP_CUB_SIZE, y * MAP_CUB_SIZE,
					MAP_COLOR_BG, cub->map.img);
			x++;
		}
		y++;
	}
	return (false);
}
