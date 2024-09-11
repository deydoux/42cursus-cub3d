/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:04:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/09/11 17:39:33 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_loop.h"

static double	calc_ray_dxy_neg(double xy, double dxy)
{
	return ((xy - (int)xy) / (dxy * -1));
}

static double	calc_ray_dxy_pos(double xy, double dxy)
{
	return (((int)xy - xy + 1) / dxy);
}

static double	calc_ray_dxy_nul(double xy, double dxy)
{
	(void)xy;
	(void)dxy;
	return (2);
}

void	cub_raycast(t_cub cub)
{
	t_calc_ray_dxy	calc_ray_dx;
	t_calc_ray_dxy	calc_ray_dy;
	t_cub_ray		ray;

	if (cub.dx < 0)
		calc_ray_dx = calc_ray_dxy_neg;
	else if (cub.dx)
		calc_ray_dx = calc_ray_dxy_pos;
	else
		calc_ray_dx = calc_ray_dxy_nul;
	if (cub.dy < 0)
		calc_ray_dy = calc_ray_dxy_neg;
	else if (cub.dy)
		calc_ray_dy = calc_ray_dxy_pos;
	else
		calc_ray_dy = calc_ray_dxy_nul;
	ray.x = cub.x;
	ray.y = cub.y;
	while (cub.map.buf[(int)ray.y][(int)ray.x] != '1')
	{
		ray.dx = calc_ray_dx(ray.x, cub.dx);
		ray.dy = calc_ray_dy(ray.y, cub.dy);
		if (ray.dx < ray.dy)
			ray.a = ray.dx;
		else
			ray.a = ray.dy;
		ray.x += cub.dx * ray.a - CUB_1_SIZE * (cub.dx < 0);
		ray.y += cub.dy * ray.a - CUB_1_SIZE * (cub.dy < 0);
	}
	cub_draw_line(cub.x * CUB_SIZE / 2, cub.y * CUB_SIZE / 2, ray.x * CUB_SIZE / 2, ray.y * CUB_SIZE / 2, 0xff0000, cub);
}
