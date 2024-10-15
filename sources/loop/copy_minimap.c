/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:27:49 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/15 10:27:59 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

static void	blend_map_colors(t_color src, t_color *dst)
{
	dst->r = dst->r * (1 - MAP_A) + src.r * MAP_A;
	dst->g = dst->g * (1 - MAP_A) + src.g * MAP_A;
	dst->b = dst->b * (1 - MAP_A) + src.b * MAP_A;
}

void	copy_minimap(t_img src, t_img dst)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < MAP_H)
	{
		x = 0;
		while (x < MAP_W)
		{
			blend_map_colors(src.buf[y * src.w_size + x],
				&dst.buf[y * dst.w_size + x]);
			x++;
		}
		y++;
	}
}
