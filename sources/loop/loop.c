/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:39:53 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/03 18:15:20 by deydoux          ###   ########.fr       */
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
	cub->dy = sin(cub->a);
	return (true);
}

int	loop(t_cub *cub)
{
	rotate(cub);
	move(cub);
	clear_img(cub->frame);
	copy_img(cub->map.img, cub->frame, 0, 0);
	raycast(*cub);
	cub->frame.buf[(int)(cub->y * CUB_SIZE / 2) * cub->frame.w_size + (int)(cub->x * CUB_SIZE / 2)] = 0xffffff;
	mlx_put_image_to_window(cub->mlx, cub->win, cub->frame.ptr, 0, 0);
	return (EXIT_SUCCESS);
	(void)cub;
}
