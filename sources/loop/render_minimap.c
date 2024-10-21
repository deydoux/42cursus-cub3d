/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:57:37 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/21 12:51:09 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

static void	draw_minimap_point(t_img minimap)
{
	t_color	*pixel;

	pixel = read_img(minimap, MAP_W / 2, MAP_H / 2);
	pixel->raw = MAP_COLOR_RAY;
	pixel -= 1;
	pixel->raw = MAP_COLOR_RAY;
	pixel -= minimap.w_size;
	pixel->raw = MAP_COLOR_RAY;
	pixel += 1;
	pixel->raw = MAP_COLOR_RAY;
}

void	render_minimap(t_cub cub)
{
	copy_img(cub.map.img, cub.minimap, -cub.pos.x * MAP_CUB_SIZE + MAP_W / 2,
		-cub.pos.y * MAP_CUB_SIZE + MAP_H / 2);
	draw_minimap_point(cub.minimap);
}
