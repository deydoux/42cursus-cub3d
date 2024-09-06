/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:43:04 by deydoux           #+#    #+#             */
/*   Updated: 2024/09/07 00:27:32 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_init.h"

static bool	placeholder_parsing(t_cub *cub)
{
	cub->map.buf = malloc(sizeof(*cub->map.buf) * 6);
	cub->map.buf[0] = ft_strdup("111111\n");
	cub->map.buf[1] = ft_strdup("100001\n");
	cub->map.buf[2] = ft_strdup("101001\n");
	cub->map.buf[3] = ft_strdup("1010N1\n");
	cub->map.buf[4] = ft_strdup("111111\n");
	cub->map.buf[5] = NULL;
	cub->map.h = 5;
	cub->map.w= 6;
	cub->a = -M_PI_2;
	cub->x = 4;
	cub->y = 3;
	return (false);
}

static bool	cub_mlx_init(void **mlx)
{
	*mlx = mlx_init();
	if (!*mlx)
	{
		ft_putstr_fd(CUB_ERR CUB_MLX_INIT_ERR, STDERR_FILENO);
		return (true);
	}
	return (false);
}

static bool	cub_win_init(void *mlx, void **win)
{
	*win = mlx_new_window(mlx, CUB_WIN_W, CUB_WIN_H, CUB_PH "map file");
	if (!*win)
	{
		ft_putstr_fd(CUB_ERR CUB_WIN_INIT_ERR, STDERR_FILENO);
		return (true);
	}
	return (false);
}

bool	cub_init(t_cub *cub)
{
	ft_bzero(cub, sizeof(*cub));
	return (placeholder_parsing(cub) || cub_mlx_init(&cub->mlx)
		|| cub_new_img(CUB_WIN_H, CUB_WIN_W, cub->mlx, &cub->frame)
		|| cub_win_init(cub->mlx, &cub->win));
}
