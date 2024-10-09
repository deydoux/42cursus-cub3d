/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:02:11 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/09 15:13:41 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	clear_img(t_img img)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = img.h * img.w_size;
	while (i < size)
		img.buf[i++].raw = 0;
}
