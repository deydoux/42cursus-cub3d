/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:47:29 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/21 17:25:50 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

static bool	valid_pos(t_pos pos, t_img img)
{
	return (0 <= pos.x && pos.x <= img.w && 0 <= pos.y && pos.y <= img.h);
}

void	render_ray(t_ray ray, t_cub cub)
{
	t_color	*color;
	t_pos	pos;

	pos.x = MAP_W / 2 + ray.vec.dx;
	pos.y = MAP_W / 2 + ray.vec.dy;
	color = read_img(cub.minimap, pos.x, pos.y);
	while (valid_pos(pos, cub.minimap) && color->raw != MAP_COLOR_WALL)
	{
		if (color->raw != MAP_COLOR_DOOR)
			color->raw = MAP_COLOR_RAY;
		pos.x += ray.vec.dx;
		pos.y += ray.vec.dy;
		color = read_img(cub.minimap, pos.x, pos.y);
	}
}
