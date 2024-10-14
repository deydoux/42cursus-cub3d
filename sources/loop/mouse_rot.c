/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 02:31:55 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/14 16:28:55 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	mouse_rot(t_cub *cub)
{
	int			new_x;
	int			y;
	static bool	focus = false;
	static int	x = 0;

	mlx_mouse_get_pos(cub->mlx, cub->win, &new_x, &y);
	if (focus)
		cub->angle -= (x - new_x) * VELOCITY_ROT * MOUSE_SENSIV;
	x = new_x;
	new_x = (new_x - 1) % (WIN_W - 2);
	if (new_x < 0)
		new_x += WIN_W - 2;
	if (focus && x - 1 != new_x)
	{
		x = new_x + 1;
		mlx_mouse_move(cub->mlx, cub->win, x, y);
	}
	focus = cub->focus;
}
