/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:58:29 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/15 13:02:55 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

static int	move_key(bool pos, bool neg)
{
	if (neg)
		return (-1 * !pos);
	return (pos != 0);
}

static t_vec	move_vec(t_key key, double a)
{
	int	lateral;
	int	vertical;

	lateral = move_key(key.right, key.left);
	vertical = move_key(key.up, key.down);
	if (!vertical)
	{
		if (!lateral)
			return ((t_vec){.dx = 0, .dy = 0});
		lateral *= 2;
	}
	else if (vertical == -1)
	{
		lateral *= -1;
		a -= M_PI;
	}
	return (pol_vec(a + M_PI_4 * lateral));
}

void	move(t_cub *cub)
{
	t_vec	vec;

	cub->angle += move_key(cub->key.rot_right, cub->key.rot_left)
		* VELOCITY_ROT;
	vec = move_vec(cub->key, cub->angle);
	vec.dx *= VELOCITY;
	vec.dy *= VELOCITY;
	if (cub->map.buf[(int)cub->pos.y][(int)(cub->pos.x + vec.dx * 2)] != '1')
		cub->pos.x += vec.dx;
	if (cub->map.buf[(int)(cub->pos.y + vec.dy * 2)][(int)cub->pos.x] != '1')
		cub->pos.y += vec.dy;
}
