/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:26:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/21 18:27:05 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	draw_map_square(size_t x, size_t y, uint32_t raw_color, t_img img)
{
	size_t	sq_x;
	size_t	sq_y;

	sq_y = 0;
	while (sq_y < MAP_CUB_SIZE)
	{
		sq_x = 0;
		while (sq_x < MAP_CUB_SIZE)
			read_img(img, x + sq_x++, y + sq_y)->raw = raw_color;
		sq_y++;
	}
}
