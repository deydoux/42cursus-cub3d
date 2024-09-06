/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:43:04 by deydoux           #+#    #+#             */
/*   Updated: 2024/08/21 16:45:46 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_init.h"

static bool	placeholder_parsing(t_cub *cub)
{
	cub->map = malloc(sizeof(*cub->map) * 6);
	cub->map[0] = ft_strdup("111111\n");
	cub->map[1] = ft_strdup("100101\n");
	cub->map[2] = ft_strdup("101001\n");
	cub->map[3] = ft_strdup("1100N1\n");
	cub->map[4] = ft_strdup("111111\n");
	cub->map[5] = NULL;
	cub->dir = M_PI;
	cub->x = 4;
	cub->y = 3;
	return (false);
}

static bool	cub_mlx_init(void **mlx)
{
	*mlx = mlx_init();
	if (!*mlx)
	{
		ft_putstr_fd(CUB_ERROR CUB_MLX_INIT_ERROR, STDERR_FILENO);
		return (true);
	}
	return (false);
}

static bool	cub_win_init(void *mlx, void **win)
{
	*win = mlx_new_window(mlx, CUB_WINDOW_WIDTH, CUB_WINDOW_HEIGH,
			CUB_PLACEHOLDER "map file");
	if (!*win)
	{
		ft_putstr_fd(CUB_ERROR CUB_WIN_INIT_ERROR, STDERR_FILENO);
		return (true);
	}
	return (false);
}

bool	cub_init(t_cub *cub)
{
	ft_bzero(cub, sizeof(*cub));
	return (placeholder_parsing(cub) || cub_mlx_init(&cub->mlx)
		|| cub_new_img(CUB_WINDOW_HEIGH, CUB_WINDOW_WIDTH, cub->mlx,
			&cub->frame) || cub_win_init(cub->mlx, &cub->win));
}
