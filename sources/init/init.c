/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:43:04 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/28 16:03:56 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static bool	init_mlx(void **mlx)
{
	*mlx = mlx_init();
	if (!*mlx)
	{
		ft_putstr_fd(ERR MLX_INIT_ERR, STDERR_FILENO);
		return (true);
	}
	return (false);
}

static bool	init_win(void *mlx, void **win)
{
	*win = mlx_new_window(mlx, WIN_W, WIN_H, "placeholder: map file");
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
	if (init_mlx(&cub->mlx) || use_parse(map_path, cub)
		|| new_img(MAP_H, MAP_W, cub->mlx, &cub->minimap))
		return (true);
	fill_img(MAP_COLOR_WALL, cub->minimap);
	return (new_img(WIN_H, WIN_W, cub->mlx, &cub->frame) || init_map_img(cub)
		|| init_win(cub->mlx, &cub->win));
}
