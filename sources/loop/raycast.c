/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:04:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/07 01:38:10 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

double	cub_raycast_dist(t_pol_vec vec, t_cub cub)
{
	t_ray	ray;

	ft_memcpy(&ray.pos, &cub.pos, sizeof(ray.pos));
	while (cub.map.buf[(int)ray.pos.y][(int)ray.pos.x] != '1')
	{
		if (vec.dx < 0)
			ray.dx = (ray.pos.x - (int)ray.pos.x) / (vec.dx * -1);
		else
			ray.dx = ((int)ray.pos.x - ray.pos.x + 1) / vec.dx;
		if (vec.dy < 0)
			ray.dy = (ray.pos.y - (int)ray.pos.y) / (vec.dy * -1);
		else
			ray.dy = ((int)ray.pos.y - ray.pos.y + 1) / vec.dy;
		if (ray.dx < ray.dy)
			ray.a = ray.dx;
		else
			ray.a = ray.dy;
		ray.a += 1e-8;
		ray.pos.x += vec.dx * ray.a;
		ray.pos.y += vec.dy * ray.a;
	}
	draw_line(cub.pos.x * CUB_SIZE / 2, cub.pos.y * CUB_SIZE / 2, (ray.pos.x * CUB_SIZE / 2), (ray.pos.y * CUB_SIZE / 2), 0xff0000, cub.frame);
	return (sqrt(pow(cub.pos.x - ray.pos.x, 2) + pow(cub.pos.y - ray.pos.y, 2)));
}

void	raycast(t_cub cub)
{
	double	d;
	int		y0;
	int		y1;
	size_t	x;
	double	a;

	a = cub.a - FOV / 2;
	x = 0;
	while (x < WIN_W)
	{
		d = cub_raycast_dist(pol_vec(a), cub) * cos(cub.a - a);
		y0 = WIN_H / 2 - WIN_H / 2 / d;
		y1 = WIN_H / 2 + WIN_H / 2 / d;
		if (y0 < 0)
			y0 = 0;
		if (y1 > WIN_H)
			y1 = WIN_H;
		draw_line(x, y0, x, y1, 0xff, cub.frame);
		a += FOV / WIN_W;
		x++;
	}
}
