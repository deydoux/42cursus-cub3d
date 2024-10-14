/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:47:56 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/14 18:39:30 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	destroy_imgs(t_cub cub)
{
	const size_t	size = 5;
	const t_img		imgs[] = {cub.frame, cub.ray_map, cub.minimap, cub.wall,
		cub.map.img};
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (imgs[i].ptr)
			mlx_destroy_image(cub.mlx, imgs[i].ptr);
		i++;
	}
}

static void	destroy_map_buf(char **buf)
{
	size_t	i;

	if (!buf)
		return ;
	i = 0;
	while (buf[i])
		free(buf[i++]);
	free(buf);
}

void	destroy(t_cub cub)
{
	destroy_map_buf(cub.map.buf);
	if (!cub.mlx)
		return ;
	mlx_loop_end(cub.mlx);
	if (cub.win)
		mlx_destroy_window(cub.mlx, cub.win);
	destroy_imgs(cub);
	mlx_destroy_display(cub.mlx);
	free(cub.mlx);
}
