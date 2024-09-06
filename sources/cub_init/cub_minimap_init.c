/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_minimap_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:17:01 by deydoux           #+#    #+#             */
/*   Updated: 2024/09/06 21:55:53 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_init.h"

static void	minimap_draw_wall(size_t x, size_t y, t_cub_img img)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < CUB_SIZE)
	{
		i = 0;
		while (i < CUB_SIZE)
			img.buf[(y + j) * img.w_size + x + i++] = 0xffffffff;
		j++;
	}
}

bool	cub_minimap_init(t_cub *cub)
{
	size_t	x;
	size_t	y;

	if (cub_new_img(CUB_SIZE * cub->map.h, CUB_SIZE * cub->map.w, cub->mlx,
		&cub->map.img))
		return (true);
	y = 0;
	while (y < cub->map.h)
	{
		x = 0;
		while (x < cub->map.w)
		{
			if (cub->map.buf[y][x] == '1')
				minimap_draw_wall(x * CUB_SIZE, y * CUB_SIZE, cub->map.img);
			x++;
		}
		y++;
	}
	return (false);
}
