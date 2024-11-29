/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:04:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/11/29 18:30:30 by deydoux          ###   ########.fr       */
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
		ray.fix.x = EPSILON_RAY;
	}
	else
	{
		ray.dx_calc = calc_pos;
		ray.fix.x = 0;
	}
	if (vec.dy < 0)
	{
		ray.dy_calc = calc_neg;
		ray.fix.y = EPSILON_RAY;
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
	while (!ft_strchr(COLLISION, cub.map.buf[(size_t)(ray.pos.y - ray.fix.y)]
		[(size_t)(ray.pos.x - ray.fix.x)]))
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

void	raycasts(t_cub cub)
{
	double	angle;
	double	dist;
	size_t	x;
	t_ray	ray;

	x = 0;
	while (x < WIN_W)
	{
		angle = cub.angle + atan((2.0 * (double)x / (double)WIN_W - 1.0)
				* cub.fov.ray_angle);
		ray = raycast(pol_vec(angle), cub);
		render_ray(ray, cub);
		dist = round(sqrt(pow(cub.pos.x - ray.pos.x, 2)
					+ pow(cub.pos.y - ray.pos.y, 2)) * cos(cub.angle - angle)
				* EPSILON_DIST) / EPSILON_DIST;
		draw_wall(x, WIN_H / dist / cub.fov.draw_wall, ray, cub);
		x++;
	}
}
