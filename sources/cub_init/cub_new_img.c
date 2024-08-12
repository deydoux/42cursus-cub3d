/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_new_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:58:12 by deydoux           #+#    #+#             */
/*   Updated: 2024/08/12 17:55:09 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_init.h"

bool	cub_new_img(int height, int width, void *mlx, t_img *img)
{
	int	ign;

	if (height > CUB_MAX_IMG_DIMENSION || width > CUB_MAX_IMG_DIMENSION
		|| height * width > CUB_MAX_IMG_PIXEL)
	{
		img->ptr = NULL;
		return (true);
	}
	img->height = height;
	img->width = width;
	img->ptr = mlx_new_image(mlx, width, height);
	if (!img->ptr)
		return (true);
	img->buffer = (uint32_t *)mlx_get_data_addr(img->ptr, &ign, &img->size_line,
		&ign);
	return (false);
}
