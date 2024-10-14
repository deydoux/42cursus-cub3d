/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 02:31:55 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/14 14:07:11 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	mouse_rot(t_cub *cub)
{
	int			x;
	int			y;
	static bool	focus = false;

	if (focus)
	{
		mlx_mouse_get_pos(cub->mlx, cub->win, &x, &y);
		cub->angle -= (WIN_W / 2 - x) * VELOCITY_ROT / 2;
	}
	if (cub->focus)
		mlx_mouse_move(cub->mlx, cub->win, WIN_W / 2, WIN_H / 2);
	focus = cub->focus;
}
