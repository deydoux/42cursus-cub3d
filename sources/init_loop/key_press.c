/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:37:27 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/21 17:41:47 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_loop.h"

static void	interact(t_cub cub)
{
	char	*c;

	c = &cub.map.buf[(size_t)(cub.pos.y + sin(cub.angle))]
		[(size_t)(cub.pos.x + cos(cub.angle))];
	if (ft_isupper(*c))
		*c = ft_tolower(*c);
	else
		*c = ft_toupper(*c);
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
