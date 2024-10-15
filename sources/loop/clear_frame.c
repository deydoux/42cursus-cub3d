/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:26:53 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/15 14:46:48 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

static void	fill_ceiling(t_cub cub)
{
	const size_t	size = cub.frame.size / 2;
	size_t			i;

	i = 0;
	while (i < size)
		cub.frame.buf[i++] = cub.ceiling;
}

static void	fill_floor(t_cub cub)
{
	size_t	i;

	i = cub.frame.size / 2;
	while (i < cub.frame.size)
		cub.frame.buf[i++] = cub.floor;
}

void	clear_frame(t_cub cub)
{
	fill_ceiling(cub);
	fill_floor(cub);
}
