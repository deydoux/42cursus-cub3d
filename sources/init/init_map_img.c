/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:17:01 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/14 00:55:45 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	draw_map_wall(size_t x, size_t y, t_img img)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < MAP_CUB_SIZE)
	{
		i = 0;
		while (i < MAP_CUB_SIZE)
			img.buf[(y + j) * img.w_size + x + i++].raw = 0xffffffff;
		j++;
	}
}

bool	init_map_img(t_cub *cub)
{
	size_t	x;
	size_t	y;

	if (new_img(cub->map.h * MAP_CUB_SIZE, cub->map.w * MAP_CUB_SIZE, cub->mlx,
			&cub->map.img))
		return (true);
	y = 0;
	while (y < cub->map.h)
	{
		x = 0;
		while (x < cub->map.w)
		{
			if (cub->map.buf[y][x] == '1')
				draw_map_wall(x * MAP_CUB_SIZE, y * MAP_CUB_SIZE, cub->map.img);
			x++;
		}
		y++;
	}
	return (false);
}
