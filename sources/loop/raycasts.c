/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:04:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/07 15:58:48 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

static double	calc_pos(double pos, double d)
{
	return (((int)pos - pos + 1) / d);
}

static double	calc_neg(double pos, double d)
{
	pos -= (int)pos;
	if (!pos)
		pos = 1;
	return (pos / d * -1);
}

static double	dist(t_pos pos0, t_pos pos1)
{
	return (sqrt(pow(pos0.x - pos1.x, 2) + pow(pos0.y - pos1.y, 2)));
}

static double	raycast(t_pol_vec vec, t_cub cub)
{
	t_ray	ray;

	ft_memcpy(&ray.pos, &cub.pos, sizeof(ray.pos));
	if (vec.dx < 0)
		ray.dx_calc = calc_neg;
	else
		ray.dx_calc = calc_pos;
	if (vec.dy < 0)
		ray.dy_calc = calc_neg;
	else
		ray.dy_calc = calc_pos;
	while (cub.map.buf[(int)ray.pos.y][(int)ray.pos.x] != '1')
	{
		ray.dx = ray.dx_calc(ray.pos.x, vec.dx);
		ray.dy = ray.dy_calc(ray.pos.y, vec.dy);
		if (ray.dx < ray.dy)
			ray.d = ray.dx;
		else
			ray.d = ray.dy;
		ray.d += 1e-8;
		ray.pos.x += vec.dx * ray.d;
		ray.pos.y += vec.dy * ray.d;
	}
	draw_line(cub.pos.x * CUB_SIZE / 2, cub.pos.y * CUB_SIZE / 2, (ray.pos.x * CUB_SIZE / 2), (ray.pos.y * CUB_SIZE / 2), 0xff0000, cub.frame);
	return (dist(cub.pos, ray.pos));
}

void	raycasts(t_cub cub)
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
		d = raycast(pol_vec(a), cub) * cos(cub.a - a);
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
