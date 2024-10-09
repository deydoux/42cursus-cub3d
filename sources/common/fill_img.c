/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:47:36 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/09 18:03:03 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	fill_img(uint32_t raw_color, t_img img)
{
	size_t	i;

	i = 0;
	while (i < img.size)
		img.buf[i++].raw = raw_color;
}
