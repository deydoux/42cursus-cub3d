/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:40:50 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/09 16:45:16 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

bool	init_img(t_img *img)
{
	int	ign;

	if (!img->ptr)
		return (true);
	img->buf = (t_color *)mlx_get_data_addr(img->ptr, &ign, &img->w_size, &ign);
	img->w_size /= 4;
	img->size = img->h * img->w_size;
	return (false);
}
