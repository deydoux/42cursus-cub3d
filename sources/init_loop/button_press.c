/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:49:26 by deydoux           #+#    #+#             */
/*   Updated: 2025/06/03 16:39:41 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_loop.h"

static void	interact(t_cub cub)
{
	char		*c;
	size_t		x;
	size_t		y;
	uint32_t	raw_color;

	x = cub.pos.x + cos(cub.angle) * (1 + VELOCITY * 2);
	y = cub.pos.y + sin(cub.angle) * (1 + VELOCITY * 2);
	if (x >= cub.map.w || y >= cub.map.h)
		return ;
	c = &cub.map.buf[y][x];
	if (*c == 'D')
		*c = ft_tolower(*c);
	else if (*c == 'd')
		*c = ft_toupper(*c);
	else
		return ;
	x *= MAP_CUB_SIZE;
	y *= MAP_CUB_SIZE;
	raw_color = read_img(cub.map.img, x, y)->raw ^ MASK_COLOR_A;
	draw_map_square(x, y, raw_color, cub.map.img);
}

int	button_press(int button, int x, int y, t_cub *cub)
{
	if (button == BUTTON_INTERACT)
		interact(*cub);
	else if (button == BUTTON_ZOOM_IN)
		update_fov(cub->fov.deg - 2, &cub->fov);
	else if (button == BUTTON_ZOOM_OUT)
		update_fov(cub->fov.deg + 2, &cub->fov);
	return (EXIT_SUCCESS);
	(void)x;
	(void)y;
}
