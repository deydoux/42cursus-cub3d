/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:57:37 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/15 10:28:18 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	render_minimap(t_cub cub)
{
	copy_img(cub.map.img, cub.minimap, -cub.pos.x * MAP_CUB_SIZE + MAP_W / 2,
		-cub.pos.y * MAP_CUB_SIZE + MAP_H / 2);
	copy_minimap(cub.minimap, cub.frame);
}
