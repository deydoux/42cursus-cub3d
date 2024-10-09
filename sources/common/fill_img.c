/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:47:36 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/09 14:54:28 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	fill_img(uint32_t raw_color, t_img img)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = img.h * img.w_size;
	while (i < size)
		img.buf[i++].raw = raw_color;
}
