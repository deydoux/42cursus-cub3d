/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:54:40 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/15 10:39:17 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_loop.h"

void	init_loop(t_cub *cub)
{
	mlx_hook(cub->win, destroy_notify_event, structure_notify_mask, quit, cub);
	mlx_hook(cub->win, key_press_event, key_press_mask, key_press, cub);
	mlx_hook(cub->win, key_release_event, key_release_mask, key_release, cub);
	mlx_hook(cub->win, focus_in_event, focus_change_mask, focus_in, cub);
	mlx_hook(cub->win, focus_out_event, focus_change_mask, focus_out, cub);
	mlx_loop_hook(cub->mlx, loop, cub);
	if (HIDE_MOUSE)
		mlx_mouse_hide(cub->mlx, cub->win);
	mlx_loop(cub->mlx);
}
