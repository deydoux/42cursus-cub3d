/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:04:38 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/15 12:41:28 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	draw_wall(int frame_x, int wall_h, t_ray ray, t_cub cub)
{
	int	frame_y;
	int	img_h;
	int	img_x;

	if (wall_h < 0)
		wall_h = INT_MAX;
	if (ray.pos.x - (int)ray.pos.x > ray.pos.y - (int)ray.pos.y)
		img_x = (ray.pos.x - (int)ray.pos.x) * cub.wall.w;
	else
		img_x = (ray.pos.y - (int)ray.pos.y) * cub.wall.w;
	frame_y = (WIN_H - wall_h) / 2;
	img_h = frame_y * -1 * (frame_y < 0);
	while (img_h < wall_h && frame_y + img_h < WIN_H)
	{
		*read_img(cub.frame, frame_x, frame_y + img_h)
			= *read_img(cub.wall, img_x, (double)img_h / wall_h * cub.wall.h);
		img_h++;
	}
}
