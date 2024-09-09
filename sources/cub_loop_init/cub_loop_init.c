/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loop_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:54:40 by deydoux           #+#    #+#             */
/*   Updated: 2024/09/09 22:47:24 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_loop_init.h"

static int	cub_quit(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_loop_end(cub->mlx);
	cub_destroy(*cub);
	exit(EXIT_SUCCESS);
}

static int	cub_key_press(int key, t_cub *cub)
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

static int	cub_key_release(int key, t_cub *cub)
{
	size_t	i;

	if (key == mlx_key_esc)
		cub_quit(cub);
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

void	cub_loop_init(t_cub *cub)
{
	mlx_hook(cub->win, mlx_destroy_notify_event, mlx_structure_notify_mask,
		cub_quit, cub);
	mlx_hook(cub->win, mlx_key_press_event, mlx_key_press_mask, cub_key_press,
		cub);
	mlx_hook(cub->win, mlx_key_release_event, mlx_key_release_mask,
		cub_key_release, cub);
	mlx_loop_hook(cub->mlx, cub_loop, cub);
	mlx_loop(cub->mlx);
}
