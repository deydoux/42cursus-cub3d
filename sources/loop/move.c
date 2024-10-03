/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:58:29 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/04 00:05:57 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

static int	move_key(bool pos, bool neg)
{
	if (neg)
		return (-1 * !pos);
	return (pos != 0);
}

static t_pol_vec	move_vec(t_key key, double a)
{
	int			lateral;
	int			vertical;

	lateral = move_key(key.right, key.left);
	vertical = move_key(key.up, key.down);
	if (!vertical)
	{
		if (!lateral)
			return (null_pol_vec());
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
	t_pol_vec	vec;

	vec = move_vec(cub->key, cub->a);
	vec.dx = vec.dx / CUB_SIZE * VELOCITY;
	vec.dy = vec.dy / CUB_SIZE * VELOCITY;
	if (cub->map.buf[(int)cub->y][(int)(cub->x + vec.dx)] != '1')
		cub->x += vec.dx;
	if (cub->map.buf[(int)(cub->y + vec.dy)][(int)cub->x] != '1')
		cub->y += vec.dy;
}
