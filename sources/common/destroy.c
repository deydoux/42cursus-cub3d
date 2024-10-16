/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:47:56 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/16 12:33:19 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

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

static void	destroy_img(t_img img, t_cub cub)
{
	if (img.ptr)
		mlx_destroy_image(cub.mlx, img.ptr);
}

static void	destroy_spr(t_cub cub)
{
	size_t	i;

	i = 0;
	while (i < MAX_SPR)
	{
		destroy_img(cub.spr.n[i], cub);
		destroy_img(cub.spr.s[i], cub);
		destroy_img(cub.spr.w[i], cub);
		destroy_img(cub.spr.e[i++], cub);
	}
}

void	destroy(t_cub cub)
{
	destroy_map_buf(cub.map.buf);
	if (!cub.mlx)
		return ;
	mlx_loop_end(cub.mlx);
	if (cub.win)
		mlx_destroy_window(cub.mlx, cub.win);
	destroy_img(cub.frame, cub);
	destroy_img(cub.minimap, cub);
	destroy_img(cub.map.img, cub);
	destroy_spr(cub);
	mlx_destroy_display(cub.mlx);
	free(cub.mlx);
}
