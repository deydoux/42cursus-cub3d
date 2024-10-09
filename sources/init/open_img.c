/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:16:49 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/09 15:13:33 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

bool	open_img(char *path, void *mlx, t_img *img)
{
	int	ign;

	img->ptr = mlx_xpm_file_to_image(mlx, path, &img->w, &img->h);
	if (!img->ptr)
		return (true);
	img->buf = (t_color *)mlx_get_data_addr(img->ptr, &ign, &img->w_size, &ign);
	img->w_size /= 4;
	return (false);
}
