/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:39:53 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/09 15:16:35 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

int	loop(t_cub *cub)
{
	move(cub);
	fill_img(0, cub->frame);
	copy_img(cub->map.img, cub->frame, 0, 0);
	raycasts(*cub);
	cub->frame.buf[(int)(cub->pos.y * CUB_SIZE / 2) * cub->frame.w_size + (int)(cub->pos.x * CUB_SIZE / 2)].raw = 0xffffff;
	mlx_put_image_to_window(cub->mlx, cub->win, cub->frame.ptr, 0, 0);
	return (EXIT_SUCCESS);
	(void)cub;
}
