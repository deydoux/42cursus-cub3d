/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:54:40 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/14 02:37:49 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_loop.h"

static int	quit(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_loop_end(cub->mlx);
	destroy(*cub);
	exit(EXIT_SUCCESS);
}

static int	key_press(int key, t_cub *cub)
{
	if (key == KEY_UP)
		cub->key.up = true;
	else if (key == KEY_LEFT)
		cub->key.left = true;
	else if (key == KEY_DOWN)
		cub->key.down = true;
	else if (key == KEY_RIGHT)
		cub->key.right = true;
	else if (key == KEY_ROT_LEFT)
		cub->key.rot_left = true;
	else if (key == KEY_ROT_RIGHT)
		cub->key.rot_right = true;
	return (EXIT_SUCCESS);
}

static int	key_release(int key, t_cub *cub)
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

void	init_loop(t_cub *cub)
{
	mlx_hook(cub->win, destroy_notify_event, structure_notify_mask, quit, cub);
	mlx_hook(cub->win, key_press_event, key_press_mask, key_press, cub);
	mlx_hook(cub->win, key_release_event, key_release_mask, key_release, cub);
	mlx_loop_hook(cub->mlx, loop, cub);
	mlx_mouse_hide(cub->mlx, cub->win);
	mlx_loop(cub->mlx);
}
