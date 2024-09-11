/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:08:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/09/11 17:10:59 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_loop.h"

void	cub_draw_line(int x0, int y0, int x1, int y1, int color, t_cub cub)
{
	double	x_inc;
	double	x;
	double	y_inc;
	double	y;
	int		dx;
	int		dy;
	int		steps;

	dx = x1 - x0;
	dy = y1 - y0;
	steps = ft_abs(dx) > ft_abs(dy) ? ft_abs(dx) : ft_abs(dy);
	x_inc = dx / (double)steps;
	y_inc = dy / (double)steps;
	x = x0;
	y = y0;
	for (int i = 0; i <= steps; i++) {
		mlx_pixel_put(cub.mlx, cub.win, x, y, color);
		x += x_inc;
		y += y_inc;
	}
}
