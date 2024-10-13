/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:39:53 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/14 01:21:16 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

int	loop(t_cub *cub)
{
	move(cub);
	fill_img(0, cub->frame);
	raycasts(*cub);
	copy_img(cub->map.img, cub->frame, 0, 0);
	cub->frame.buf[(int)(cub->pos.y * MAP_CUB_SIZE) * cub->frame.w_size
		+ (int)(cub->pos.x * MAP_CUB_SIZE)].raw = 0xffffff;
	mlx_put_image_to_window(cub->mlx, cub->win, cub->frame.ptr, 0, 0);
	return (EXIT_SUCCESS);
	(void)cub;
}
