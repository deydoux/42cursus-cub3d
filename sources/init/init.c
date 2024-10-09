/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:43:04 by deydoux           #+#    #+#             */
/*   Updated: 2024/10/09 15:21:09 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

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
	cub->pos.x = 26.5;
	cub->pos.y = 11.5;
	return (false);
}

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

bool	init(t_cub *cub)
{
	ft_bzero(cub, sizeof(*cub));
	return (placeholder_parsing(cub) || init_mlx(&cub->mlx)
		|| new_img(WIN_H, WIN_W, cub->mlx, &cub->frame)
		|| open_img("wall.xpm", cub->mlx, &cub->wall)
		|| init_map_img(cub) || init_win(cub->mlx, &cub->win));
}
