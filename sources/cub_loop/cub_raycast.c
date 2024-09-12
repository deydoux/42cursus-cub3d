/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:04:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/09/12 13:51:17 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_loop.h"

void	cub_raycast(t_cub cub)
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
		ray.x += cub.dx * ray.a - CUB_1_SIZE * (cub.dx < 0);
		ray.y += cub.dy * ray.a - CUB_1_SIZE * (cub.dy < 0);
	}
	cub_draw_line(cub.x * CUB_SIZE / 2, cub.y * CUB_SIZE / 2, ray.x * CUB_SIZE / 2, ray.y * CUB_SIZE / 2, 0xff0000, cub.frame);
}
