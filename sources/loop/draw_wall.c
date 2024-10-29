/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:04:38 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/29 12:36:14 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

static int	init_draw_wall(t_img *spr, t_ray ray, t_cub cub)
{
	if (ray.d == ray.dy)
	{
		if (ray.vec.dy < 0)
		{
			*spr = cub.spr.s[cub.i / SPR_STEP % cub.spr.s_size];
			return ((ray.pos.x - (int)ray.pos.x) * spr->w);
		}
		*spr = cub.spr.n[cub.i / SPR_STEP % cub.spr.n_size];
		return (spr->w - (ray.pos.x - (int)ray.pos.x) * spr->w);
	}
	if (ray.vec.dx > 0)
	{
		*spr = cub.spr.e[cub.i / SPR_STEP % cub.spr.e_size];
		return ((ray.pos.y - (int)ray.pos.y) * spr->w);
	}
	*spr = cub.spr.w[cub.i / SPR_STEP % cub.spr.w_size];
	return (spr->w - (ray.pos.y - (int)ray.pos.y) * spr->w);
}

void	draw_wall(size_t frame_x, int wall_h, t_ray ray, t_cub cub)
{
	int		frame_y;
	int		img_h;
	int		img_x;
	t_img	spr;

	if (wall_h < 0)
		wall_h = INT_MAX;
	img_x = init_draw_wall(&spr, ray, cub);
	frame_y = (WIN_H - wall_h) / 2;
	img_h = frame_y * -1 * (frame_y < 0);
	frame_x += (frame_y + img_h) * cub.frame.w_size;
	while (img_h < wall_h && frame_y + img_h < WIN_H)
	{
		cub.frame.buf[frame_x]
			= *read_img(spr, img_x, (double)img_h / wall_h * spr.h);
		img_h++;
		frame_x += cub.frame.w_size;
	}
}
