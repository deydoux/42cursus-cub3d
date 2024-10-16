/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:04:38 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/16 13:43:20 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

static int	init_draw_wall(t_img *spr, t_ray ray, t_cub cub)
{
	if (ray.d == ray.dy)
	{
		if (ray.vec.dy < 0)
		{
			*spr = cub.spr.n[0];
			return ((ray.pos.x - (int)ray.pos.x) * spr->w);
		}
		*spr = cub.spr.s[0];
		return (spr->w - (ray.pos.x - (int)ray.pos.x) * spr->w);
	}
	if (ray.vec.dx > 0)
	{
		*spr = cub.spr.w[0];
		return ((ray.pos.y - (int)ray.pos.y) * spr->w);
	}
	*spr = cub.spr.e[0];
	return (spr->w - (ray.pos.y - (int)ray.pos.y) * spr->w);
}

void	draw_wall(int frame_x, int wall_h, t_ray ray, t_cub cub)
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
	while (img_h < wall_h && frame_y + img_h < WIN_H)
	{
		*read_img(cub.frame, frame_x, frame_y + img_h)
			= *read_img(spr, img_x, (double)img_h / wall_h * spr.h);
		img_h++;
	}
}
