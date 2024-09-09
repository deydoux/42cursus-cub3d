/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:39:53 by deydoux           #+#    #+#             */
/*   Updated: 2024/09/09 13:51:51 by deydoux          ###   ########.fr       */
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
		cub->x += cub->dx_move;
		cub->y += cub->dy_move;
	}
	else if (cub->keys[cub_key_down])
	{
		cub->x -= cub->dx_move;
		cub->y -= cub->dy_move;
	}
	else if (!angle_move)
		return ;
	printf("a %f\nx %f\ny %f\n\n", cub->a, cub->x, cub->y);
	mlx_pixel_put(cub->mlx, cub->win, round(cub->x * CUB_SIZE), round(cub->y * CUB_SIZE), 0xff0000);
}

int	cub_loop(t_cub *cub)
{
	handle_key_press(cub);
	usleep(1000);
	return (EXIT_SUCCESS);
	(void)cub;
}
