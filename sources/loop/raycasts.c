/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:04:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/11 17:03:17 by deydoux          ###   ########.fr       */
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

static t_ray	init_ray(t_vec vec, t_cub cub)
{
	t_ray	ray;

	ray.pos = cub.pos;
	ray.vec = vec;
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

static t_ray	raycast(t_vec vec, t_cub cub)
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
	return (ray);
}

static void	draw_wall(int frame_x, int wall_h, t_ray ray, t_cub cub)
{
	int	frame_y;
	int	img_h;
	int	img_x;

	if (ray.pos.x - (int)ray.pos.x > ray.pos.y - (int)ray.pos.y)
		img_x = (ray.pos.x - (int)ray.pos.x) * cub.wall.w;
	else
		img_x = (ray.pos.y - (int)ray.pos.y) * cub.wall.w;
	frame_y = (WIN_H - wall_h) / 2;
	img_h = 0;
	while (img_h < wall_h)
	{
		cub.frame.buf[frame_x + (frame_y + img_h) * cub.frame.w_size]
			= cub.wall.buf[img_x
			+ (int)((double)img_h / wall_h * cub.wall.h) *cub.wall.w_size];
		img_h++;
	}
}

void	raycasts(t_cub cub)
{
	double	a;
	double	d;
	int		wall_h;
	size_t	x;
	t_ray	ray;

	a = cub.a - FOV / 2;
	x = 0;
	while (x < WIN_W)
	{
		ray = raycast(pol_vec(a), cub);
		ray.vec.len = sqrt(pow(cub.pos.x - ray.pos.x, 2)
			+ pow(cub.pos.y - ray.pos.y, 2));
		d = ray.vec.len * cos(cub.a - a);
		if (!d)
			wall_h = WIN_H;
		else
			wall_h = WIN_H / d;
		if (wall_h > WIN_H)
			wall_h = WIN_H;
		draw_wall(x, wall_h, ray, cub);
		a += FOV / WIN_W;
		x++;
	}
}
