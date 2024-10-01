/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:54:40 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/01 14:30:49 by deydoux          ###   ########.fr       */
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

static int	handle_key_press(int key, t_cub *cub)
{
	size_t	i;

	i = 0;
	while (i < CUB_KEY_N)
	{
		if (key == CUB_KEY_BIND[i])
		{
			cub->keys[i] = true;
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_FAILURE);
}

static int	handle_key_release(int key, t_cub *cub)
{
	size_t	i;

	if (key == key_esc)
		quit(cub);
	i = 0;
	while (i < CUB_KEY_N)
	{
		if (key == CUB_KEY_BIND[i])
		{
			cub->keys[i] = false;
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_FAILURE);
}

void	init_loop(t_cub *cub)
{
	mlx_hook(cub->win, destroy_notify_event, structure_notify_mask, quit, cub);
	mlx_hook(cub->win, key_press_event, key_press_mask, handle_key_press, cub);
	mlx_hook(cub->win, key_release_event, key_release_mask, handle_key_release,
		cub);
	mlx_loop_hook(cub->mlx, loop, cub);
	mlx_loop(cub->mlx);
}
