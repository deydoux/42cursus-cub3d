/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:43:04 by deydoux           #+#    #+#             */
/*   Updated: 2024/09/09 15:24:22 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_init.h"

static bool	placeholder_parsing(t_cub *cub)
{
	cub->map.buf = malloc(sizeof(*cub->map.buf) * 15);
	cub->map.buf[0] = ft_strdup("000000001111111111111111111111111\n");
	cub->map.buf[1] = ft_strdup("000000001000000000110000000000001\n");
	cub->map.buf[2] = ft_strdup("000000001011000001110000000000001\n");
	cub->map.buf[3] = ft_strdup("000000001001000000000000000000001\n");
	cub->map.buf[4] = ft_strdup("111111111011000001110000000000001\n");
	cub->map.buf[5] = ft_strdup("100000000011000001110111110111111\n");
	cub->map.buf[6] = ft_strdup("111101111111110111000000100010000\n");
	cub->map.buf[7] = ft_strdup("111101111111110111010100100010000\n");
	cub->map.buf[8] = ft_strdup("110000001101010111000000100010000\n");
	cub->map.buf[9] = ft_strdup("100000000000000011000000100010000\n");
	cub->map.buf[10] = ft_strdup("10000000000000001101010010001000\n");
	cub->map.buf[11] = ft_strdup("11000001110101011111011110N01110\n");
	cub->map.buf[12] = ft_strdup("11110111011101010101111010001000\n");
	cub->map.buf[13] = ft_strdup("11111111011111110111111111111000\n");
	cub->map.buf[14] = NULL;
	cub->map.h = 14;
	cub->map.w = 33;
	cub->a = -M_PI_2;
	cub->dy = -1;
	cub->dy_move = cub->dy / CUB_SIZE;
	cub->x = 26.5;
	cub->y = 11.5;
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
		|| cub_map_img_init(cub) || cub_win_init(cub->mlx, &cub->win));
}
