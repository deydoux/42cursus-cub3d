/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:37:27 by deydoux           #+#    #+#             */
/*   Updated: 2025/01/13 14:36:33 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_loop.h"

int	key_press(int key, t_cub *cub)
{
	if (key == cub->key.bind[0])
		cub->key.up = true;
	else if (key == cub->key.bind[1])
		cub->key.left = true;
	else if (key == cub->key.bind[2])
		cub->key.down = true;
	else if (key == cub->key.bind[3])
		cub->key.right = true;
	else if (key == KEY_SPRINT)
		cub->key.sprint = true;
	else if (key == KEY_ROT_LEFT)
		cub->key.rot_left = true;
	else if (key == KEY_ROT_RIGHT)
		cub->key.rot_right = true;
	return (EXIT_SUCCESS);
}
