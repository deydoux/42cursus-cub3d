/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:04:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/08 01:32:34 by deydoux          ###   ########.fr       */
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

static t_ray	init_ray(t_pol_vec vec, t_cub cub)
{
	t_ray	ray;

	ft_memcpy(&ray.pos, &cub.pos, sizeof(ray.pos));
	if (vec.dx < 0)
	{
		ray.dx_calc = calc_neg;
		ray.fix.x = EPSILON;
	}
	else
	{
		ray.dx_calc = calc_pos;
		ray.fix.x = 0;
	}
	if (vec.dy < 0)
	{
		ray.dy_calc = calc_neg;
		ray.fix.y = EPSILON;
	}
	else
	{
		ray.dy_calc = calc_pos;
		ray.fix.y = 0;
	}
	return (ray);
}

static t_ray	raycast(t_pol_vec vec, t_cub cub)
{
	t_ray	ray;

	ray = init_ray(vec, cub);
	while (cub.map.buf[(int)(ray.pos.y - ray.fix.y)]
		[(int)(ray.pos.x - ray.fix.x)] != '1')
	{
		ray.dx = ray.dx_calc(ray.pos.x, vec.dx);
		ray.dy = ray.dy_calc(ray.pos.y, vec.dy);
		if (ray.dx < ray.dy)
			ray.d = ray.dx;
		else
			ray.d = ray.dy;
		ray.pos.x += vec.dx * ray.d;
		ray.pos.y += vec.dy * ray.d;
	}
	if (ray.dx < ray.dy)
		ray.pos.x = (int)(ray.pos.x + ray.fix.x);
	else
		ray.pos.y = (int)(ray.pos.y + ray.fix.y);
	draw_line(cub.pos.x * CUB_SIZE / 2, cub.pos.y * CUB_SIZE / 2, (ray.pos.x * CUB_SIZE / 2), (ray.pos.y * CUB_SIZE / 2), 0xff0000, cub.frame);
	return (ray);
}

static void	draw_wall(int x, int h, t_ray ray, t_cub cub)
{
	int	i;
	int	w;
	int	y;

	if (ray.pos.x - (int)ray.pos.x > ray.pos.y - (int)ray.pos.y)
		w = (ray.pos.x - (int)ray.pos.x) * cub.wall.w;
	else
		w = (ray.pos.y - (int)ray.pos.y) * cub.wall.w;
	y = (WIN_H - h) / 2;
	i = 0;
	while (i < h)
	{
		cub.frame.buf[x + (i + y) * cub.frame.w_size] = cub.wall.buf[w + (int)((double)i / h * cub.wall.h )* cub.wall.w_size];
		i++;
	}
}

void	raycasts(t_cub cub)
{
	double	a;
	double	d;
	int		h;
	size_t	x;
	t_ray	ray;

	a = cub.a - FOV / 2;
	x = 0;
	while (x < WIN_W)
	{
		ray = raycast(pol_vec(a), cub);
		d = dist(cub.pos, ray.pos) * cos(cub.a - a);
		if (!d)
			h = WIN_H;
		else
			h = WIN_H / d;
		if (h > WIN_H)
			h = WIN_H;
		draw_wall(x, h, ray, cub);
		a += FOV / WIN_W;
		x++;
	}
}
