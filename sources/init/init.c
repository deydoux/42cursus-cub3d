/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:43:04 by deydoux           #+#    #+#             */
/*   Updated: 2025/01/10 18:52:21 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static bool	init_win(void *mlx, void **win)
{
	*win = mlx_new_window(mlx, WIN_W, WIN_H, "cub3D");
	if (!*win)
	{
		ft_putstr_fd(ERR WIN_INIT_ERR, STDERR_FILENO);
		return (true);
	}
	return (false);
}

bool	init(char *map_path, t_cub *cub)
{
	ft_bzero(cub, sizeof(*cub));
	update_fov(FOV_DEFAULT, &cub->fov);
	if (use_parse(map_path, cub)
		|| new_img(MAP_H, MAP_W, cub->mlx, &cub->minimap))
		return (true);
	fill_img(MAP_COLOR_WALL, cub->minimap);
	return (new_img(WIN_H, WIN_W, cub->mlx, &cub->frame) || init_map_img(cub)
		|| init_win(cub->mlx, &cub->win));
}
