/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:39:53 by deydoux           #+#    #+#             */
/*   Updated: 2024/09/09 14:34:55 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_loop.h"

static bool	handle_key_press_angle(t_cub *cub)
{
	if (cub->keys[cub_key_left])
	{
		if (cub->keys[cub_key_right])
			return (false);
		cub->a -= DEG_RAD;
	}
	else if (cub->keys[cub_key_right])
		cub->a += DEG_RAD;
	else
		return (false);
	cub->dx = cos(cub->a);
	cub->dx_move = cub->dx / CUB_SIZE;
	cub->dy = sin(cub->a);
	cub->dy_move = cub->dy / CUB_SIZE;
	return (true);
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
	else if (!angle_move)
		return ;
	mlx_put_image_to_window(cub->mlx, cub->win, cub->map.img.ptr, 0, 0);
	mlx_pixel_put(cub->mlx, cub->win, (int)(cub->x * CUB_SIZE), (int)(cub->y * CUB_SIZE), 0xff0000);
}

int	cub_loop(t_cub *cub)
{
	handle_key_press(cub);
	usleep(1000);
	return (EXIT_SUCCESS);
	(void)cub;
}
