/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_img_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:02:11 by deydoux           #+#    #+#             */
/*   Updated: 2024/09/17 12:13:56 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_loop.h"

void	cub_img_clear(t_cub_img img)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = img.h * img.w_size;
	while (i < size)
		img.buf[i++] = 0;
}
