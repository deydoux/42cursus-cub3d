/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:08:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/01 14:36:34 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	draw_line(int x0, int y0, int x1, int y1, int color, t_img img)
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
	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	x_inc = dx / (double)steps;
	y_inc = dy / (double)steps;
	x = x0;
	y = y0;
	for (int i = 0; i <= steps; i++) {
		img.buf[(int)round(y) * img.w_size + (int)round(x)] = color;
		x += x_inc;
		y += y_inc;
	}
}