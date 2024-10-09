/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:17:01 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/09 15:22:06 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	draw_map_wall(size_t x, size_t y, t_img img)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < CUB_SIZE / 2)
	{
		i = 0;
		while (i < CUB_SIZE / 2)
			img.buf[(y + j) * img.w_size + x + i++].raw = 0xffffffff;
		j++;
	}
}

bool	init_map_img(t_cub *cub)
{
	size_t	x;
	size_t	y;

	if (new_img(CUB_SIZE * cub->map.h, CUB_SIZE * cub->map.w, cub->mlx,
			&cub->map.img))
		return (true);
	y = 0;
	while (y < cub->map.h)
	{
		x = 0;
		while (x < cub->map.w)
		{
			if (cub->map.buf[y][x] == '1')
				draw_map_wall(x * CUB_SIZE / 2, y * CUB_SIZE / 2,
					cub->map.img);
			x++;
		}
		y++;
	}
	return (false);
}
