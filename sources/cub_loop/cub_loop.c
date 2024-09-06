/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:39:53 by deydoux           #+#    #+#             */
/*   Updated: 2024/09/07 01:09:16 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_loop.h"

static bool	handle_key_press_angle(t_cub *cub)
{
	if (cub->key_press[cub_key_left])
	{
		if (cub->key_press[cub_key_right])
			return (false);
		cub->a -= DEG_RAD;
	}
	else if (cub->key_press[cub_key_right])
		cub->a += DEG_RAD;
	else
		return (false);
	cub->dx = cos(cub->a);
	cub->dy = sin(cub->a);
	return (true);
}

static void	handle_key_press(t_cub *cub)
{
	bool	angle_move;

	angle_move = handle_key_press_angle(cub);
	if (cub->key_press[cub_key_up])
	{
		if (cub->key_press[cub_key_down])
			return ;
		cub->x += cub->dx;
		cub->y += cub->dy;
	}
	else if (cub->key_press[cub_key_down])
	{
		cub->x -= cub->dx;
		cub->y -= cub->dy;
	}
	else if (!angle_move)
		return ;
	printf("a %f\nx %f\ny %f\n\n", cub->a, cub->x, cub->y);
	mlx_pixel_put(cub->mlx, cub->win, round(cub->x), round(cub->y), 0xff0000);
}

int	cub_loop(t_cub *cub)
{
	handle_key_press(cub);
	usleep(1000);
	return (EXIT_SUCCESS);
	(void)cub;
}
