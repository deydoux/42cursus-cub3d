/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:37:27 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/30 12:14:07 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_loop.h"

static void	interact(t_cub cub)
{
	char		*c;
	size_t		x;
	size_t		y;
	uint32_t	raw_color;

	x = cub.pos.x + cos(cub.angle);
	y = cub.pos.y + sin(cub.angle);
	c = &cub.map.buf[y][x];
	if (*c == 'D')
		*c = ft_tolower(*c);
	else if (*c != 'd')
		*c = ft_toupper(*c);
	else
		return ;
	x *= MAP_CUB_SIZE;
	y *= MAP_CUB_SIZE;
	raw_color = read_img(cub.map.img, x, y)->raw ^ MASK_COLOR_A;
	draw_map_square(x, y, raw_color, cub.map.img);
}

int	key_press(int key, t_cub *cub)
{
	if (key == KEY_UP)
		cub->key.up = true;
	else if (key == KEY_LEFT)
		cub->key.left = true;
	else if (key == KEY_DOWN)
		cub->key.down = true;
	else if (key == KEY_RIGHT)
		cub->key.right = true;
	else if (key == KEY_SPRINT)
		cub->key.sprint = true;
	else if (key == KEY_ROT_LEFT)
		cub->key.rot_left = true;
	else if (key == KEY_ROT_RIGHT)
		cub->key.rot_right = true;
	else if (key == KEY_INTERACT)
		interact(*cub);
	return (EXIT_SUCCESS);
}
