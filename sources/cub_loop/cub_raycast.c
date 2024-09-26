/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:04:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/09/26 17:39:10 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_loop.h"

double	cub_raycast_dist(t_cub cub)
{
	t_cub_ray	ray;

	ray.x = cub.x;
	ray.y = cub.y;
	while (cub.map.buf[(int)ray.y][(int)ray.x] != '1')
	{
		if (cub.dx < 0)
			ray.dx = (ray.x - (int)ray.x) / (cub.dx * -1);
		else
			ray.dx = ((int)ray.x - ray.x + 1) / cub.dx;
		if (cub.dy < 0)
			ray.dy = (ray.y - (int)ray.y) / (cub.dy * -1);
		else
			ray.dy = ((int)ray.y - ray.y + 1) / cub.dy;
		if (ray.dx < ray.dy)
			ray.a = ray.dx;
		else
			ray.a = ray.dy;
		ray.a += 1e-8;
		ray.x += cub.dx * ray.a;
		ray.y += cub.dy * ray.a;
	}
	cub_draw_line(cub.x * CUB_SIZE / 2, cub.y * CUB_SIZE / 2, ray.x * CUB_SIZE / 2, ray.y * CUB_SIZE / 2, 0xff0000, cub.frame);
	return (sqrt(pow(cub.x - ray.x, 2) + pow(cub.y - ray.y, 2)));
}

void	cub_raycast(t_cub cub)
{
	double	d;
	int		y0;
	int		y1;
	size_t	x;
	double	a;

	a = cub.a;
	cub.a -= (66.0 / 2) * DEG_RAD;
	x = 0;
	while (x < CUB_WIN_W)
	{
		cub.dx = cos(cub.a);
		cub.dy = sin(cub.a);
		d = cub_raycast_dist(cub) * cos(cub.a - a);
		y0 = CUB_WIN_H / 2 - CUB_WIN_H / 2 / d;
		y1 = CUB_WIN_H / 2 + CUB_WIN_H / 2 / d;
		if (y0 < 0)
			y0 = 0;
		if (y1 > CUB_WIN_H)
			y1 = CUB_WIN_H;
		cub_draw_line(x, y0, x, y1, 0xff, cub.frame);
		cub.a += DEG_RAD / (CUB_WIN_W / 66.0);
		x++;
	}
}
