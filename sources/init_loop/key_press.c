/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:37:27 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/16 15:30:23 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_loop.h"

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
	return (EXIT_SUCCESS);
}
