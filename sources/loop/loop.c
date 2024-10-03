/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:39:53 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/03 14:46:01 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

static bool	rotate(t_cub *cub)
{
	if (cub->key.rot_left)
	{
		if (cub->key.rot_right)
			return (false);
		cub->a -= DEG_RAD;
	}
	else if (cub->key.rot_right)
		cub->a += DEG_RAD;
	else
		return (false);
	cub->dx = cos(cub->a);
	cub->dx_move = cub->dx / CUB_SIZE * 2;
	cub->dy = sin(cub->a);
	cub->dy_move = cub->dy / CUB_SIZE * 2;
	return (true);
}

static void	move(t_cub *cub)
{
	bool	angle_move;

	angle_move = rotate(cub);
	if (cub->key.up)
	{
		if (cub->key.down)
			return ;
		if (cub->map.buf[(int)cub->y][(int)(cub->x + cub->dx_move)] != '1')
			cub->x += cub->dx_move;
		if (cub->map.buf[(int)(cub->y + cub->dy_move)][(int)cub->x] != '1')
			cub->y += cub->dy_move;
	}
	else if (cub->key.down)
	{
		if (cub->map.buf[(int)cub->y][(int)(cub->x - cub->dx_move)] != '1')
			cub->x -= cub->dx_move;
		if (cub->map.buf[(int)(cub->y - cub->dy_move)][(int)cub->x] != '1')
			cub->y -= cub->dy_move;
	}
	else if (!angle_move)
		return ;
	clear_img(cub->frame);
	copy_img(cub->map.img, cub->frame, 0, 0);
	raycast(*cub);
	cub->frame.buf[(int)(cub->y * CUB_SIZE / 2) * cub->frame.w_size + (int)(cub->x * CUB_SIZE / 2)] = 0xffffff;
	mlx_put_image_to_window(cub->mlx, cub->win, cub->frame.ptr, 0, 0);
}

int	loop(t_cub *cub)
{
	move(cub);
	usleep(1000);
	return (EXIT_SUCCESS);
	(void)cub;
}
