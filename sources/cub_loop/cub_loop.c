/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:39:53 by deydoux           #+#    #+#             */
/*   Updated: 2024/09/09 23:47:58 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_loop.h"

void cub_draw_line(int x0, int y0, int x1, int y1, t_cub cub)
{
	float	x_inc;
	float	x;
	float	y_inc;
	float	y;
	int		dx;
	int		dy;
	int		steps;

	dx = x1 - x0;
	dy = y1 - y0;
	steps = ft_abs(dx) > ft_abs(dy) ? ft_abs(dx) : ft_abs(dy);
	x_inc = dx / (float)steps;
	y_inc = dy / (float)steps;
	x = x0;
	y = y0;
	for (int i = 0; i <= steps; i++) {
		mlx_pixel_put(cub.mlx, cub.win, x, y, 0xff);
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
	mlx_pixel_put(cub->mlx, cub->win, (int)(cub->x * CUB_SIZE / 2), (int)(cub->y * CUB_SIZE / 2), 0xff0000);
	cub_draw_line(150, 300, (int)(cub->x * CUB_SIZE / 2), (int)(cub->y * CUB_SIZE / 2), *cub);
}

int	cub_loop(t_cub *cub)
{
	handle_key_press(cub);
	usleep(1000);
	return (EXIT_SUCCESS);
	(void)cub;
}
