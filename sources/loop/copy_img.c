/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:55:42 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/09 15:19:38 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	copy_img(t_img src, t_img dst, int x, int y)
{
	const int	min_src_x = x * -1 * (x < 0);
	int			src_x;
	int			src_y;

	src_y = y * -1 * (y < 0);
	while (src_y < src.h && y + src_y < dst.h)
	{
		src_x = min_src_x;
		while (src_x < src.w && x + src_x < dst.w)
		{
			dst.buf[(y + src_y) * dst.w_size + x + src_x]
				= src.buf[src_y * src.w_size + src_x];
			src_x++;
		}
		src_y++;
	}
}
