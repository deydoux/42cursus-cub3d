/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:39:53 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/16 12:27:20 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

int	loop(t_cub *cub)
{
	mouse_rot(cub);
	move(cub);
	render_minimap(*cub);
	clear_frame(*cub);
	raycasts(*cub);
	copy_minimap(cub->minimap, cub->frame);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->frame.ptr, 0, 0);
	cub->i++;
	return (EXIT_SUCCESS);
}
