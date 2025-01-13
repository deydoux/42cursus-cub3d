/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:38:18 by deydoux           #+#    #+#             */
/*   Updated: 2025/01/13 14:41:13 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_loop.h"

int	key_release(int key, t_cub *cub)
{
	if (key == cub->key.bind[0])
		cub->key.up = false;
	else if (key == cub->key.bind[1])
		cub->key.left = false;
	else if (key == cub->key.bind[2])
		cub->key.down = false;
	else if (key == cub->key.bind[3])
		cub->key.right = false;
	else if (key == KEY_SPRINT)
		cub->key.sprint = false;
	else if (key == KEY_ROT_LEFT)
		cub->key.rot_left = false;
	else if (key == KEY_ROT_RIGHT)
		cub->key.rot_right = false;
	else if (key == KEY_QUIT)
		quit(cub);
	return (EXIT_SUCCESS);
}
