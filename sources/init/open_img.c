/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:16:49 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/28 15:22:56 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

bool	open_img(char *path, void *mlx, t_img *img)
{
	img->ptr = mlx_xpm_file_to_image(mlx, path, &img->w, &img->h);
	if (!img->ptr)
	{
		ft_dprintf(STDERR_FILENO, ERR OPEN_IMG_ERR, path);
		return (true);
	}
	init_img(img);
	return (false);
}
