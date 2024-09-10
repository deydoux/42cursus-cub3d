/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:39:53 by deydoux           #+#    #+#             */
/*   Updated: 2024/09/10 19:19:36 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_loop.h"

void cub_draw_line(int x0, int y0, int x1, int y1, int color, t_cub cub)
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

static bool	handle_key_press_angle(t_cub *cub)
{
	if (cub->keys[cub_key_left])
	{
		if (cub->keys[cub_key_right])
			return (true);
		cub->a -= DEG_RAD;
	}
	else if (cub->keys[cub_key_right])
		cub->a += DEG_RAD;
	else
		return (true);
	cub->dx = cos(cub->a);
	cub->dx_move = cub->dx / CUB_SIZE;
	cub->dy = sin(cub->a);
	cub->dy_move = cub->dy / CUB_SIZE;
	return (false);
}

static void	raycast_ph(t_cub cub)
{
	double	rd;
	double	rx;
	double	ry;
	double	rdx;
	double	rdy;

	rx = cub.x;
	ry = cub.y;
	while (cub.map.buf[(int)ry][(int)rx] != '1')
	{
		if (cub.dx > 0)
			rdx = ((int)rx + 1 - rx) / cub.dx;
		else if (!cub.dx)
			rdx = 2;
		else
			rdx = (rx - (int)rx) / (cub.dx * -1);
		if (cub.dy > 0)
			rdy = ((int)ry + 1 - ry) / cub.dy;
		else if (!cub.dy)
			rdy = 2;
		else
			rdy = (ry - (int)ry) / (cub.dy * -1);
		if (rdx < rdy)
			rd = rdx;
		else
			rd = rdy;
		rx += cub.dx * rd - (1. / CUB_SIZE) * (cub.dx < 0);
		ry += cub.dy * rd - (1. / CUB_SIZE) * (cub.dy < 0);
	}
	cub_draw_line(
		cub.x * CUB_SIZE / 2,
		cub.y * CUB_SIZE / 2,
		rx * CUB_SIZE / 2,
		ry * CUB_SIZE / 2,
		0xff0000, cub);
}

static void	handle_key_press(t_cub *cub)
{
	bool	angle_move;

	angle_move = handle_key_press_angle(cub);
	if (cub->keys[cub_key_up])
	{
		if (cub->keys[cub_key_down])
			return ;
		if (cub->map.buf[(int)cub->y][(int)(cub->x + cub->dx_move)] != '1')
			cub->x += cub->dx_move;
		if (cub->map.buf[(int)(cub->y + cub->dy_move)][(int)cub->x] != '1')
			cub->y += cub->dy_move;
	}
	else if (cub->keys[cub_key_down])
	{
		if (cub->map.buf[(int)cub->y][(int)(cub->x - cub->dx_move)] != '1')
			cub->x -= cub->dx_move;
		if (cub->map.buf[(int)(cub->y - cub->dy_move)][(int)cub->x] != '1')
			cub->y -= cub->dy_move;
	}
	else if (angle_move)
		return ;
	mlx_put_image_to_window(cub->mlx, cub->win, cub->map.img.ptr, 0, 0);
	raycast_ph(*cub);
	mlx_pixel_put(cub->mlx, cub->win, (int)(cub->x * CUB_SIZE / 2), (int)(cub->y * CUB_SIZE / 2), 0xffffff);
}

int	cub_loop(t_cub *cub)
{
	handle_key_press(cub);
	usleep(1000);
	return (EXIT_SUCCESS);
	(void)cub;
}
