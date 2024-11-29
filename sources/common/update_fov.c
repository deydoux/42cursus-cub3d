/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_fov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:22:13 by deydoux           #+#    #+#             */
/*   Updated: 2024/11/29 18:31:35 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static double	to_rad(double deg)
{
	return (deg * (M_PI / 180));
}

static double	calc_ray_angle(double rad)
{
	return (tan(rad / 2));
}

static double	calc_draw_wall(double rad)
{
	return (rad / M_PI_2);
}

void	update_fov(int deg, t_fov *fov)
{
	double	rad;

	if (FOV_MIN > deg || deg > FOV_MAX)
		return ;
	rad = to_rad(deg);
	fov->ray_angle = calc_ray_angle(rad);
	fov->draw_wall = calc_draw_wall(rad);
	fov->deg = deg;
}
