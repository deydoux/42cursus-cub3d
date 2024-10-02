/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:58:12 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/02 15:22:21 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

bool	new_img(int height, int width, void *mlx, t_img *img)
{
	int	ign[1];

	if (height > MAX_IMG_DIM || width > MAX_IMG_DIM
		|| height * width > MAX_IMG_PIXEL)
	{
		img->ptr = NULL;
		return (true);
	}
	img->h = height;
	img->w = width;
	img->ptr = mlx_new_image(mlx, width, height);
	if (!img->ptr)
		return (true);
	img->buf = (uint32_t *)mlx_get_data_addr(img->ptr, ign, &img->w_size, ign);
	img->w_size /= 4;
	return (false);
}
