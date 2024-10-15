/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:38:18 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/15 10:38:25 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_loop.h"

int	key_release(int key, t_cub *cub)
{
	if (key == KEY_UP)
		cub->key.up = false;
	else if (key == KEY_LEFT)
		cub->key.left = false;
	else if (key == KEY_DOWN)
		cub->key.down = false;
	else if (key == KEY_RIGHT)
		cub->key.right = false;
	else if (key == KEY_ROT_LEFT)
		cub->key.rot_left = false;
	else if (key == KEY_ROT_RIGHT)
		cub->key.rot_right = false;
	else if (key == KEY_QUIT)
		quit(cub);
	return (EXIT_SUCCESS);
}
