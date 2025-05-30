/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:58:12 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/28 16:42:24 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

bool	new_img(int height, int width, void *mlx, t_img *img)
{
	if (height > MAX_IMG_DIM || width > MAX_IMG_DIM
		|| height * width > MAX_IMG_PIXEL)
	{
		img->ptr = NULL;
		ft_putstr_fd(ERR NEW_IMG_ERR, STDERR_FILENO);
		return (true);
	}
	img->h = height;
	img->w = width;
	img->ptr = mlx_new_image(mlx, width, height);
	if (!img->ptr)
	{
		ft_putstr_fd(ERR NEW_IMG_ERR, STDERR_FILENO);
		return (true);
	}
	init_img(img);
	return (false);
}
