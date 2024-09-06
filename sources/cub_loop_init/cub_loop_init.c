/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_loop_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:54:40 by deydoux           #+#    #+#             */
/*   Updated: 2024/09/07 00:27:59 by deydoux          ###   ########.fr       */
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

static int	cub_key_release(int key, t_cub *cub)
{
	if (key == CUB_KEY_LEFT)
		cub->a += 5 * DEG_RAD;
	else if (key == CUB_KEY_RIGHT)
		cub->a -= 5 * DEG_RAD;
	else if (key == mlx_esc_key)
		cub_quit(cub);
	else
		return (EXIT_FAILURE);
	printf("dir = %f;\ndir_deg = %f;\ndir_x = %f;\ndir_y = %f;\n\n", cub->a,
		cub->a / DEG_RAD, sin(cub->a), cos(cub->a));
	return (EXIT_SUCCESS);
}

void	cub_loop_init(t_cub *cub)
{
	mlx_hook(cub->win, mlx_destroy_notify_event, mlx_structure_notify_mask,
		cub_quit, cub);
	mlx_hook(cub->win, mlx_key_release_event, mlx_key_release_mask,
		cub_key_release, cub);
	mlx_loop_hook(cub->mlx, cub_loop, cub);
	mlx_loop(cub->mlx);
}
